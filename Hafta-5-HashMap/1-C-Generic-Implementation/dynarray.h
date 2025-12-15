/*
 * dynarray.h - Generic Dynamic Array Library
 * 
 * Hafta-1'den alınan dinamik dizi implementasyonu
 * Header dosyası olarak kullanılmak üzere düzenlendi
 */

#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <stdlib.h>

typedef struct {
    void** data;
    int size;
    int capacity;
    void (*deconstructor)(void* data);
} DynArray;

// Yeni bir dinamik dizi oluşturur
static DynArray* dynarray_create(void (*deconstructor)(void* data)) {
    DynArray* arr = (DynArray*)malloc(sizeof(DynArray));
    if (!arr) return NULL;
    arr->capacity = 5;
    arr->deconstructor = deconstructor; 
    arr->data = malloc(sizeof(void*) * arr->capacity);
    if (!arr->data) { free(arr); return NULL; }
    arr->size = 0;
    return arr;
}

// DynArray yapısını siler
static void dynarray_delete(DynArray* arr) {
    if (!arr) return;
    for (int i = 0; i < arr->size; i++) {
        void* current_data = arr->data[i];
        if (arr->deconstructor) arr->deconstructor(current_data);
    }
    free(arr->data);
    free(arr);
}

// Kapasiteyi 2 katına çıkarır
static int dynarray_resize(DynArray* arr) {
    int new_capacity = arr->capacity * 2;
    void **tmp = (void**)realloc(arr->data, sizeof(void*) * new_capacity);
    if (!tmp) return 0;
    arr->data = tmp;
    arr->capacity = new_capacity;
    return 1;
}

// Diziye yeni eleman ekler
static int dynarray_append(DynArray* arr, void* value) {
    if (arr->size >= arr->capacity) {
        if (!dynarray_resize(arr)) return 0;
    }
    arr->data[arr->size] = value;
    arr->size++;
    return 1;
}

// Belirtilen index'teki elemanı döndürür
static void* dynarray_get(DynArray* arr, int index) {
    if(arr->size <= index || index < 0) return NULL;
    return arr->data[index];
}

// Belirtilen index'e eleman set eder
static int dynarray_set(DynArray* arr, int index, void* value) {
    if (index < 0 || index >= arr->size) return 0;
    arr->data[index] = value;
    return 1;
}

// Dizinin boyutunu döndürür
static int dynarray_size(DynArray* arr) {
    if (!arr) return 0;
    return arr->size;
}

// Belirtilen index'teki elemanı siler
static void* dynarray_remove_at(DynArray* arr, int index) {
    if (!arr) return NULL;
    if (index < 0 || index >= arr->size) return NULL;

    void *val = arr->data[index];
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i+1];
    }
    arr->size--;
    return val;
}

#endif // DYNARRAY_H
