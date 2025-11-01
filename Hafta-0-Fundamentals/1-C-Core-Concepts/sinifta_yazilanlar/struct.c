#include <stdio.h>
#include <stdlib.h>

struct Ogrenci
{
    int yas;
    int notlar[3];
    char sinif;
};

// ogrenci kopyasi olustu
void ogrenciYazdirPointersiz(struct Ogrenci ogrenci){ 
    printf("Pointersiz Ogrencinin Adresi: %p\n",&ogrenci);

    printf("yas -> %d\n",ogrenci.yas);
    printf("not 1 -> %d\n",ogrenci.notlar[0]);
    printf("not 2 -> %d\n",ogrenci.notlar[1]);
    printf("not 3 -> %d\n",ogrenci.notlar[2]);
    printf("sinif -> %d\n",ogrenci.sinif);
}

void ogrenciYazdirPointerli(struct Ogrenci* ogrenci){
    printf("Pointerli Ogrencinin Adresi: %p\n",ogrenci);

    printf("yas -> %d\n",ogrenci->yas);
    printf("not 1 -> %d\n",ogrenci->notlar[0]);
    printf("not 2 -> %d\n",ogrenci->notlar[1]);
    printf("not 3 -> %d\n",ogrenci->notlar[2]);
    printf("sinif -> %d\n",ogrenci->sinif);
}


int main(){

    struct Ogrenci ogrenci1;

    printf("maindeki addresi: %p\n",&ogrenci1);

    ogrenci1.sinif = 10;
    ogrenci1.yas = 20;

    ogrenci1.notlar[0] = 100;
    ogrenci1.notlar[1] = 50;
    ogrenci1.notlar[2] = 300;

    ogrenciYazdirPointerli(&ogrenci1);

    ogrenciYazdirPointersiz(ogrenci1); 




    
}