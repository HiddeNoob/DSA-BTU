#include <stdio.h>
#include <stdlib.h>

int main(){
    size_t veri = sizeof(int) + 1; // 4 + 1 byte
    void* ptr = malloc(veri); // 5 bytelık yer tahsis ettik

    int* sayi = ptr; // 4 bytelık yazma okuma için int pointer'ına casting yaptık

    *sayi = 5; // ilk 4 bytelık kısma yazdı
    // ancak sonda kalan yukarda fazladan istediğimiz 1 byte
    // boşa gitmiş oldu bu sebeple gerekenden fazla veri tahsis etmeyiz 

    // manuel tahsis ettik
    // manuel olarak veriyi siliyoruz
    free(sayi); 

    
}