#include <stdlib.h>
#include <stdio.h>

#include "parser.h"
#include "hashtable.h"
#include "linked.h"

int main() {
    ht *ht = ht_create();

    ht_set(ht, "name", "X220");
    ht_set(ht, "cpu", "i7");
    ht_set(ht, "keyboard", "half-sized");

    node *head = create_node(ht);
    ht_dump(head->data);

    return 0;
}
