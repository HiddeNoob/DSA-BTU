/*
 * 2_function_ptr.c - Fonksiyonlara pointer aktarımı
 * 
 */

#include <stdio.h>

void deneme(int* ptr){ // ptr maindeki sayi degiskenini gosteriyor
    *ptr = 50; // * koyarak o degiskene erisip sahip oldugu degeri degistiriyoruz.
}

int main() {
    
    // Basit değişken
    int sayi = 42;

    printf("%p -> %d\n",&sayi,sayi);
    
    // Sayiyi değiştir
    deneme(&sayi);
    
    printf("%p -> %d\n",&sayi,sayi);
    return 0;
}

