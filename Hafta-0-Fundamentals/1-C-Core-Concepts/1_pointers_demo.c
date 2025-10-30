/*
 * 1_pointers_demo.c - Kısa Pointer Demo
 * 
 * & operatörü: adres alma
 * * operatörü: değere erişim
 */

#include <stdio.h>

int main() {
    printf("=== Pointer Demo ===\n");
    
    // Basit değişken
    int sayi = 42;
    
    // Pointer tanımla
    int *ptr = &sayi;  // sayi'nin adresini al
    
    printf("sayi = %d\n", sayi);
    printf("ptr adresi = %p\n", (void*)ptr);
    printf("*ptr değeri = %d\n", *ptr);
    
    // Pointer ile değeri değiştir
    *ptr = 100;
    printf("*ptr = 100 sonrası:\n");
    printf("sayi = %d\n", sayi);
    
    // Farklı türlerde pointerlar
    printf("\nFarklı türler:\n");
    char karakter = 'a';
    char *char_ptr = &karakter;
    
    printf("karakter = %c\n", karakter);
    printf("*char_ptr = %c\n", *char_ptr);
    
    return 0;
}

/*
 * Pointer Özet:
 * & = adres alma operatörü
 * * = değere erişim operatörü  
 * Pointer = adres tutan değişken
 */