/*
 * hashtable.c - HashMap Implementation
 * DynArray + LinkedList kullanarak
 */

#include <stdio.h>
#include <stdlib.h>


#define BUCKET_COUNT 100

int hash(int key){
    return key % BUCKET_COUNT;
}

typedef struct {
    int key;
    void* value;
} Entry;

typedef struct Node
{
    Entry* data;
    Node* next;
}Node;


typedef struct {
    Node* buckets[BUCKET_COUNT];
    int count;
} HashTable;





HashTable* HashTableConstructor(){
    HashTable* ptr = (HashTable*)malloc(sizeof(HashTable));
    ptr->count = 0;
    return ptr;
}

void insert(HashTable* table,int keyData,void* value){
    
    int key = hash(keyData);
    
    Node** bucket = &table->buckets[key];


    Entry* entry = (Entry*)malloc(sizeof(Entry));

    entry->key = keyData;
    entry->value = value;


    Node* dataNode = (Node*)malloc(sizeof(Node));
    dataNode->next = NULL;

    dataNode->data = entry;

    if(*bucket == NULL){
        *bucket = dataNode;
    }else{

        Node* temp = *bucket;
        *bucket = dataNode;

        dataNode->next = temp;

    }
}


void* get(HashTable* table,int* key){
    int bucketId = hash(*key);

    Node** currentNode = &table->buckets[bucketId];

    void* data = NULL;

    while(*currentNode != NULL){
        Entry* entry = (*currentNode)->data;
        if(entry->key == *key){
            data = entry->value;
            break;
        }
        currentNode = &(*currentNode)->next; 
    }

    return data;
}

