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
    
}

void deleteArray(){
    
}

// kapasiteyi 2 katına çıkarır (gerekirse)
// parametre: büyütülecek IntArray*
// döndürür: başarılıysa 1, hata varsa 0
static int resizeArray(IntArray* arr) {
    
}

// diziye yeni eleman ekler
// parametreler: arr -> hedef dizi, value -> eklenecek int değer
// döndürür: başarılıysa 1, hata varsa 0
int append(IntArray* arr, int value) {
    
}

// belirtilen index’teki elemanı döndürür
// parametreler: arr -> dizi, index -> alınacak konum
// döndürür: geçerliyse data[index], yoksa 0 veya hata için uygun değer
int get(IntArray* arr, int index) {
    
}

// belirtilen index’teki elemanı siler
// parametreler: arr -> dizi, index -> silinecek konum
// döndürür: geçerliyse data[index], yoksa NULL
int* remove(IntArray* arr, int index){

}
