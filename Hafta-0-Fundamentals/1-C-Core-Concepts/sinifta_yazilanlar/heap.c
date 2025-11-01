#include <stdlib.h>
#include <stdio.h>

int main(){
    int a = 5; // stackde oluştu

    int* b = (int*)malloc(sizeof(int));
    // b pointer'ı yine stack'de oluştu
    // ancak
    // malloc heapten 4'bytelık yer oluşturdu
    // bu address b pointerına atandı

    // heaple stack farklı yerlerde
    printf("stack -> %p heap -> %p",&a,b); 
}