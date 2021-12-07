#include <stdlib.h>
#include <stdio.h>

#include "parser.h"
#include "hashtable.h"
#include "linked.h"
#include "util.h"

int main() {
    ht *ht = ht_create();

    ht_set(ht, "name", "X220");
    ht_set(ht, "cpu", "i7");
    ht_set(ht, "keyboard", "half-sized");

    linked *list = init_linked(ht);

    ht_dump(list->head->data);

    return 0;
}
