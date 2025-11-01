/*
 * 2_structs_and_heap_demo.c - Kısa Struct Demo
 * 
 * Struct tanımlama ve malloc kullanımı
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Basit Student struct
struct Student {
    int id;
    char name[30];
    float gpa;
};

int main() {
    printf("=== Struct Demo ===\n");
    
    // Stack'te struct
    struct Student s1;
    s1.id = 123;
    strcpy(s1.name, "Ali");
    s1.gpa = 3.5;
    
    printf("Stack student: %d, %s, %.1f\n", s1.id, s1.name, s1.gpa);
    
    // Heap'te struct (malloc)
    struct Student *s2 = malloc(sizeof(struct Student));
    s2->id = 456;
    strcpy(s2->name, "Ayşe");
    s2->gpa = 3.8;
    
    printf("Heap student: %d, %s, %.1f\n", s2->id, s2->name, s2->gpa);
    
    free(s2);  // Belleği temizle
    
    return 0;
}