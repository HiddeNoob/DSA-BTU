# Valid Anagram

**LeetCode No:** 242

**Level:** Easy

**Link:** https://leetcode.com/problems/valid-anagram/

## 1. Problem Description

Given two strings `s` and `t`, return `true` if `t` is an **anagram** of `s`, and `false` otherwise.

**Anagram Nedir?**
Bir anagram, başka bir kelimenin veya ifadenin harflerini yeniden düzenleyerek oluşturulan kelime veya ifadedir. Örneğin, "listen" ve "silent" birbirinin anagramıdır.

## 2. Examples

**Example 1:**
- **Input:** `s = "anagram", t = "nagaram"`
- **Output:** `true`
- **Explanation:** "nagaram" kelimesi "anagram" kelimesinin harflerini yeniden düzenleyerek elde edilebilir.

**Example 2:**
- **Input:** `s = "rat", t = "car"`
- **Output:** `false`
- **Explanation:** "rat" ve "car" farklı harfler içerir ('t' vs 'c').

## 3. Constraints

- `1 <= s.length, t.length <= 5 * 10^4`
- `s` and `t` consist of lowercase English letters.

**Follow-up:** What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

## 4. Solution Approach (Intuition)

### Yaklaşım 1: Sorting (Sıralama)
İki string'i sıralayıp karşılaştırabiliriz. Anagram iseler, sıralanmış halleri aynı olacaktır.
- Time Complexity: O(n log n)
- Space Complexity: O(n) veya O(1) - sorting algoritmasına bağlı

### Yaklaşım 2: HashMap / Frequency Count (Optimal)
Her karakterin kaç kez geçtiğini sayıp karşılaştırabiliriz.

1. **Temel Fikir:**
   - İki string anagram ise, her karakterin frekansı aynı olmalıdır.
   - HashMap kullanarak karakter frekanslarını sayabiliriz.

2. **İki HashMap Yaklaşımı:**
   - Her iki string için ayrı HashMap oluştur.
   - HashMap'leri karşılaştır.

3. **Tek HashMap Yaklaşımı (Daha Verimli):**
   - İlk string için karakterleri say (artır).
   - İkinci string için karakterleri azalt.
   - Sonunda tüm değerler 0 olmalı.

4. **Array Yaklaşımı (En Verimli - Sadece lowercase için):**
   - Sadece 26 küçük harf olduğundan, 26 elemanlı bir array yeterli.
   - Array index: `char - 'a'`

**Örnek Üzerinden:**
```
s = "anagram", t = "nagaram"

Frekans sayımı:
s: {a: 3, n: 1, g: 1, r: 1, m: 1}
t: {n: 1, a: 3, g: 1, r: 1, m: 1}

İkisi eşit → true
```

**Complexity Analysis:**
- **Time Complexity:** O(n) - Her karakteri bir kez ziyaret ediyoruz.
- **Space Complexity:** O(1) - Sabit boyutlu array (26 karakter) veya O(k) HashMap için (k = unique karakter sayısı).

## 5. Solution Templates

### Python
```python
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        count = {}
        
        for char in s:
            count[char] = count.get(char, 0) + 1
        
        for char in t:
            if char not in count:
                return False
            count[char] -= 1
            if count[char] < 0:
                return False
        
        return True
```

**Alternatif (Counter kullanarak):**
```python
from collections import Counter

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)
```

### C++
```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        // Array yaklaşımı (26 lowercase letter)
        int count[26] = {0};
        
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};
```

**Alternatif (unordered_map kullanarak - Unicode desteği için):**
```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, int> count;
        
        for (char c : s) {
            count[c]++;
        }
        
        for (char c : t) {
            if (count.find(c) == count.end() || count[c] == 0) {
                return false;
            }
            count[c]--;
        }
        
        return true;
    }
};
```

### Java
```java
class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        int[] count = new int[26];
        
        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'a']++;
            count[t.charAt(i) - 'a']--;
        }
        
        for (int c : count) {
            if (c != 0) {
                return false;
            }
        }
        
        return true;
    }
}
```

**Alternatif (HashMap kullanarak - Unicode desteği için):**
```java
class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        Map<Character, Integer> count = new HashMap<>();
        
        for (char c : s.toCharArray()) {
            count.put(c, count.getOrDefault(c, 0) + 1);
        }
        
        for (char c : t.toCharArray()) {
            if (!count.containsKey(c) || count.get(c) == 0) {
                return false;
            }
            count.put(c, count.get(c) - 1);
        }
        
        return true;
    }
}
```

### C (Generic HashTable Kullanarak)
```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Basit array yaklaşımı (sadece lowercase için)
bool isAnagram(char* s, char* t) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    
    if (len_s != len_t) {
        return false;
    }
    
    int count[26] = {0};
    
    for (int i = 0; i < len_s; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    
    return true;
}
```

**Generic HashTable Kullanarak (Unicode desteği için):**
```c
#include "hashtable.c"
#include <string.h>
#include <stdbool.h>

unsigned int char_hash(const void* key) {
    return *(char*)key;
}

int char_compare(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

bool isAnagram(char* s, char* t) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    
    if (len_s != len_t) {
        return false;
    }
    
    HashTable* ht = ht_create(128, char_hash, char_compare);
    
    // s'deki karakterleri say
    for (int i = 0; i < len_s; i++) {
        char* key = malloc(sizeof(char));
        *key = s[i];
        int* count = (int*)ht_get(ht, key);
        
        if (count == NULL) {
            int* new_count = malloc(sizeof(int));
            *new_count = 1;
            ht_insert(ht, key, new_count);
        } else {
            (*count)++;
            free(key);
        }
    }
    
    // t'deki karakterleri kontrol et ve azalt
    for (int i = 0; i < len_t; i++) {
        int* count = (int*)ht_get(ht, &t[i]);
        
        if (count == NULL || *count == 0) {
            ht_destroy(ht);
            return false;
        }
        (*count)--;
    }
    
    ht_destroy(ht);
    return true;
}
```

## 6. Follow-up: Unicode Karakterleri

Eğer girdiler Unicode karakterler içeriyorsa:
- **Array yaklaşımı çalışmaz** çünkü Unicode'da milyonlarca karakter var.
- **HashMap yaklaşımı kullanılmalı** çünkü sadece kullanılan karakterleri saklar.
- Karakter tipi olarak `wchar_t` (C/C++) veya uygun Unicode string tipleri kullanılmalı.
