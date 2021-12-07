#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>

#include "btree_vehicle.h"

struct node {
  int key_value; // year of vehicle
  vehicle_t data; 
  node *left;
  node *right;
};

class btree {
    public:
        btree();

        void insertVehicle(vehicle_t car); 
        vehicle_t *getVehicle(int key);
        void listVehicles(); 
 
    private:
        void nextVehicleNode(vehicle_t car, node *leaf);
        vehicle_t *getVehicleNode(int key, node *leaf); 
        void listVehicles(node *leaf); 
         
        node *root;
};

btree::btree() {
  root=NULL;
}

void btree::listVehicles() {
  if (root == NULL) {
    cout << "List is empty" << endl; 
    return;
  }
  // Pass in root node 
  listVehicles(root);
}

void btree::listVehicles(node *leaf) {
  if (leaf == NULL) {
    return; 
  }
  
  // Recursive call on the left side first
  listVehicles(leaf->left); 
  // Once returned, we print each vehicle. 
  printVehicle(leaf->data);
  // Recursive call on the right 
  listVehicles(leaf->right); 
}

void btree::insertVehicle(vehicle_t car) {
  if(root != NULL)
    nextVehicleNode(car, root);
  else
  {
    // root node creation 
    root=new node;
    root->key_value = car.year; // The thing we will use for search
    root->data = car;
    root->left=NULL;
    root->right=NULL;
  }
}

void btree::nextVehicleNode(vehicle_t car, node *leaf) {
  if(car.year < leaf->key_value)
    {
      if(leaf->left != NULL)
      nextVehicleNode(car, leaf->left);
      else
      {
        leaf->left = new node;
        leaf->left->key_value = car.year;
        leaf->left->data = car; 
        leaf->left->left = NULL;    //Sets the left child of the child node to null
        leaf->left->right = NULL;   //Sets the right child of the child node to null
      }  
    }
    else if(car.year >= leaf->key_value)
    {
      if(leaf->right != NULL)
        nextVehicleNode(car, leaf->right);
      else
      {
        leaf->right = new node;
        leaf->right->key_value = car.year;
        leaf->right->data = car; 
        leaf->right->left = NULL;  //Sets the left child of the child node to null
        leaf->right->right = NULL; //Sets the right child of the child node to null
      }
    }
}

vehicle_t *btree::getVehicle(int key) {
  return getVehicleNode(key, root);
}

vehicle_t *btree::getVehicleNode(int key, node *leaf) {
  if(leaf != NULL)
  {
    // If the key is equal to the node key, return data
    if(key == leaf->key_value) {
      cout << "Key is equal!\n";
      cout << "Key: " << key << endl;
      cout << "Leaf Key: " << leaf->key_value << endl;
      return &leaf->data;
    }

    if (key < leaf->key_value){
      return getVehicleNode(key, leaf->left);
    }
    else {
      return getVehicleNode(key, leaf->right);
    }
  }

  else return NULL;
}

#endif