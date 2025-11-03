# Hafta 1: Dinamik Diziler (Dynamic Arrays)

Bu hafta, generic dinamik dizi veri yapısını C dilinde `void*` kullanarak oluşturacağız. Cuma günü ise modern dillerdeki type-safe eşdeğerlerini göreceğiz: `std::vector`, `ArrayList`, ve Python'un `list` yapısı.

## Hafta Programı

### Pazartesi: C ile Generic Implementation
- `void*` kullanarak generic dinamik dizi implementasyonu
- Memory management ve function pointers
- Manual memory allocation/deallocation

### Cuma: Modern Equivalents
- C++ `std::vector<T>` - type-safe generic collections
- Java `ArrayList<T>` - managed memory with generics
- Python `list` - dynamic typing ile flexible collections

## Öğrenme Hedefleri

1. **Generic Programming**: `void*` ile type-independent veri yapıları
2. **Memory Management**: Manuel bellek yönetimi ve function pointers
3. **Modern Alternatives**: Günümüz dillerindeki dinamik dizi implementasyonları
4. **Performance vs Safety**: Manual control vs automatic management trade-offs

## Dosya Yapısı

```
Hafta-1/
├── 1-C-Generic-Implementation/
│   ├── dynarray.c              # Core generic dynamic array logic
│   └── ex1_generic_demo.c      # Usage examples and demonstrations
└── 2-Modern-Usage/
    ├── demo.cpp                # C++ std::vector example
    ├── Demo.java               # Java ArrayList example
    └── demo.py                 # Python list example
```

## Önemli Konseptler

- **Dynamic Memory Allocation**: `malloc`, `realloc`, `free`
- **Function Pointers**: Generic cleanup ve print functions
- **Type Safety**: C'nin eksiklikleri vs modern dillerin avantajları
- **Memory Ownership**: Kim ne zaman belleği temizler?