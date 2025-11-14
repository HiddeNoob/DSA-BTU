#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generic_linkedlist.c"  

// Basit kişi yapısı
typedef struct {
    int id;
    char name[50];
} Person;

// Person yazdırma fonksiyonu
void printPerson(void* data) {
    Person* p = (Person*)data;
    printf("(%d: %s)", p->id, p->name);
}

// Person destructor
void freePerson(void* data) {
    free(data);
}

void printList(LinkedList* list){
        // Yazdır
    Node* current = list->head;
    while (current != NULL) {
        printPerson(current->data);
        printf(" -> ");
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // LinkedList oluştur
    LinkedList* list = createArray(freePerson);
    
    // Person nesneleri oluştur
    Person* p1 = malloc(sizeof(Person));
    p1->id = 1; strcpy(p1->name, "Ali");
    
    Person* p2 = malloc(sizeof(Person));
    p2->id = 2; strcpy(p2->name, "Ayşe");
    
    Person* p3 = malloc(sizeof(Person));
    p3->id = 3; strcpy(p3->name, "Mehmet");
    
    // Listeye ekle
    appendToHead(list, p1);
    appendToHead(list, p2);
    appendToTail(list, p3);
    
    printList(list);
    
    // get() test
    Person* found = (Person*)get(list, 1);
    if (found) {
        printf("Index 1: %s\n", found->name);
    }
    
    // removeAt() test
    Person* removed = (Person*)removeAt(list, 0);
    if (removed) {
        printf("Removed: %s\n", removed->name);
        free(removed);
    }

    printList(list);
    
    deleteArray(list);
    return 0;
}
