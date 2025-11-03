#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void** data; // veriler
    int size; // şuanki veri sayisi
    int capacity; // max kapasite
    void (*deconstructor)(void* data); // kullanıcının eklediği datayı nasıl sileceğini bilen fonksiyon
} DynArray;

// yeni bir dinamik dizi oluşturur
// döndürür: oluşturulan DynArray* (başarısızsa NULL)
DynArray* createArray() {
    
}

// DynArray yapısını siler ve ek olarak
// kullanıcının verisini kendi yazdığı fonksiyona göre siler
// parametre: 
// silinecek DynArray* arr
// her bir verinin nasıl silindiğini tarif eden deconstructor
void deleteArray(DynArray* arr){

}

// kapasiteyi 2 katına çıkarır (gerekirse)
// parametre: büyütülecek DynArray*
// döndürür: başarılıysa 1, hata varsa 0
static int resizeArray(DynArray* arr) {
    
}

// diziye yeni eleman ekler
// parametreler: 
// arr -> hedef dizi,
// value -> eklenecek eleman (void*)
// döndürür: başarılıysa 1, hata varsa 0
int append(DynArray* arr, void* value) {
    
}

// belirtilen index’teki elemanı döndürür
// parametreler: arr -> dizi, index -> alınacak konum
// döndürür: geçerliyse data[index], yoksa NULL
void* get(DynArray* arr, int index) {
    
}

// belirtilen index’teki elemanı siler
// parametreler: arr -> dizi, index -> silinecek konum
// döndürür: geçerliyse data[index], yoksa NULL
void* remove(DynArray* arr, int index){

}
