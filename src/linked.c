#include <stdlib.h>

#include "linked.h"
#include "hashtable.h"
#include "util.h"

// helper function - should never interface directly
node *create_node(ht *data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

linked *init_linked(ht *data) {
    nullcheck(data, "Data Passed into LL Initializer");
    linked *l = malloc(sizeof(linked));
    l->head = create_node(data);
    l->tail = l->head;
    return l;
}

void append_node(linked *l, ht *data) {
    l->tail = l->tail->next = create_node(data);
}
