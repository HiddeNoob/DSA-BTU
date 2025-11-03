#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* data;      // int verileri tutar
    int size;       // mevcut eleman sayısı
    int capacity;   // toplam kapasite
} IntArray;


// yeni bir int dizisi oluşturur
// döndürür: oluşturulan IntArray* (başarısızsa NULL)
IntArray* createArray() {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));

    array->capacity = 5;
    array->data = (int*)malloc(sizeof(int) * 5);
    array->size = 0;

    return array;
}

void deleteArray(IntArray* arr){
    free(arr->data);
    free(arr);
}

// kapasiteyi 2 katına çıkarır (gerekirse)
// parametre: büyütülecek IntArray*
// döndürür: başarılıysa 1, hata varsa 0
static int resizeArray(IntArray* arr) {
    int new_capacity = arr->capacity * 2;
    int *tmp = (int*)realloc(arr->data, sizeof(int) * new_capacity);
    if (tmp == NULL) return 0;
    arr->data = tmp;
    arr->capacity = new_capacity;
    return 1;
}

// diziye yeni eleman ekler
// parametreler: arr -> hedef dizi, value -> eklenecek int değer
// döndürür: başarılıysa 1, hata varsa 0
void append(IntArray* arr, int value) {
    if (arr->size >= arr->capacity) {
        if (!resizeArray(arr)) return; /* allocation failed - silently ignore for class demo */
    }
    arr->data[arr->size] = value;
    arr->size++;


}

// belirtilen index’teki elemanı döndürür
// parametreler: arr -> dizi, index -> alınacak konum
// döndürür: geçerliyse data[index], yoksa 0 veya hata için uygun değer
int* get(IntArray* arr, int index) {
    if(index < 0 || index >= arr->size) return NULL;
    return &arr->data[index];
}

// belirtilen index’teki elemanı siler
// parametreler: arr -> dizi, index -> silinecek konum
// döndürür: geçerliyse data[index], yoksa NULL
int* removeAt(IntArray* arr, int index){
    if (index < 0 || index >= arr->size) return NULL;

    /* Kaydırma yapmadan önce silinen değeri sakla */
    int *removed = (int*)malloc(sizeof(int));
    if (!removed) return NULL;
    *removed = arr->data[index];

    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i+1];
    }
    arr->size--;

    return removed; /* Caller should free() the returned pointer */
}
