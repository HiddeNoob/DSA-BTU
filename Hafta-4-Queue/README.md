# Hafta-4: Queue (FIFO) - First In, First Out

## 📚 Bu Hafta Öğreneceklerimiz

Bu hafta **Queue (Kuyruk)** veri yapısını öğreniyoruz! Queue, **FIFO (First In, First Out)** prensibine göre çalışan temel bir veri yapısıdır.

### 🎯 Öğrenme Hedefleri

1. **Queue konseptini anlamak** - FIFO prensibi ve queue operations
2. **Generic C implementation** - `void*` ile type-independent queue
3. **Linked list tabanlı implementasyon** - Dynamic memory ile front/rear pointers
4. **Modern dillerde queue kullanımı** - Real-world scenarios simulation

## 📅 Haftalık Program

### **Pazartesi: C Generic Implementation**
- `struct Node` ve `struct Queue` with front/rear pointers
- `enqueue()`, `dequeue()`, queue management operations
- Generic programming with `void*` data handling
- Memory management in queue operations

### **Cuma: Modern Language Usage**
- **C++**: `std::queue<int>` template container
- **Java**: `java.util.Queue<String>` interface with LinkedList
- **Python**: `collections.deque` for printer simulation

## 🔄 Queue Operations

| Operation | Açıklama | Time Complexity |
|-----------|----------|-----------------|
| `enqueue(item)` | Yeni eleman ekle (rear'a) | O(1) |
| `dequeue()` | En öndeki elemanı çıkar | O(1) |
| `front()/peek()` | En öndeki elemanı göster | O(1) |
| `isEmpty()` | Queue boş mu kontrol et | O(1) |
| `size()` | Eleman sayısını ver | O(n) |

## 🆚 Stack vs Queue Comparison

| Özellik | Stack (LIFO) | Queue (FIFO) |
|---------|--------------|--------------|
| Insert | Push to top | Enqueue to rear |
| Remove | Pop from top | Dequeue from front |
| Access | Top element | Front element |
| Order | Last In, First Out | First In, First Out |
| Use Case | Function calls, undo | Task scheduling, buffering |

## 💡 Queue Kullanım Alanları

1. **Task Scheduling** - İşletim sistemi görev kuyruğu
2. **Printer Queue** - Yazdırma işleri sırası
3. **BFS Algorithm** - Breadth-First Search
4. **Buffer Management** - IO operations buffering
5. **Web Server Requests** - HTTP request handling
6. **CPU Scheduling** - Process scheduling algorithms

## 🔧 Implementation Approaches

### **Array-based Queue**
- Fixed size, circular buffer
- Better cache locality
- Index management (front/rear indices)

### **Linked List Queue (Bu hafta)**
- Dynamic size, unlimited capacity
- Two pointers: front (dequeue) and rear (enqueue)
- O(1) operations at both ends

## 📁 Dosya Yapısı

```
Hafta-4/
├── README.md (Bu dosya)
├── 1-C-Generic-Implementation/
│   ├── queue.c (Core queue implementation)
│   └── demo.c (Usage examples with main)
└── 2-Modern-Usage/
    ├── demo.cpp (C++ std::queue example)
    ├── Demo.java (Java Queue interface example)
    └── demo.py (Python deque printer simulation)
```

## 🎓 Hafta Sonu Değerlendirmesi

### **Temel Kavramlar**
- FIFO prensibi ve queue operations
- Front/rear pointer management
- Generic programming with `void*`
- Memory management in dynamic structures

### **Pratik Uygulamalar**
- Task scheduling simulation
- Buffer management concepts
- Real-world queue scenarios
- Modern language queue containers

### **Karşılaştırmalı Analiz**
- Stack vs Queue behavioral differences
- Array vs Linked List implementations
- C manual management vs modern automatic handling

## 🔄 Queue Variations

1. **Simple Queue** - Basic FIFO implementation
2. **Circular Queue** - Array-based with wraparound
3. **Priority Queue** - Elements with priorities
4. **Deque** - Double-ended queue (both ends)

## ⚡ Performance Characteristics

| Aspect | Linked List Queue | Array Queue |
|--------|-------------------|-------------|
| Enqueue | O(1) | O(1) |
| Dequeue | O(1) | O(1) |
| Space | Dynamic | Fixed/Circular |
| Cache | Poor locality | Good locality |
| Memory | Node overhead | Contiguous |

---

**This week's focus is a generic Queue in C, handling any data type via `void*`. On Friday, we will simulate real-world scenarios using the powerful queue libraries in C++, Java, and Python.**

## 🚀 Sonraki Hafta Preview

Hafta-5'te **Trees** veri yapısını öğreneceğiz ve linear olmayan strukturlara geçiş yapacağız!