# Hafta 1: Dinamik Diziler (Dynamic Arrays)

Bu hafta C dilinde hem integer-özel (`int`) hem de generic (`void*`) dinamik dizi uygulamalarını yapıyoruz. Pazartesi C tarafını (elle bellek yönetimi, function pointer ile cleanup) yapacağız, Cuma ise modern dillerdeki karşılıklarını göreceğiz (`std::vector`, `ArrayList`, `list`).

## Hafta Programı

### Pazartesi: C ile Generic ve Int-Tipinde Implementasyonlar
- `void*` kullanarak generic dinamik dizi implementasyonu
- `int` tipi için daha basit, özel bir dinamik dizi implementasyonu (öğrenme kolaylığı için)
- Memory management ve function pointers

### Cuma: Modern Equivalents
- C++ `std::vector<T>` - type-safe generic collections
- Java `ArrayList<T>` - managed memory with generics
- Python `list` - dynamic typing ile flexible collections

## Öğrenme Hedefleri

1. Generic programming kavramı ve `void*` ile nasıl generic yapı kurulduğu
2. Manuel bellek yönetimi (malloc/realloc/free) ve ownership kararları
3. Function pointer kullanımı (ör. öğe temizleme/deconstructor)
4. Modern dillerdeki güvenlik ve performans farkları

## Mevcut Dosya Yapısı (güncel)

```
Hafta-1/
├── 1-C-Generic-Implementation/
│   ├── int_dynarray.c          # Int-özgü dinamik dizi 
│   ├── int_dynarray_usage.c    # Küçük kullanım/
│   ├── generic_dynarray.c      # Generic dyn array 
│   ├── generic_usage.c         # Generic demo / örnek 
│   └── bigO-example.c          # Küçük yardımcı örnek 
└── 2-Modern-Usage/
    ├── demo.cpp                # C++ std::vector example
    ├── Demo.java               # Java ArrayList example
    └── demo.py                 # Python list example
```