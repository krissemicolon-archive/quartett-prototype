#include <stdlib.h>
#include <stdio.h>

#include "linked.h"
#include "hashtable.h"
#include "util.h"

// helper function - should never interface directly
node *create_node(ht *data) {
    node *n = malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

linked *init_linked(ht *data) {
    nullcheck(data, "Data Passed into LL Initializer");
    linked *l = malloc(sizeof(linked));
    l->tail = l->head = create_node(data);
    l->size = 1;
    return l;
}

void append_node(linked *l, ht *data) {
    l->tail = l->tail->next = create_node(data);
    l->size++;
}

void dump_linked(linked *l) {
    node *current = l->head;
    for(size_t i = 1; i <= l->size; i++) {
        printf("Data of Node %zu/%zu\n", i, l->size);
        ht_dump(current->data);
        printf("\n");
        current = current->next;
    }
}
