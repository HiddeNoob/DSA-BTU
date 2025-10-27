#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 
 * Hafta 0: Bellek Yönetimi Örnekleri
 * Bu dosya README.md'deki tüm C kod örneklerini içerir ve çalıştırılabilir.
 * 
 * Derleme: gcc bellek_yonetimi_ornekler.c -o bellek_yonetimi
 * Çalıştırma: ./bellek_yonetimi
 */

// Stack örneği için fonksiyon
void myFunction() {
    int a = 5; // Bu 'a' değişkeni STACK'te yaşar.
    printf("Stack Ornegi - myFunction icerisinde 'a' degeri: %d\n", a);
    // myFunction bittiğinde 'a' için ayrılan bellek otomatik olarak temizlenir.
}

// Pointer (İşaretçi) örneği için fonksiyon
void pointerOrnegi() {
    printf("\n=== ISARETCI (POINTER) ORNEGI ===\n");
    
    int x = 10;      // 'x' adında bir değişken, değeri 10.
    int* ptr = &x;   // 'ptr' adında bir İŞARETÇİ. Değeri, x'in bellek adresi.

    printf("x'in degeri: %d\n", x);          // Çıktı: 10
    printf("ptr'nin gosterdigi deger: %d\n", *ptr); // Çıktı: 10 (*ptr -> adresteki değeri al)
    printf("x'in bellek adresi: %p\n", (void*)&x);
    printf("ptr'nin degeri (x'in adresi): %p\n", (void*)ptr);
}

// malloc ve free örneği için fonksiyon
void mallocFreeOrnegi() {
    printf("\n=== MALLOC ve FREE ORNEGI ===\n");
    
    // Heap'te bir integer'lık yer ayır.
    int* sayi_ptr = (int*) malloc(sizeof(int));

    if (sayi_ptr != NULL) { // malloc bellek bulamazsa NULL döner, her zaman kontrol et!
        *sayi_ptr = 25; // Ayrılan alana 25 değerini yaz.
        printf("Heap'teki sayi: %d\n", *sayi_ptr);
        printf("Heap'teki sayinin adresi: %p\n", (void*)sayi_ptr);
        
        // İşimiz bitti, belleği geri veriyoruz.
        free(sayi_ptr); 
        printf("Bellek basariyla serbest birakildi (free).\n");
    } else {
        printf("HATA: Bellek ayrilamadi!\n");
    }
}

// Dinamik dizi oluşturma örneği
void dinamikDiziOrnegi() {
    printf("\n=== DINAMIK DIZI ORNEGI ===\n");
    
    int boyut = 5;
    
    // Heap'te 5 integer için yer ayır
    int* dizi = (int*) malloc(boyut * sizeof(int));
    
    if (dizi != NULL) {
        // Diziyi doldur
        printf("Diziyi dolduruluyor...\n");
        for (int i = 0; i < boyut; i++) {
            dizi[i] = (i + 1) * 10;
            printf("dizi[%d] = %d\n", i, dizi[i]);
        }
        
        printf("\nDizinin bellekteki konumu: %p\n", (void*)dizi);
        printf("Ayrilan toplam bellek: %lu byte\n", boyut * sizeof(int));
        
        // Belleği serbest bırak
        free(dizi);
        printf("Dizi bellegi serbest birakildi.\n");
    } else {
        printf("HATA: Dizi icin bellek ayrilamadi!\n");
    }
}

// Big O örnekleri - Gerçek işlemler ve süre ölçümü
void bigOOrnekleri(int n) {
    printf("\n=== BIG O NOTASYONU ORNEKLERI (n = %d) ===\n\n", n);
    
    // Süre ölçümü için değişkenler
    clock_t baslangic, bitis;
    double sure;
    long long islem_sayisi;
    int sonuc;
    
    // O(1) - Sabit Zaman
    printf("1. O(1) - Sabit Zaman:\n");
    printf("   Kod: int x = dizi[0];\n");
    baslangic = clock();
    sonuc = n; // Basit bir işlem
    bitis = clock();
    sure = ((double)(bitis - baslangic)) / CLOCKS_PER_SEC * 1000;
    printf("   Islem sayisi: 1\n");
    printf("   Sure: %.6f milisaniye\n", sure);
    printf("   Aciklama: n ne kadar buyuk olursa olsun, her zaman 1 islem!\n\n");
    
    // O(n) - Doğrusal Zaman
    printf("2. O(n) - Dogrusal Zaman:\n");
    printf("   Kod: for(i=0; i<n; i++) { toplam += i; }\n");
    islem_sayisi = 0;
    long long toplam = 0;
    baslangic = clock();
    for (int i = 0; i < n; i++) {
        toplam += i;
        islem_sayisi++;
    }
    bitis = clock();
    sure = ((double)(bitis - baslangic)) / CLOCKS_PER_SEC * 1000;
    printf("   Islem sayisi: %lld\n", islem_sayisi);
    printf("   Sure: %.6f milisaniye\n", sure);
    printf("   Aciklama: n tane eleman icin n tane islem yapildi.\n\n");
    
    // O(n^2) - Karesel Zaman
    printf("3. O(n^2) - Karesel Zaman:\n");
    printf("   Kod: for(i=0; i<n; i++) { for(j=0; j<n; j++) { sonuc++; } }\n");
    islem_sayisi = 0;
    sonuc = 0;
    baslangic = clock();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sonuc++;
            islem_sayisi++;
        }
    }
    bitis = clock();
    sure = ((double)(bitis - baslangic)) / CLOCKS_PER_SEC * 1000;
    printf("   Islem sayisi: %lld\n", islem_sayisi);
    printf("   Sure: %.6f milisaniye\n", sure);
    printf("   Aciklama: Ic ice 2 dongu! n=%d icin %d x %d = %lld islem!\n\n", 
           n, n, n, islem_sayisi);
}

// Stack vs Heap karşılaştırması
void stackVsHeapKarsilastirma() {
    printf("\n=== STACK vs HEAP KARSILASTIRMA ===\n");
    
    // Stack'te yerel değişken
    int stack_degiskeni = 100;
    printf("\n1. STACK Degiskeni:\n");
    printf("   Deger: %d\n", stack_degiskeni);
    printf("   Adres: %p\n", (void*)&stack_degiskeni);
    printf("   - Otomatik olarak yonetilir\n");
    printf("   - Fonksiyon bitince bellekten kaldirilir\n");
    printf("   - Cok hizli\n");
    
    // Heap'te dinamik bellek
    int* heap_degiskeni = (int*) malloc(sizeof(int));
    if (heap_degiskeni != NULL) {
        *heap_degiskeni = 200;
        printf("\n2. HEAP Degiskeni:\n");
        printf("   Deger: %d\n", *heap_degiskeni);
        printf("   Adres: %p\n", (void*)heap_degiskeni);
        printf("   - Manuel olarak yonetilir (malloc/free)\n");
        printf("   - Fonksiyondan sonra da yasamaya devam eder\n");
        printf("   - Stack'e gore daha yavas ama daha esnek\n");
        
        free(heap_degiskeni);
        printf("   - Bellek serbest birakildi (free)\n");
    }
}

int main() {
    printf("====================================\n");
    printf("HAFTA 0: BELLEK YONETIMI ORNEKLERI\n");
    printf("====================================\n");
    
    // 1. Stack örneği
    printf("\n=== STACK ORNEGI ===\n");
    printf("myFunction cagiriliyor...\n");
    myFunction();
    printf("myFunction bitti. 'a' degiskeni artik bellekte yok.\n");
    
    // 2. Pointer örneği
    pointerOrnegi();
    
    // 3. malloc ve free örneği
    mallocFreeOrnegi();
    
    // 4. Dinamik dizi örneği
    dinamikDiziOrnegi();
    
    // 5. Big O örnekleri - Farklı n değerleriyle
    printf("\n========================================\n");
    printf("BIG O KARSILASTIRMASI - FARKLI N DEGERLERI\n");
    printf("========================================\n");
    
    double n_degerleri[] = {1e1, 1e2, 1e3, 1e4, 1e5}; // 1e5 -> 1 * 10^5
    for (int i = 0; i < sizeof(n_degerleri) / sizeof((n_degerleri[0])); i++) {
        bigOOrnekleri(n_degerleri[i]);
        if (i < 3) {
            printf("----------------------------------------\n");
        }
    }
    
    // 6. Stack vs Heap karşılaştırması
    stackVsHeapKarsilastirma();
    
    printf("\n====================================\n");
    printf("TUM ORNEKLER TAMAMLANDI!\n");
    printf("====================================\n");
    
    return 0;
}
