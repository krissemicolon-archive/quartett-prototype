#ifndef HASHTABLE_H
#define HASHTABLE_H

#define TABLE_SIZE 100000

typedef struct ht_entry {
    char *key;
    char *value;
    struct ht_entry *next;
} ht_entry;

typedef struct {
    ht_entry **entries;
} ht;

unsigned int hash(const char *);
ht_entry *ht_pair(const char *, const char *);
ht *ht_create(void);
void ht_set(ht *, const char *, const char *);
char *ht_get(ht *, const char *);
void ht_del(ht *, const char *);
void ht_dump(ht *);

#endif
