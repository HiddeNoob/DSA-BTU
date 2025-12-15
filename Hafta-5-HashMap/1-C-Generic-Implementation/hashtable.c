/*
 * hashtable.c - HashMap Implementation
 * DynArray + LinkedList kullanarak
 */

#include <stdio.h>
#include <stdlib.h>

#include "dynarray.h"
#include "linkedlist.h"

typedef struct {
    int key;
    int value;
} Entry;

typedef struct {
    DynArray* buckets;
    int size;
    int count;
} HashTable;

int hash(int key, int size) {
    // TODO
    return 0;
}

void entry_destructor(void* data) {
    // TODO
}

void bucket_destructor(void* data) {
    // TODO
}

Entry* ht_find_entry(LinkedList* bucket, int key) {
    // TODO
    return NULL;
}

HashTable* ht_create(int size) {
    // TODO
    return NULL;
}

void ht_destroy(HashTable* ht) {
    // TODO
}

void ht_insert(HashTable* ht, int key, int value) {
    // TODO
}

int ht_search(HashTable* ht, int key, int* found) {
    // TODO
    if (found) *found = 0;
    return 0;
}

int ht_delete(HashTable* ht, int key) {
    // TODO
    return 0;
}

void ht_print(HashTable* ht) {
    // TODO
}
