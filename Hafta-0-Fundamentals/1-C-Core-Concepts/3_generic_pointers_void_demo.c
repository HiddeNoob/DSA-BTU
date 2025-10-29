/*
 * 3_generic_pointers_void_demo.c - Kısa void* Demo
 * 
 * void* generic pointer kullanımı
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("=== void* Demo ===\n\n");
    
    // 1. Temel void* kullanımı
    int sayi = 42;
    char karakter = 'A';
    
    void *generic_ptr;  // Generic işaretçi
    
    
    // int adresi tutma
    generic_ptr = &sayi;
    printf("void* ile int tutma:\n");
    printf("  Değer: %d\n", *(int*)generic_ptr);  // casting gerekli!
    
    // char adresi tutma
    generic_ptr = &karakter;
    printf("void* ile char tutma:\n");
    printf("  Değer: %c\n", *(char*)generic_ptr);
    
    printf("\n");
    
    // 2. malloc() void* döndürür
    void *bellek = malloc(sizeof(int));
    if (bellek != NULL) {
        *(int*)bellek = 100;
        printf("malloc ile ayırılan bellek:\n");
        printf("  Değer: %d\n", *(int*)bellek);
        free(bellek);
    }
    
    
    return 0;
}

/*
 * void* Özet:
 * - Herhangi bir türün adresini tutabilir
 * - Doğrudan kullanılamaz, casting gerekli: *(int*)ptr
 * - malloc() void* döndürür
 * - Generic veri yapıları için temel
 */