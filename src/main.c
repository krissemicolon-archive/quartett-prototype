#include <stdlib.h>
#include <stdio.h>

#include "parser.h"
#include "hashtable.h"

int main() {
    hashtable *ht = ht_create();

    ht_set(ht, "key1", "car");
    ht_set(ht, "key2", "house");
    ht_set(ht, "key3", "painting");

    ht_dump(ht);

    return 0;
}
