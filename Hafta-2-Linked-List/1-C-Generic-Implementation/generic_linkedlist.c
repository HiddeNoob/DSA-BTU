#include <stdio.h>
#include <stdlib.h>

/*
 * Node Structure - Tek bağlı liste düğümü
 * - data: Generic veri pointer'ı (void*)
 * - next: Sonraki düğümü gösteren pointer
 */
typedef struct Node {
    void* data;           
    struct Node* next;
} Node;

/*
 * LinkedList Structure - Liste yönetim yapısı
 * - head: İlk düğümü gösteren pointer
 * - destructor: Veriyi nasıl sileceğini bilen fonksiyon (DynArray'daki gibi)
 */
typedef struct {
    Node* head;
    void (*destructor)(void* data);
} LinkedList;

// yeni bir LinkedList oluşturur (DynArray createArray'e benzer)
// parametre: destructor -> veriyi nasıl sileceğini bilen fonksiyon  
// döndürür: oluşturulan LinkedList* (başarısızsa NULL)
LinkedList* createArray(void (*destructor)(void* data)) {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    
    if (!list) {
        return NULL;
    }

    list->destructor = destructor;
    list->head = NULL;

    return list;
}

// LinkedList yapısını siler ve tüm elemanları temizler 
// parametre: list -> silinecek LinkedList
void deleteArray(LinkedList* list) {
    if (!list) return;
    
    Node* ptr = list->head;
    Node* next = NULL;
    while(ptr){
        if (list->destructor && ptr->data) {
            list->destructor(ptr->data);
        }
        next = ptr->next;
        free(ptr);
        ptr = next;
    }
    free(list);
}

// listeye yeni eleman ekler
// parametreler: list -> hedef liste, value -> eklenecek eleman (void*)
// döndürür: başarılıysa 1, hata varsa 0
int appendToHead(LinkedList* list, void* value) {
    if (!list) return 0;
    
    Node* newNode = (Node*)malloc(sizeof(Node));
 
    if(!newNode){ // null ptr
        return 0;
    }

    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;

    return 1;
}

// liste sonuna eleman ekle 
// parametreler: list -> hedef liste, value -> eklenecek eleman
// döndürür: başarılıysa 1, hata varsa 0
int appendToTail(LinkedList* list, void* value) {
    if (!list) return 0;
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return 0;

    newNode->data = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        return 1;
    }

    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return 1;
}

// belirtilen pozisyona eleman ekle 
// parametreler: list -> hedef liste, index -> pozisyon, value -> eklenecek eleman
// döndürür: başarılıysa 1, hata varsa 0
int insertAt(LinkedList* list, int index, void* value) {
    if (!list || index < 0) return 0;
    
    // Index 0 ise başa ekle
    if (index == 0) {
        return appendToHead(list, value);
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return 0;
    
    newNode->data = value;
    
    // Index-1'e kadar git
    Node* current = list->head;
    for (int i = 0; i < index - 1 && current != NULL; i++) {
        current = current->next;
    }
    
    // Eğer index geçerli değilse
    if (current == NULL) {
        free(newNode);
        return 0;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    
    return 1;
}

// belirtilen index'teki elemanı siler 
// parametreler: list -> liste, index -> silinecek konum
// döndürür: silinen veri
// NOT: DynArray removeAt elemanları sola kaydırır, LinkedList bağlantıları günceller
void* removeAt(LinkedList* list, int index) {
    if (!list || index < 0 || list->head == NULL) {
        return NULL;
    }
    
    // İlk elemanı siliyorsak
    if (index == 0) {
        Node* nodeToRemove = list->head;
        void* data = nodeToRemove->data;
        list->head = list->head->next;
        free(nodeToRemove); // Node'u sildik ama datayi silmedik doğrudan kullanıcıya verdik
        return data;
    }
    
    // Index-1'e kadar git
    Node* current = list->head;
    for (int i = 0; i < index - 1 && current->next != NULL; i++) {
        current = current->next;
    }
    
    // Eğer silinecek node yoksa
    if (current->next == NULL) {
        return NULL;
    }
    
    Node* nodeToRemove = current->next;
    void* data = nodeToRemove->data;
    current->next = nodeToRemove->next;
    
    free(nodeToRemove);
    
    return data;
}

// belirtilen index'teki elemanı döndürür
// parametreler: list -> liste, index -> alınacak konum  
// döndürür: geçerliyse data[index], yoksa NULL
// NOT: DynArray get O(1), LinkedList get O(n) - traversal gerekli!
void* get(LinkedList* list, int index) {
    if (!list || index < 0 || list->head == NULL) {
        return NULL;
    }
    
    Node* current = list->head;
    for (int i = 0; i < index && current != NULL; i++) {
        current = current->next;
    }
    
    if (current == NULL) {
        return NULL;
    }
    
    return current->data;
}
