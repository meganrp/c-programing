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

        void insert(int key);
        void insertVehicle(vehicle_t car); 

        node *search(int key);
        vehicle_t getVehicle(int key);
 
    private:
        void nextVehicleNode(vehicle_t car, node *leaf);
        void insertNode(int key, node *leaf);

        node *search(int key, node *leaf);
        vehicle_t getVehicleNode(int key, node *leaf); 
         
        node *root;
};

btree::btree() {
  root=NULL;
}

void btree::insertVehicle(vehicle_t car) {
  if(root != NULL)
    //insertNode(key, root);
    cout << "f u";
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

// PUBLIC 
void btree::insert(int key) {
  if(root!=NULL)
    insertNode(key, root);
  else
  {
    root=new node;
    root->key_value=key;
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

// PRIVATE 
void btree::insertNode(int key, node *leaf) {
  if(key < leaf->key_value)
  {
    if(leaf->left != NULL)
     insertNode(key, leaf->left);
    else
    {
      leaf->left = new node;
      leaf->left->key_value = key;
      leaf->left->left = NULL;    //Sets the left child of the child node to null
      leaf->left->right = NULL;   //Sets the right child of the child node to null
    }  
  }
  else if(key >= leaf->key_value)
  {
    if(leaf->right != NULL)
      insertNode(key, leaf->right);
    else
    {
      leaf->right = new node;
      leaf->right->key_value = key;
      leaf->right->left = NULL;  //Sets the left child of the child node to null
      leaf->right->right = NULL; //Sets the right child of the child node to null
    }
  }
}

vehicle_t btree::getVehicle(int key) {
  return getVehicleNode(key, root);
}

vehicle_t btree::getVehicleNode(int key, node *leaf) {
  if(leaf != NULL)
  {

    if(key == leaf->key_value)
      return leaf->data;

    if(key < leaf->key_value)
      return getVehicleNode(leaf->data.year, leaf->left);

    else
      return getVehicleNode(leaf->data.year, leaf->right);
  }

  else return NewVehicle();
}

node *btree::search(int key) {
  return search(key, root);
}

node *btree::search(int key, node *leaf) {
  if(leaf != NULL)
  {
    if(key == leaf->key_value)
      return leaf;
    if(key < leaf->key_value)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return NULL;
}

#endif