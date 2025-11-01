/*
 * 2_function_ptr.c - Fonksiyonlara pointer aktarımı
 * 
 */

#include <stdio.h>

void deneme(int* ptr){ // ptr maindeki sayi degiskenini gosteriyor
    printf("%p\n",ptr);
    printf("%d\n",*ptr);
    *ptr = 67; // * koyarak o degiskene erisip sahip oldugu degeri degistiriyoruz.
}

int main() {
    
    // Basit değişken
    int sayi = 42;
    printf("%d\n",sayi);

    printf("%p\n",&sayi);

    // Sayiyi değiştir
    deneme(&sayi);
    
    printf("%d\n",sayi);
    return 0;
}

