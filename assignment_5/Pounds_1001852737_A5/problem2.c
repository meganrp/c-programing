#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "problem2.h"

void read_file(FILE *fp) {

  

  data_t *n = calloc(1, sizeof(data_t)); 

  char comma =  ',';
  char newLine = '\n';

  //Read year
  
  long string_start = ftell(fp); 
  printf("Beginning is set!\n");

  while (fgetc(fp) && !feof(fp)) {
    long temp = fgetc(fp);

    if ((temp) == (comma) || (temp) == (newLine)) {
      break;
    }

  }; 

  long string_end = ftell(fp); 
  printf("End is set!\n");
  
  size_t yearSize = string_end - string_start;

  
  fseek(fp, string_start, SEEK_SET);
  n->year = calloc(yearSize, sizeof(char));
  printf("File size assigned!\n");

  printf("Beginning file read!\n");
  fread(n->year, sizeof(char), yearSize, fp);

  //debug
  printf("Input is: %s\n", n->year);

// Read Make 
  string_start = ftell(fp); 
  while (fgetc(fp) && !feof(fp)){
    long temp = fgetc(fp);
    if ((temp) == (comma) || (temp) == (newLine)) {
      break;
    }
  } 

  string_end = ftell(fp); 
  size_t makeSize = string_end - string_start;
  fseek(fp, string_start, SEEK_SET);
  n->make = calloc(makeSize, sizeof(char));
  fread(n->make, sizeof(char), makeSize, fp);

  // READ MODEL 
  string_start = ftell(fp); 
  while (fgetc(fp) && !feof(fp)) {
    long temp = fgetc(fp);
    if ((temp) == (comma) || (temp) == (newLine)) {
      break;
    }
  } 
    
  string_end = ftell(fp); 
  size_t modelSize = string_end - string_start;
  fseek(fp, string_start, SEEK_SET);
  n->model = calloc(modelSize, sizeof(char));
  fread(n->model, sizeof(char), modelSize, fp);

  // READ COLOR 
  string_start = ftell(fp); 
  while (fgetc(fp) && !feof(fp)) {
    long temp = fgetc(fp);
    if ((temp) == (comma) || (temp) == (newLine)) {
      break;
    }
  } 
   
  string_end = ftell(fp); 
  size_t colorSize = string_end - string_start;
  fseek(fp, string_start, SEEK_SET);
  n->color = calloc(colorSize, sizeof(char));
  fread(n->color, sizeof(char), colorSize, fp);

  // READ LICENSE PLATE 
 string_start = ftell(fp); 
  while (fgetc(fp) && !feof(fp)) {
    long temp = fgetc(fp);
    if ((temp) == (comma) || (temp) == (newLine)) {
      break;
    }
  } 
   
  string_end = ftell(fp); 
  size_t lisenseSize = string_end - string_start;
  fseek(fp, string_start, SEEK_SET);
  n->license_plate = calloc(lisenseSize, sizeof(char)); 
  fread(n->license_plate, sizeof(char), lisenseSize, fp); 

}


Node *create_node(Node *link) {
    Node *n = calloc(1, sizeof(Node));
    n->next = link;

    return n;
}


int main(int argc, char *argv[]) {
  FILE *fp = fopen("vehicles.csv", "rb"); 

  if (argc == 2) {
    fp = fopen(argv[1], "r");
    if (!fp) {
      printf("File not found!\n");
      return 0;
      }

  } else {
      printf("Invalid length of arguments.\n");
      return 0;
  }
  printf("File accessed!\n");
  int i = 0;
  while (i<15) {
    if (feof(fp)){
      printf("End of file reached!\n");
      break;
    }

    printf("Starting program!\n");
    Node *v1 = 0;
    create_node(v1);
    printf("Node created!\n");
    if (feof(fp)) {
      break;
    }
    read_file(fp);
    printf("Item read!\n");
    i++;


  }


  return 0;
}