/*
 * linkedlist.h - Generic Linked List Library
 * 
 * Hafta-2'den alınan bağlı liste implementasyonu
 * Header dosyası olarak kullanılmak üzere düzenlendi
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

/*
 * Node Structure - Tek bağlı liste düğümü
 */
typedef struct LLNode {
    void* data;           
    struct LLNode* next;
} LLNode;

/*
 * LinkedList Structure - Liste yönetim yapısı
 */
typedef struct {
    LLNode* head;
    int size;
    void (*destructor)(void* data);
} LinkedList;

// Yeni bir LinkedList oluşturur
static LinkedList* linkedlist_create(void (*destructor)(void* data)) {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (!list) return NULL;
    
    list->destructor = destructor;
    list->head = NULL;
    list->size = 0;
    return list;
}

// LinkedList yapısını siler ve tüm elemanları temizler 
static void linkedlist_delete(LinkedList* list) {
    if (!list) return;
    
    LLNode* ptr = list->head;
    LLNode* next = NULL;
    while(ptr) {
        if (list->destructor && ptr->data) {
            list->destructor(ptr->data);
        }
        next = ptr->next;
        free(ptr);
        ptr = next;
    }
    free(list);
}

// Liste başına eleman ekler (O(1))
static int linkedlist_prepend(LinkedList* list, void* value) {
    if (!list) return 0;
    
    LLNode* newNode = (LLNode*)malloc(sizeof(LLNode));
    if (!newNode) return 0;

    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
    return 1;
}

// Head node'u döndürür (iteration için)
static LLNode* linkedlist_head(LinkedList* list) {
    if (!list) return NULL;
    return list->head;
}

#endif // LINKEDLIST_H
