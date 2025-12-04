# Min Stack

**LeetCode No:** 155

**Level:** Medium

**Link:** https://leetcode.com/problems/min-stack/

## 1. Problem Description

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the `MinStack` class:
- `MinStack()` initializes the stack object.
- `void push(int val)` pushes the element `val` onto the stack.
- `void pop()` removes the element on the top of the stack.
- `int top()` gets the top element of the stack.
- `int getMin()` retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.

## 2. Examples

**Example 1:**
- **Input:** 
  ```
  ["MinStack","push","push","push","getMin","pop","top","getMin"]
  [[],[-2],[0],[-3],[],[],[],[]]
  ```
- **Output:** `[null,null,null,null,-3,null,0,-2]`
- **Explanation:**
  ```
  MinStack minStack = new MinStack();
  minStack.push(-2);    // Stack: [-2]
  minStack.push(0);     // Stack: [-2, 0]
  minStack.push(-3);    // Stack: [-2, 0, -3]
  minStack.getMin();    // Returns -3 (minimum so far)
  minStack.pop();       // Removes -3, Stack: [-2, 0]
  minStack.top();       // Returns 0 (top element)
  minStack.getMin();    // Returns -2 (new minimum after -3 was removed)
  ```

**Example 2:**
- **Input:**
  ```
  ["MinStack","push","push","getMin","pop","getMin"]
  [[],[1],[1],[],[],[]]
  ```
- **Output:** `[null,null,null,1,null,1]`
- **Explanation:**
  ```
  MinStack minStack = new MinStack();
  minStack.push(1);     // Stack: [1]
  minStack.push(1);     // Stack: [1, 1] (duplicate)
  minStack.getMin();    // Returns 1
  minStack.pop();       // Removes 1, Stack: [1]
  minStack.getMin();    // Returns 1 (still valid because of duplicate tracking)
  ```

## 3. Constraints

- -2^31 <= val <= 2^31 - 1
- Methods `pop`, `top` and `getMin` operations will always be called on non-empty stacks.
- At most 3 * 10^4 calls will be made to `push`, `pop`, `top`, and `getMin`.

## 4. Solution Approach (Intuition)

The challenge here is achieving O(1) time complexity for `getMin()`. A naive approach would scan the entire stack to find the minimum, but that's O(n).

The elegant solution uses a **two-stack approach**:
1. **Main Stack (`dataStack`)** - Stores all the elements normally.
2. **Minimum Stack (`minStack`)** - Keeps track of the minimum values at each state of the main stack.

Why do we need a secondary stack?
- When we pop an element, the minimum might change. We need to know what the minimum was *before* that element was pushed.
- The minimum stack maintains a "history" of minimums, synchronized with the main stack.

The algorithm:
1. **Push operation:**
   - Always push the value onto the main stack.
   - Push onto the min stack if:
     - The min stack is empty, OR
     - The value is **less than or equal to** the current minimum (`val <= minStack.top()`)
   - **Important:** We use `<=` (not `<`) to handle duplicate minimum values correctly!

2. **Pop operation:**
   - Pop from the main stack.
   - If the popped value equals the top of the min stack, pop from the min stack too.

3. **Top operation:**
   - Return the top of the main stack.

4. **GetMin operation:**
   - Return the top of the min stack (always the current minimum).

Why `<=` instead of `<`?
- Consider pushing [1, 1]. If we only push when `<`, the min stack would have just [1].
- When we pop the first 1, we'd incorrectly pop from min stack, leaving it empty!
- Using `<=`, the min stack has [1, 1], correctly tracking both instances.

## 5. Code Solutions

### C++ Solution

```cpp
class MinStack {
private:
    stack<int> dataStack;    // Main stack for all elements
    stack<int> minStack;     // Stack to track minimum values
    
public:
    MinStack() {
        // Constructor - stacks are initialized empty by default
    }
    
    void push(int val) {
        // Always push to the main data stack
        dataStack.push(val);
        
        // Push to min stack if it's empty or val is <= current minimum
        // Using <= (not <) to handle duplicate minimum values correctly
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        // If the element being popped is the current minimum,
        // also pop from the min stack
        if (dataStack.top() == minStack.top()) {
            minStack.pop();
        }
        dataStack.pop();
    }
    
    int top() {
        // Return the top element of the main stack
        return dataStack.top();
    }
    
    int getMin() {
        // The top of min stack is always the current minimum
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

### Python Solution

```python
class MinStack:

    def __init__(self):
        # Main stack for all elements
        self.data_stack = []
        # Stack to track minimum values
        self.min_stack = []

    def push(self, val: int) -> None:
        # Always push to the main data stack
        self.data_stack.append(val)
        
        # Push to min stack if it's empty or val is <= current minimum
        # Using <= (not <) to handle duplicate minimum values correctly
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self) -> None:
        # If the element being popped is the current minimum,
        # also pop from the min stack
        if self.data_stack[-1] == self.min_stack[-1]:
            self.min_stack.pop()
        self.data_stack.pop()

    def top(self) -> int:
        # Return the top element of the main stack
        return self.data_stack[-1]

    def getMin(self) -> int:
        # The top of min stack is always the current minimum
        return self.min_stack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
```

## 6. Complexity Analysis

- **Time Complexity:** O(1) for all operations (`push`, `pop`, `top`, `getMin`). Each operation involves only constant-time stack operations (push, pop, or peek).

- **Space Complexity:** O(n) - In the worst case (e.g., a strictly decreasing sequence like [5, 4, 3, 2, 1]), the min stack will store all n elements. On average, the min stack will be smaller than the main stack, but we consider the worst case for complexity analysis.
