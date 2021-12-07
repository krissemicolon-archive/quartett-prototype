#ifndef LINKED_H
#define LINKED_H

#include "hashtable.h"

struct node {
    ht *data;
    struct node *next;
};

struct node;
typedef struct node node;

node *create_node(ht *);

#endif
