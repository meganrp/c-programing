#ifndef LINKLIST_H_
#define LINKLIST_H_

typedef struct data {
    char *year; 
    char *make; 
    char *model; 
    char *color; 
    char *license_plate; 
} data_t;

typedef struct node Node;
struct node {
    data_t *link;
    Node *next;
};



#endif