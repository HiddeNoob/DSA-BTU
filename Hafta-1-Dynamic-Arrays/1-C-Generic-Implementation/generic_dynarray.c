#include <stdlib.h>

typedef struct {
    void** data; // veriler
    int size; // şuanki veri sayisi
    int capacity; // max kapasite
    void (*deconstructor)(void* data); // kullanıcının eklediği datayı nasıl sileceğini bilen fonksiyon
} DynArray;

// yeni bir dinamik dizi oluşturur
// döndürür: oluşturulan DynArray* (başarısızsa NULL)
DynArray* createArray(void (*deconstructor)(void* data)) {
    DynArray* arr = (DynArray*)malloc(sizeof(DynArray));
    if (!arr) return NULL;
    arr->capacity = 5;
    arr->deconstructor = deconstructor; 
    arr->data = malloc(sizeof(void*) * arr->capacity);
    if (!arr->data) { free(arr); return NULL; }
    arr->size = 0;
    return arr;

}

// DynArray yapısını siler ve ek olarak
// kullanıcının verisini kendi yazdığı fonksiyona göre siler
// parametre: 
// silinecek DynArray* arr
// her bir verinin nasıl silindiğini tarif eden deconstructor
void deleteArray(DynArray* arr){
    if (!arr) return;
    for (int i = 0; i < arr->size; i++) {
        void* current_data = arr->data[i];
        if (arr->deconstructor) arr->deconstructor(current_data);
    }
    free(arr->data);

    free(arr);
    
}

// kapasiteyi 2 katına çıkarır (gerekirse)
// parametre: büyütülecek DynArray*
// döndürür: başarılıysa 1, hata varsa 0
static int resizeArray(DynArray* arr) {
    int new_capacity = arr->capacity * 2;
    void **tmp = (void**)realloc(arr->data, sizeof(void*) * new_capacity);
    if (!tmp) return 0;
    arr->data = tmp;
    arr->capacity = new_capacity;
    return 1;
}

// diziye yeni eleman ekler
// parametreler: 
// arr -> hedef dizi,
// value -> eklenecek eleman (void*)
// döndürür: başarılıysa 1, hata varsa 0
int append(DynArray* arr, void* value) {
    if (arr->size >= arr->capacity) {
        if (!resizeArray(arr)) return 0;
    }
    arr->data[arr->size] = value;
    arr->size++;
    return 1;
}

// belirtilen index’teki elemanı döndürür
// parametreler: arr -> dizi, index -> alınacak konum
// döndürür: geçerliyse data[index], yoksa NULL
void* get(DynArray* arr, int index) {
    if(arr->size <= index || index < 0) return NULL;

    return arr->data[index];
}

// belirtilen index’teki elemanı siler
// parametreler: arr -> dizi, index -> silinecek konum
// döndürür: geçerliyse data[index], yoksa NULL
void* removeAt(DynArray* arr, int index) {
    if (!arr) return NULL;
    if (index < 0 || index >= arr->size) return NULL;

    void *val = arr->data[index];
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i+1]; // bütün elemanları sola kaydır
    }
    arr->size--;
    return val; /* caller owns the returned pointer */
}

