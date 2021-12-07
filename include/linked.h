#ifndef LINKED_H
#define LINKED_H

#include "hashtable.h"

struct node {
    ht *data;
    struct node *next;
};
struct node;
typedef struct node node;

typedef struct {
    node *head;
    node *tail;
} linked;

node *create_node(ht *);
linked *init_linked(ht *);
void append_node(linked *, ht*);

#endif
