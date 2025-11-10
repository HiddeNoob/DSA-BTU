# Hafta 2: Tekli Bağlı Listeler (Singly Linked Lists)

Bu hafta generic tekli bağlı liste veri yapısını C dilinde `void*` kullanarak oluşturacağız. **Hafta-1'deki DynArray API'sine benzer fonksiyon isimleri** kullanarak iki veri yapısı arasındaki farkları net göreceğiz. Function pointer'lar ile generic operations yapacağız.

## Hafta Programı

### Pazartesi: C ile Generic Implementation
- DynArray API'sine benzer fonksiyon isimleri (`createArray`, `append`, `get`, `removeAt`)
- `void*` kullanarak generic linked list
- Function pointers ile generic operations (destructor, print)
- Performance farkları (O(1) vs O(n) operations)

### Cuma: Modern Built-in Implementations
- C++ `std::list<T>` - doubly-linked, STL integrated
- Java `LinkedList<T>` - generic collections framework  
- Python `collections.deque` - flexible double-ended queue

## Öğrenme Hedefleri

1. **API Comparison**: DynArray ile LinkedList arasındaki API benzerliği ve performance farkları
2. **Linked List Fundamentals**: Node structure, pointer connections ve traversal
3. **Generic Programming**: `void*` ile type-independent data structures
4. **Function Pointers**: Destructor, print, compare fonksiyonları ile generic operations
5. **Memory Management**: Node-based dynamic allocation ve proper cleanup

## Mevcut Dosya Yapısı

```
Hafta-2/
├── 1-C-Generic-Implementation/
│   ├── generic_linkedlist.c    # Generic LinkedList implementation (sınıfta doldurulacak)
│   └── linkedlist_usage.c      # Basit Person struct kullanım örneği
└── 2-Modern-Usage/
    ├── demo.cpp                # C++ std::list example
    ├── Demo.java               # Java LinkedList example  
    └── demo.py                 # Python deque example
```

## Performance Karşılaştırması: DynArray vs LinkedList

| İşlem | DynArray | LinkedList | Kazanan |
|-------|----------|------------|---------|
| **append()** | O(1) amortized (sona) | O(1) (başa) | 🤝 Berabere |
| **get(index)** | O(1) direct access | O(n) traversal | 🏆 DynArray |
| **removeAt(index)** | O(n) shift elements | O(n) find + O(1) unlink | 🤝 Berabere |
| **insertAt(0)** | O(n) shift all | O(1) head insert | 🏆 LinkedList |

### Memory & Cache Karşılaştırması

| Özellik | DynArray | LinkedList |
|---------|----------|------------|
| **Memory Layout** | Bitişik (contiguous) | Dağınık (scattered) |
| **Cache Locality** | 🟢 Excellent | 🔴 Poor |
| **Memory Overhead** | 🟢 Düşük | 🔴 Yüksek (pointer'lar) |
| **Reallocation Cost** | 🔴 Pahalı (büyük kopyalama) | 🟢 Yok |
| **Dynamic Growth** | 🔴 Kısıtlı (capacity) | 🟢 Sınırsız |

### Hangi Durumda Hangisi?

**DynArray Kullan:**
- ✅ Çok fazla `get()` işlemi
- ✅ Sequential access pattern
- ✅ Memory efficient olmalı
- ✅ Cache performance önemli

**LinkedList Kullan:**
- ✅ Çok fazla başa insert (O(1))
- ✅ Boyut önceden bilinmiyor
- ✅ Frequent insertion/deletion at head
- ✅ Memory fragmentation sorun değil
- ✅ Reallocation cost'u olmadan büyümeli
