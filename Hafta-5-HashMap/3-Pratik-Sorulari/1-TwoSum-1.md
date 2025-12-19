# Two Sum

**LeetCode No:** 1

**Level:** Easy

**Link:** https://leetcode.com/problems/two-sum/

## 1. Problem Description

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have **exactly one solution**, and you may not use the same element twice.

You can return the answer in any order.

## 2. Examples

**Example 1:**
- **Input:** `nums = [2,7,11,15], target = 9`
- **Output:** `[0,1]`
- **Explanation:** Because `nums[0] + nums[1] == 9`, we return `[0, 1]`.

**Example 2:**
- **Input:** `nums = [3,2,4], target = 6`
- **Output:** `[1,2]`

**Example 3:**
- **Input:** `nums = [3,3], target = 6`
- **Output:** `[0,1]`

## 3. Constraints

- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- Only one valid answer exists.

**Follow-up:** Can you come up with an algorithm that is less than `O(n^2)` time complexity?

## 4. Solution Approach (Intuition)

### Brute Force Yaklaşımı
En basit yöntem, her eleman çifti için toplamın `target`'a eşit olup olmadığını kontrol etmektir.
- Time Complexity: O(n²)
- Space Complexity: O(1)

### HashMap Yaklaşımı (Optimal)
HashMap kullanarak tek geçişte çözüm bulabiliriz:

1. **Temel Fikir:**
   - Her eleman için, `target - nums[i]` değerinin daha önce görülüp görülmediğini kontrol et.
   - Eğer görüldüyse, cevabı bulduk!
   - Görülmediyse, mevcut elemanı ve indeksini HashMap'e ekle.

2. **Neden HashMap?**
   - HashMap'te arama O(1) sürede yapılır.
   - Her elemanı sadece bir kez ziyaret ederiz.
   - Toplam zaman karmaşıklığı O(n) olur.

3. **Algoritma:**
   ```
   hashmap = {}
   for i, num in enumerate(nums):
       complement = target - num
       if complement in hashmap:
           return [hashmap[complement], i]
       hashmap[num] = i
   ```

4. **Örnek Üzerinden:**
   ```
   nums = [2, 7, 11, 15], target = 9
   
   i=0: num=2, complement=7, hashmap={} → 7 yok, ekle: {2: 0}
   i=1: num=7, complement=2, hashmap={2: 0} → 2 var! return [0, 1]
   ```

**Complexity Analysis:**
- **Time Complexity:** O(n) - Her elemanı bir kez ziyaret ediyoruz, HashMap lookup O(1).
- **Space Complexity:** O(n) - En kötü durumda tüm elemanları HashMap'te saklıyoruz.

## 5. Solution Templates

### Python
```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in hashmap:
                return [hashmap[complement], i]
            hashmap[num] = i
        return []
```

### C++
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (hashmap.find(complement) != hashmap.end()) {
                return {hashmap[complement], i};
            }
            hashmap[nums[i]] = i;
        }
        return {};
    }
};
```

### Java
```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> hashmap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (hashmap.containsKey(complement)) {
                return new int[] {hashmap.get(complement), i};
            }
            hashmap.put(nums[i], i);
        }
        return new int[] {};
    }
}
```

### C (Generic HashTable Kullanarak)
```c
// Bu çözüm, derste yazdığımız generic hashtable yapısını kullanır
#include "hashtable.c"
#include <stdio.h>

unsigned int int_hash(const void* key) {
    return *(int*)key;
}

int int_compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashTable* ht = ht_create(numsSize * 2, int_hash, int_compare);
    int* result = malloc(2 * sizeof(int));
    *returnSize = 2;
    
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int* found_index = (int*)ht_get(ht, &complement);
        
        if (found_index != NULL) {
            result[0] = *found_index;
            result[1] = i;
            ht_destroy(ht);
            return result;
        }
        
        int* idx = malloc(sizeof(int));
        int* key = malloc(sizeof(int));
        *idx = i;
        *key = nums[i];
        ht_insert(ht, key, idx);
    }
    
    ht_destroy(ht);
    *returnSize = 0;
    free(result);
    return NULL;
}
```
