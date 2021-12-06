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
} hashtable;

unsigned int hash(const char *);
ht_entry *ht_pair(const char *, const char *);
void ht_set(hashtable *, const char *, const char *);
char *ht_get(hashtable *, const char *);
hashtable *ht_create(void);
void ht_dump(hashtable *);


#endif

/* struct Node { */
/*     char *key; */
/*     char *value; */
/*     struct Node* next; */
/* }; */
/*  */
/* struct Node; */
/* typedef struct Node Node; */
