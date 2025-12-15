# Hafta-5: Hash Table - Key-Value Data Structure

## 📚 Bu Hafta Öğreneceklerimiz

Bu hafta **Hash Table (Hash Map/Dictionary)** veri yapısını öğreniyoruz! Hash table, **key-value pairs** ile çalışan ve **O(1) average time complexity** sağlayan temel bir veri yapısıdır.

### 🎯 Öğrenme Hedefleri

1. **Hash Table konseptini anlamak** - Key-value mapping ve hashing
2. **Hash function implementasyonu** - String keys için hash algoritması
3. **Collision handling** - Separate chaining with linked lists
4. **Generic value storage** - `void*` ile type-independent values
5. **Modern hash maps** - Built-in hash table implementations

## 📅 Haftalık Program

### **Pazartesi: C Generic Implementation**
- `struct Node` with `char* key` and `void* value`
- Hash function for string keys
- `insert()`, `search()`, `delete()` operations
- Collision resolution with separate chaining
- Generic value storage with `void*`

### **Cuma: Modern Language Usage**
- **C++**: `std::unordered_map<string, double>` for student GPAs
- **Java**: `java.util.HashMap<Integer, String>` for product catalog
- **Python**: `dict` for word frequency analysis

## 🔄 Hash Table Operations

| Operation | Açıklama | Average Case | Worst Case |
|-----------|----------|--------------|------------|
| `insert(key, value)` | Key-value pair ekle | O(1) | O(n) |
| `search(key)` | Key ile value ara | O(1) | O(n) |
| `delete(key)` | Key-value pair sil | O(1) | O(n) |
| `hash(key)` | Key'i index'e map et | O(k) | O(k) |

*k = key length, n = number of elements*

## 🔧 Hash Table Components

### **Hash Function**
- String keys'i integer index'lere map eder
- Good distribution properties
- djb2 algorithm implementation
- Deterministic ve uniform distribution

### **Collision Resolution**
- **Separate Chaining**: Linked list at each bucket
- **Open Addressing**: Linear/quadratic probing
- Bu hafta: Separate chaining method

### **Load Factor**
- `α = n/m` (n=elements, m=buckets)
- Performance metric for hash table
- Rehashing when load factor > threshold

## 💡 Hash Table Kullanım Alanları

1. **Database Indexing** - Veritabanı hızlı erişim
2. **Caching Systems** - Memory cache implementations
3. **Symbol Tables** - Compiler symbol management
4. **Associative Arrays** - Key-value data storage
5. **Set Implementation** - Unique element storage
6. **Dictionary/Map** - Modern language built-ins

## 🆚 Search Structure Comparison

| Veri Yapısı | Search | Insert | Delete | Memory | Ordered |
|-------------|--------|--------|--------|---------|---------|
| Array | O(n) | O(n) | O(n) | Best | Manual |
| Linked List | O(n) | O(1) | O(n) | Good | Manual |
| Binary Tree | O(log n) | O(log n) | O(log n) | Good | Yes |
| Hash Table | O(1) avg | O(1) avg | O(1) avg | Fair | No |

## 🔍 Hash Function Properties

### **Good Hash Function Characteristics**
1. **Uniform Distribution** - Even spread across buckets
2. **Deterministic** - Same input → same output
3. **Fast Computation** - Efficient to calculate
4. **Avalanche Effect** - Small input change → big output change

### **Common Hash Algorithms**
- **djb2**: `hash = hash * 33 + c`
- **sdbm**: `hash = c + (hash << 6) + (hash << 16) - hash`
- **FNV**: Fowler-Noll-Vo hash function
- **CRC32**: Cyclic redundancy check

## 📁 Dosya Yapısı

```
Hafta-5/
├── README.md (Bu dosya)
├── 1-C-Generic-Implementation/
│   ├── hashtable.c (Core hash table implementation)
│   └── ex1_generic_value_demo.c (Usage examples with main)
└── 2-Modern-Usage/
    ├── demo.cpp (C++ unordered_map example)
    ├── Demo.java (Java HashMap example)
    └── demo.py (Python dict word frequency)
```

## 🎓 Hafta Sonu Değerlendirmesi

### **Temel Kavramlar**
- Hash function design ve implementation
- Collision resolution strategies
- Load factor ve performance impact
- Generic value storage with void*

### **Pratik Uygulamalar**
- Symbol table implementation
- Cache system simulation
- Word frequency analysis
- Student grade management

### **Modern Alternatives**
- Language built-in hash maps
- Type safety improvements
- Automatic memory management
- Rich API and utility methods

## ⚡ Performance Characteristics

### **Time Complexity**
- **Average Case**: O(1) for all operations
- **Worst Case**: O(n) when all keys hash to same bucket
- **Hash Function**: O(k) where k is key length

### **Space Complexity**
- **Storage**: O(n) for n key-value pairs
- **Overhead**: Extra space for buckets and pointers
- **Load Factor**: Affects both time and space

### **Performance Factors**
1. **Hash Function Quality** - Distribution uniformity
2. **Load Factor** - Elements per bucket ratio
3. **Collision Resolution** - Method efficiency
4. **Table Size** - Number of buckets

## 🔄 Hash Table Variations

1. **Separate Chaining** - Linked lists at buckets (bu hafta)
2. **Open Addressing** - Linear/quadratic probing
3. **Robin Hood Hashing** - Minimize variance
4. **Cuckoo Hashing** - Guaranteed O(1) worst case
5. **Consistent Hashing** - Distributed systems

---

**We build a hash table in C with string keys and generic values (`void*`). On Friday, we explore the versatile hash map/dictionary structures that are fundamental to modern programming.**

## 🚀 Sonraki Hafta Preview

Hafta-6'da **Trees** veri yapısını öğreneceğiz ve hierarchical data structures'a geçiş yapacağız!