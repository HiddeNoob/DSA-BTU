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
    // Kodunu buraya yaz!
}

// LinkedList yapısını siler ve tüm elemanları temizler 
// parametre: list -> silinecek LinkedList
void deleteArray(LinkedList* list) {
    // Kodunu buraya yaz!
}

// listeye yeni eleman ekler
// parametreler: list -> hedef liste, value -> eklenecek eleman (void*)
// döndürür: başarılıysa 1, hata varsa 0
int appendToHead(LinkedList* list, void* value) {
    // Kodunu buraya yaz!
}

// liste sonuna eleman ekle 
// parametreler: list -> hedef liste, value -> eklenecek eleman
// döndürür: başarılıysa 1, hata varsa 0
int appendToTail(LinkedList* list, void* value) {
    // Kodunu buraya yaz!
}

// belirtilen pozisyona eleman ekle 
// parametreler: list -> hedef liste, index -> pozisyon, value -> eklenecek eleman
// döndürür: başarılıysa 1, hata varsa 0
int insertAt(LinkedList* list, int index, void* value) {
    // Kodunu buraya yaz!
}

// belirtilen index'teki elemanı siler 
// parametreler: list -> liste, index -> silinecek konum
// döndürür: silinen veri
// NOT: DynArray removeAt elemanları sola kaydırır, LinkedList bağlantıları günceller
void* removeAt(LinkedList* list, int index) {
    // Kodunu buraya yaz!
}

// belirtilen index'teki elemanı döndürür
// parametreler: list -> liste, index -> alınacak konum  
// döndürür: geçerliyse data[index], yoksa NULL
// NOT: DynArray get O(1), LinkedList get O(n) - traversal gerekli!
void* get(LinkedList* list, int index) {
    // Kodunu buraya yaz!
}
