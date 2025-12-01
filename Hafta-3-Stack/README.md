# Hafta-3: Stack (LIFO) - Last In, First Out

## 📚 Bu Hafta Öğreneceklerimiz

Bu hafta **Stack (Yığın)** veri yapısını öğreniyoruz! Stack, **LIFO (Last In, First Out)** prensibine göre çalışan temel bir veri yapısıdır.

### 🎯 Öğrenme Hedefleri

1. **Stack konseptini anlamak** - LIFO prensibi ve stack operations
2. **Generic C implementation** - `void*` ile type-independent stack
3. **Linked list tabanlı implementasyon** - Dynamic memory kullanımı
4. **Modern dillerde stack kullanımı** - Type-safe, built-in containers

## 📅 Haftalık Program

### **Pazartesi: C Generic Implementation**
- `struct StackNode` ile linked list tabanlı stack
- `push()`, `pop()`, `peek()` operations
- Generic programming with `void*`
- Memory management in stack operations

### **Cuma: Modern Language Usage**
- **C++**: `std::stack<T>` template container
- **Java**: `java.util.Stack<T>` generic class
- **Python**: `list` as stack with balanced parentheses checker

## 🔄 Stack Operations

| Operation | Açıklama | Time Complexity |
|-----------|----------|-----------------|
| `push(item)` | Yeni eleman ekle (top'a) | O(1) |
| `pop()` | En üstteki elemanı çıkar | O(1) |
| `peek()/top()` | En üstteki elemanı göster | O(1) |
| `isEmpty()` | Stack boş mu kontrol et | O(1) |
| `size()` | Eleman sayısını ver | O(n) |

## 💡 Stack Kullanım Alanları

1. **Function Call Stack** - Program çağrı yığını
2. **Expression Evaluation** - Matematiksel ifade hesaplama
3. **Balanced Parentheses** - Parantez kontrolü
4. **Undo Operations** - Geri alma işlemleri
5. **Browser History** - Tarayıcı geçmişi
6. **Compiler Operations** - Syntax parsing

## 🆚 Array vs Linked List Implementation

| Özellik | Array Stack | Linked List Stack |
|---------|-------------|-------------------|
| Memory | Contiguous, fixed size | Scattered, dynamic |
| Performance | Better cache locality | O(1) for all ops |
| Memory Usage | Pre-allocated space | Only needed space |
| Implementation | Simple index ops | Pointer manipulation |

## 🔧 Bu Hafta Öğrenecek Teknikler

### **C Programming Concepts**
- Linked list based data structures
- Generic programming with `void*`
- Function pointers for callbacks
- Manual memory management
- Stack pointer (`top`) manipulation

### **Modern Language Features**
- **C++**: STL containers and templates
- **Java**: Generics and Collections framework
- **Python**: List methods and stack idioms

## 📁 Dosya Yapısı

```
Hafta-3/
├── README.md (Bu dosya)
├── 1-C-Generic-Implementation/
│   ├── stack.c (Core stack implementation)
│   └── demo.c (Usage examples with main)
└── 2-Modern-Usage/
    ├── demo.cpp (C++ std::stack example)
    ├── Demo.java (Java Stack example)
    └── demo.py (Python list as stack)
```

## 🎓 Değerlendirme Kriterleri

1. **LIFO prensibini anlama** - Stack'in temel çalışma prensibi
2. **Generic implementation** - `void*` kullanarak type-independent kod
3. **Memory management** - Stack operations'da malloc/free kullanımı
4. **Modern alternatives** - Built-in stack containers'ı kullanabilme

---

**We implement a generic Stack in C. We'll learn how `void*` allows us to push and pop any data type. Friday's lesson focuses on the convenient, type-safe stack containers in modern languages.**

## 🚀 Sonraki Hafta Preview

Hafta-4'te **Queue (FIFO)** veri yapısını öğreneceğiz ve Stack ile karşılaştırma yapacağız!