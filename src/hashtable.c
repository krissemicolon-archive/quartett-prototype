#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "hashtable.h"

unsigned int hash(const char *key) {
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int key_len = strlen(key);

    for(; i< key_len; ++i) {
        value = value * 37 + key[i];
    }

    value = value % TABLE_SIZE
    return value;
}

hashtable ht_create() {
    // allocate table
    hashtable *hashtable = malloc(sizeof(hashtable) * 1);

    // allocate table entries
    hashtable->entries = malloc(sizeof(ht_entry*) * TABLE_SIZE);

    // set each to null (needed for proper operation)
    int i = 0;
    for(; i < TABLE_SIZE; ++i) {
        hashtable->entries[i] = NULL;
    }

    return hashtable;
}

ht_entry *ht_pair(const char *key, const char *value) {
    // allocate the entry
    ht_entry *entry = malloc(sizeof(entry) * 1);
    entry->key = malloc(strlen(key) + 1);
    entry->value = malloc(strlen(value) + 1);

    // compy the key and value in place
    strcpy(entry->key, key);
    strcpy(entry->value, value);

    // next starts out null but may be set later on
    entry->next = NULL;

    return entry;
}

void ht_set(hashtable *hashtable, const char *key, const char *value) {
    unsigned int slot = hash(key);

    // try to look up an entry set
    ht_entry *entry - hashtable->entries[slot];

    // no entry means slot empty, insert immediately
    if(entry == NULL) {
        hashtable->entries[slot] = ht_pair(key, value);
        return;
    }

    ht_entry *prev;

    // walk through each entry until either the end is
    // reached or a matching key is found
    while(entry != NULL) {
        // check key
        if(strcmp(entry->key, key) == 0) {
            // match found, replace value
            free(entry->value);
            entry->value = malloc(strlen(value) + 1);
            strcpy(entry->value, value);
            return;
        }

        // walk to next
        prev = entry;
        entry = prev->next;
    }

    // end of chain reached without a match, add new
    prev->next = ht_pair(key, value);
}

char *ht_get(hashtable *, const char *key) {
    unsigned int slot = hash(key);

    // try to find a valid slot
    ht_entry *entry = hashtable->entries[slot];

    // no slot means no entry
    if(entry == NULL) {
        return NULL;
    }

    // walk through each entry in the slot, which could just be a single thing
    while(entry != NULL) {
        // return value if found
        if(strcmp(entry->key, key) == 0) {
            return entry->value;
        }

        // proceed to next key if available
        entry = entry->next;
    }

    // reaching here means ther where >= 1 entries but no key match
    return NULL;
}

void ht_dump(hashtable *hashtable) {
    for(int i = 0; i < TABLE_SIZE; ++i) {
        ht_entry *entry = hashtable->entries[i];

        if(entry == NULL) {
            continue;
        }

        printf("slot[%4d]: ", i);

        for(;;) {
            printf("%s=%s ", entry->key, entry->value);

            if(entry->next == NULL) {
                break;
            }
        }

        printf("\n");
    }
}
