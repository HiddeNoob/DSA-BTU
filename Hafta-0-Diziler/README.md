# Hafta 0: Dersin Temelleri - Algoritma Analizi ve C'de Bellek Yönetimi

Hoş geldiniz! Veri yapıları dünyasına dalmadan önce, bu yapıları inşa ederken kullanacağımız temel araçları ve prensipleri anlamamız gerekiyor. Bu "Sıfırıncı Hafta", sonraki haftalarda göreceğimiz her C kodunun "neden" ve "nasıl" o şekilde yazıldığını anlamanız için bir temel atacaktır.

Bu hafta herhangi bir veri yapısı implemente etmeyeceğiz. Sadece C programlamanın ve algoritma tasarımının en kritik kavramlarına odaklanacağız.

## 1. Algoritma Analizi: Big O Notasyonu (Neden Önemli?)

Bir programın ne kadar "iyi" olduğunu nasıl ölçeriz? Big O Notasyonu, bir algoritmanın performansını, özellikle de girdi boyutu (`n`) büyüdükçe nasıl davrandığını analiz etmek için kullandığımız standart bir yöntemdir. Amacımız saniyeleri ölçmek değil, büyüme oranını anlamaktır.

-   **O(1) - Sabit Zaman (Constant Time):** En iyisi. Girdi ne kadar büyük olursa olsun, işlem süresi hep aynıdır.
    *   *Örnek:* Bir dizinin 3. elemanına erişmek.

-   **O(log n) - Logaritmik Zaman (Logarithmic Time):** Mükemmel. Girdi boyutu iki katına çıktığında, işlem süresi sadece bir birim artar. Genellikle arama uzayını her adımda yarıya indiren algoritmalarda görülür.
    *   *Örnek:* Sıralı bir dizide ikili arama (binary search).

-   **O(n) - Doğrusal Zaman (Linear Time):** İyi. Girdi boyutu ne kadar artarsa, işlem süresi de o oranda artar.
    *   *Örnek:* Bir dizideki tüm elemanların toplamını bulmak.

-   **O(n^2) - Karesel Zaman (Quadratic Time):** Dikkatli olunmalı. Girdi boyutu 10 iken 100 işlem, 100 iken 10.000 işlem gerekir. Genellikle iç içe döngülerde karşımıza çıkar.
    *   *Örnek:* Bir dizideki her elemanı, diğer tüm elemanlarla karşılaştırmak.

## 2. C'de Bellek Yönetimi: Stack ve Heap (Nasıl Çalışır?)

Bir C programı çalıştığında, değişkenler ve veriler için bellek iki ana bölgeden tahsis edilir: **Stack** ve **Heap**.

### a. Stack (Yığın)
Stack, çok düzenli ve hızlı bir bellek alanıdır. Fonksiyon çağrıldığında, o fonksiyona ait lokal değişkenler (`int x;`, `char arr[10];`) ve parametreler için Stack'te bir "çerçeve" (frame) ayrılır. Fonksiyon bittiğinde, bu çerçeve otomatik olarak yok edilir.

-   **Özellikleri:**
    -   Çok hızlı bellek ayırma ve serbest bırakma.
    -   Bellek yönetimi otomatiktir (derleyici tarafından yapılır).
    -   Boyutu sınırlıdır.
    -   LIFO (Son Giren, İlk Çıkar) mantığıyla çalışır.

```c
void myFunction() {
    int a = 5; // Bu 'a' değişkeni STACK'te yaşar.
    // myFunction bittiğinde 'a' için ayrılan bellek otomatik olarak temizlenir.
}
```

### b. Heap (Öbek)
Heap, daha büyük ve esnek bir bellek alanıdır. Boyutunu derleme anında bilmediğimiz veya bir fonksiyondan daha uzun süre yaşamasını istediğimiz veriler için kullanılır.

-   **Özellikleri:**
    -   Stack'e göre daha yavaş bellek ayırma ve serbest bırakma.
    -   **Bellek yönetimi manueldir (programcı tarafından `malloc` ve `free` ile yapılır).**
    -   Boyutu çok daha büyüktür.
    -   Veri yapılarını dinamik olarak oluşturmak için burayı kullanırız!

## 3. Araçlarımız: İşaretçiler (Pointers), `malloc` ve `free`

Heap belleğini yönetmek ve karmaşık veri yapıları oluşturmak için C'de şu araçları kullanırız:

### a. İşaretçiler (Pointers)
Bir işaretçi, başka bir değişkenin **bellek adresini** tutan özel bir değişkendir. Veri yapılarında, bir sonraki düğümü göstermek veya Heap'te ayırdığımız bir bellek bloğunun başlangıcını takip etmek için hayatidirler.

```c
int x = 10;      // 'x' adında bir değişken, değeri 10.
int* ptr = &x;   // 'ptr' adında bir İŞARETÇİ. Değeri, x'in bellek adresi.

printf("x'in degeri: %d\n", x);          // Çıktı: 10
printf("ptr'nin gosterdigi deger: %d\n", *ptr); // Çıktı: 10 (*ptr -> adresteki değeri al)
```

### b. `malloc` ve `free`
Bu fonksiyonlar, Heap belleğini manuel olarak yönetmemizi sağlar.

-   **`malloc(boyut)`:** "Memory Allocation" (Bellek Tahsisi). Heap'ten `boyut` kadar byte'lık bir yer ayırır ve bu alanın başlangıç adresini gösteren bir işaretçi döndürür.
-   **`free(isaretci)`:** `malloc` ile ayrılan bir bellek bloğunu işletim sistemine geri verir. Bu adımı unutmak, **bellek sızıntısına (memory leak)** yol açar ve programın zamanla çok fazla bellek tüketmesine neden olur.

```c
// Heap'te bir integer'lık yer ayır.
int* sayi_ptr = (int*) malloc(sizeof(int));

if (sayi_ptr != NULL) { // malloc bellek bulamazsa NULL döner, her zaman kontrol et!
    *sayi_ptr = 25; // Ayrılan alana 25 değerini yaz.
    printf("Heap'teki sayi: %d\n", *sayi_ptr);
    
    // İşimiz bitti, belleği geri veriyoruz.
    free(sayi_ptr); 
}
```

---

### Özet

Bu hafta öğrendiklerimizle artık C dilinde dinamik olarak bellek yönetebilir, bu belleğe işaretçilerle erişebilir ve oluşturduğumuz yapıların performansını Big O notasyonu ile analiz edebiliriz.
