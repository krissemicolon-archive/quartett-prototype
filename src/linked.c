#include <stdlib.h>

#include "linked.h"
#include "hashtable.h"

node *create_node(ht *data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
