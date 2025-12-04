# Valid Parentheses

**LeetCode No:** 20

**Level:** Easy

**Link:** https://leetcode.com/problems/valid-parentheses/

## 1. Problem Description

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

## 2. Examples

**Example 1:**
- **Input:** s = "()"
- **Output:** true
- **Explanation:** The opening parenthesis `(` is immediately followed by its matching closing parenthesis `)`.

**Example 2:**
- **Input:** s = "()[]{}"
- **Output:** true
- **Explanation:** Each type of bracket is properly opened and closed in the correct order.

**Example 3:**
- **Input:** s = "(]"
- **Output:** false
- **Explanation:** The opening parenthesis `(` is closed by a square bracket `]`, which is not a matching pair.

## 3. Constraints

- 1 <= s.length <= 10^4
- `s` consists of parentheses only `'()[]{}'`

## 4. Solution Approach (Intuition)

This problem is a classic application of the **Stack** data structure, leveraging its LIFO (Last In, First Out) property.

The key insight is:
1. When we encounter an **opening bracket** (`(`, `{`, `[`), we push it onto the stack.
2. When we encounter a **closing bracket** (`)`, `}`, `]`), we check if it matches the most recent opening bracket (top of the stack).

Why does a stack work perfectly here?
- The most recently opened bracket must be closed first - this is exactly what LIFO provides!
- We use a **mapping** (hash map/dictionary) to associate each closing bracket with its corresponding opening bracket for quick lookup.

The algorithm:
1. Create a mapping of closing brackets to their corresponding opening brackets.
2. Iterate through each character in the string:
   - If it's an opening bracket, push it onto the stack.
   - If it's a closing bracket:
     - Check if the stack is empty (no matching opening bracket) → invalid.
     - Check if the top of the stack matches the expected opening bracket → if not, invalid.
     - If it matches, pop the top element from the stack.
3. After processing all characters, the stack should be empty for a valid string.

## 5. Code Solutions

### C++ Solution

```cpp
class Solution {
public:
    bool isValid(string s) {
        // Stack to keep track of opening brackets
        stack<char> st;
        
        // Mapping of closing brackets to their corresponding opening brackets
        unordered_map<char, char> bracketMap = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        
        // Iterate through each character in the string
        for (char c : s) {
            // Check if current character is a closing bracket
            if (bracketMap.find(c) != bracketMap.end()) {
                // If stack is empty or top doesn't match, invalid
                if (st.empty() || st.top() != bracketMap[c]) {
                    return false;
                }
                // Pop the matching opening bracket
                st.pop();
            } else {
                // It's an opening bracket, push onto stack
                st.push(c);
            }
        }
        
        // Valid only if all brackets are matched (stack is empty)
        return st.empty();
    }
};
```

### Python Solution

```python
class Solution:
    def isValid(self, s: str) -> bool:
        # Stack to keep track of opening brackets
        stack = []
        
        # Mapping of closing brackets to their corresponding opening brackets
        bracket_map = {
            ')': '(',
            '}': '{',
            ']': '['
        }
        
        # Iterate through each character in the string
        for char in s:
            # Check if current character is a closing bracket
            if char in bracket_map:
                # If stack is empty or top doesn't match, invalid
                if not stack or stack[-1] != bracket_map[char]:
                    return False
                # Pop the matching opening bracket
                stack.pop()
            else:
                # It's an opening bracket, push onto stack
                stack.append(char)
        
        # Valid only if all brackets are matched (stack is empty)
        return len(stack) == 0
```

## 6. Complexity Analysis

- **Time Complexity:** O(n) - We traverse the string once, where n is the length of the string. Each push and pop operation on the stack takes O(1) time, and hash map lookups are O(1) on average.

- **Space Complexity:** O(n) - In the worst case, all characters could be opening brackets, so the stack could grow up to size n. The hash map uses constant space O(1) as it always contains exactly 3 mappings.
