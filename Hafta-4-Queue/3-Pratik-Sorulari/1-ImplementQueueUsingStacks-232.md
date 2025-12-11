# Implement Queue using Stacks

**LeetCode No:** 232

**Level:** Easy

**Link:** https://leetcode.com/problems/implement-queue-using-stacks/

## 1. Problem Description

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (`push`, `peek`, `pop`, and `empty`).

Implement the `MyQueue` class:
- `void push(int x)` Pushes element x to the back of the queue.
- `int pop()` Removes the element from the front of the queue and returns it.
- `int peek()` Returns the element at the front of the queue.
- `boolean empty()` Returns `true` if the queue is empty, `false` otherwise.

**Notes:**
- You must use **only** standard operations of a stack, which means only `push to top`, `peek/pop from top`, `size`, and `is empty` operations are valid.
- Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

## 2. Examples

**Example 1:**
- **Input:** 
  ```
  ["MyQueue", "push", "push", "peek", "pop", "empty"]
  [[], [1], [2], [], [], []]
  ```
- **Output:** `[null, null, null, 1, 1, false]`
- **Explanation:**
  ```
  MyQueue myQueue = new MyQueue();
  myQueue.push(1);    // queue is: [1]
  myQueue.push(2);    // queue is: [1, 2] (leftmost is front of the queue)
  myQueue.peek();     // return 1
  myQueue.pop();      // return 1, queue is [2]
  myQueue.empty();    // return false
  ```

**Example 2:**
- **Input:**
  ```
  ["MyQueue", "push", "push", "push", "pop", "pop", "empty"]
  [[], [1], [2], [3], [], [], []]
  ```
- **Output:** `[null, null, null, null, 1, 2, false]`
- **Explanation:**
  ```
  MyQueue myQueue = new MyQueue();
  myQueue.push(1);    // queue is: [1]
  myQueue.push(2);    // queue is: [1, 2]
  myQueue.push(3);    // queue is: [1, 2, 3]
  myQueue.pop();      // return 1, queue is [2, 3]
  myQueue.pop();      // return 2, queue is [3]
  myQueue.empty();    // return false
  ```

## 3. Constraints

- 1 <= x <= 9
- At most 100 calls will be made to `push`, `pop`, `peek`, and `empty`.
- All the calls to `pop` and `peek` are valid.

**Follow-up:** Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.

## 4. Solution Approach (Intuition)

The challenge is that stacks are LIFO (Last In, First Out), but queues are FIFO (First In, First Out). We need to reverse the order somehow.

The elegant solution uses a **two-stack approach**:
1. **Input Stack (`inputStack`)** - Used for push operations. New elements go here.
2. **Output Stack (`outputStack`)** - Used for pop/peek operations. Elements are in reversed order here.

Why does this work?
- When we push elements onto the input stack, they're in reverse order of insertion.
- When we transfer them to the output stack, they get reversed again, putting them in the correct FIFO order!
- We only transfer when the output stack is empty, which gives us amortized O(1) complexity.

The algorithm:

1. **Push operation:**
   - Simply push the element onto the input stack.
   - Time: O(1)

2. **Pop operation:**
   - If the output stack is empty, transfer ALL elements from input stack to output stack.
   - Pop and return the top element from the output stack.
   - Time: Amortized O(1)

3. **Peek operation:**
   - If the output stack is empty, transfer ALL elements from input stack to output stack.
   - Return the top element of the output stack (without removing it).
   - Time: Amortized O(1)

4. **Empty operation:**
   - Return true if BOTH stacks are empty.
   - Time: O(1)

Why is it amortized O(1)?
- Each element is moved at most twice: once to input stack, once to output stack.
- So for n operations, we do at most 2n moves total.
- This gives us O(2n)/n = O(1) amortized time per operation.

Visual Example:
```
Push 1, 2, 3:
  inputStack: [1, 2, 3] (top is 3)
  outputStack: []

Pop (transfer happens):
  inputStack: []
  outputStack: [3, 2, 1] (top is 1) -> pop returns 1
  outputStack: [3, 2]

Push 4:
  inputStack: [4]
  outputStack: [3, 2]

Pop:
  outputStack: [3, 2] -> pop returns 2
  outputStack: [3]
```

## 5. Code Solutions

### C++ Solution

```cpp
class MyQueue {
private:
    stack<int> inputStack;   // Stack for push operations
    stack<int> outputStack;  // Stack for pop/peek operations
    
    // Helper function to transfer elements from input to output
    void transferIfNeeded() {
        if (outputStack.empty()) {
            // Move all elements from input to output
            // This reverses the order, giving us FIFO behavior
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }
    
public:
    MyQueue() {
        // Constructor - stacks are initialized empty by default
    }
    
    void push(int x) {
        // Always push to the input stack
        inputStack.push(x);
    }
    
    int pop() {
        // Ensure output stack has elements
        transferIfNeeded();
        // Pop from output stack (front of queue)
        int front = outputStack.top();
        outputStack.pop();
        return front;
    }
    
    int peek() {
        // Ensure output stack has elements
        transferIfNeeded();
        // Return top of output stack (front of queue)
        return outputStack.top();
    }
    
    bool empty() {
        // Queue is empty only if both stacks are empty
        return inputStack.empty() && outputStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```

### Python Solution

```python
class MyQueue:

    def __init__(self):
        # Stack for push operations
        self.input_stack = []
        # Stack for pop/peek operations
        self.output_stack = []

    def _transfer_if_needed(self):
        """Helper function to transfer elements from input to output."""
        if not self.output_stack:
            # Move all elements from input to output
            # This reverses the order, giving us FIFO behavior
            while self.input_stack:
                self.output_stack.append(self.input_stack.pop())

    def push(self, x: int) -> None:
        # Always push to the input stack
        self.input_stack.append(x)

    def pop(self) -> int:
        # Ensure output stack has elements
        self._transfer_if_needed()
        # Pop from output stack (front of queue)
        return self.output_stack.pop()

    def peek(self) -> int:
        # Ensure output stack has elements
        self._transfer_if_needed()
        # Return top of output stack (front of queue)
        return self.output_stack[-1]

    def empty(self) -> bool:
        # Queue is empty only if both stacks are empty
        return not self.input_stack and not self.output_stack


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
```

## 6. Complexity Analysis

- **Time Complexity:**
  - `push`: O(1) - Simply pushing to a stack.
  - `pop`: Amortized O(1) - Each element is moved at most twice (once to input, once to output).
  - `peek`: Amortized O(1) - Same reasoning as pop.
  - `empty`: O(1) - Just checking if two stacks are empty.

- **Space Complexity:** O(n) - Where n is the number of elements in the queue. We store all elements across the two stacks. In the worst case, all elements could be in one stack.
