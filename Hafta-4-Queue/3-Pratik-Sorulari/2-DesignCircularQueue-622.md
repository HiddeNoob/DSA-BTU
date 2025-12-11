# Design Circular Queue

**LeetCode No:** 622

**Level:** Medium

**Link:** https://leetcode.com/problems/design-circular-queue/

## 1. Problem Description

Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle, and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implement the `MyCircularQueue` class:
- `MyCircularQueue(k)` Initializes the object with the size of the queue to be `k`.
- `int Front()` Gets the front item from the queue. If the queue is empty, return `-1`.
- `int Rear()` Gets the last item from the queue. If the queue is empty, return `-1`.
- `boolean enQueue(int value)` Inserts an element into the circular queue. Return `true` if the operation is successful.
- `boolean deQueue()` Deletes an element from the circular queue. Return `true` if the operation is successful.
- `boolean isEmpty()` Checks whether the circular queue is empty or not.
- `boolean isFull()` Checks whether the circular queue is full or not.

You must solve the problem without using the built-in queue data structure in your programming language.

## 2. Examples

**Example 1:**
- **Input:** 
  ```
  ["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
  [[3], [1], [2], [3], [4], [], [], [], [4], []]
  ```
- **Output:** `[null, true, true, true, false, 3, true, true, true, 4]`
- **Explanation:**
  ```
  MyCircularQueue myCircularQueue = new MyCircularQueue(3);
  myCircularQueue.enQueue(1);  // return True, queue is [1]
  myCircularQueue.enQueue(2);  // return True, queue is [1, 2]
  myCircularQueue.enQueue(3);  // return True, queue is [1, 2, 3]
  myCircularQueue.enQueue(4);  // return False, queue is full
  myCircularQueue.Rear();      // return 3, last element
  myCircularQueue.isFull();    // return True
  myCircularQueue.deQueue();   // return True, queue is [2, 3]
  myCircularQueue.enQueue(4);  // return True, queue is [2, 3, 4]
  myCircularQueue.Rear();      // return 4, new last element
  ```

**Example 2:**
- **Input:**
  ```
  ["MyCircularQueue", "enQueue", "deQueue", "Front", "deQueue", "Front", "Rear", "enQueue", "isFull", "deQueue", "Rear", "enQueue"]
  [[3], [2], [], [], [], [], [], [4], [], [], [], [2]]
  ```
- **Output:** `[null, true, true, -1, false, -1, -1, true, false, true, -1, true]`
- **Explanation:**
  ```
  MyCircularQueue myCircularQueue = new MyCircularQueue(3);
  myCircularQueue.enQueue(2);  // return True, queue is [2]
  myCircularQueue.deQueue();   // return True, queue is []
  myCircularQueue.Front();     // return -1, queue is empty
  myCircularQueue.deQueue();   // return False, queue is already empty
  myCircularQueue.Front();     // return -1, queue is empty
  myCircularQueue.Rear();      // return -1, queue is empty
  myCircularQueue.enQueue(4);  // return True, queue is [4]
  myCircularQueue.isFull();    // return False, queue has 1 element, capacity is 3
  myCircularQueue.deQueue();   // return True, queue is []
  myCircularQueue.Rear();      // return -1, queue is empty
  myCircularQueue.enQueue(2);  // return True, queue is [2]
  ```

## 3. Constraints

- 1 <= k <= 1000
- 0 <= value <= 1000
- At most 3000 calls will be made to `enQueue`, `deQueue`, `Front`, `Rear`, `isEmpty`, and `isFull`.

## 4. Solution Approach (Intuition)

The key insight is using an array with **two pointers** and the **modulo operator** to create circular behavior.

Why circular?
- In a regular array-based queue, after several enqueue/dequeue operations, the front pointer moves forward, leaving "wasted" space at the beginning.
- A circular queue wraps around, reusing that space efficiently.

The solution uses:
1. **Fixed-size array** - To store the queue elements.
2. **Front pointer (`front`)** - Points to the first element.
3. **Rear pointer (`rear`)** - Points to the last element.
4. **Count variable (`count`)** - Tracks the number of elements (simplifies empty/full checks).

The magic of modulo:
- `(index + 1) % capacity` wraps the index back to 0 when it reaches the end.
- This creates the "circular" effect without actually having a circular data structure.

The algorithm:

1. **Constructor:**
   - Initialize an array of size k.
   - Set `front = 0`, `rear = -1`, `count = 0`.

2. **enQueue operation:**
   - If full, return false.
   - Move rear forward: `rear = (rear + 1) % capacity`
   - Store the value at the new rear position.
   - Increment count.
   - Return true.

3. **deQueue operation:**
   - If empty, return false.
   - Move front forward: `front = (front + 1) % capacity`
   - Decrement count.
   - Return true.

4. **Front operation:**
   - If empty, return -1.
   - Return the element at the front index.

5. **Rear operation:**
   - If empty, return -1.
   - Return the element at the rear index.

6. **isEmpty operation:**
   - Return `count == 0`.

7. **isFull operation:**
   - Return `count == capacity`.

Visual Example (capacity = 3):
```
Initial:      [_, _, _]  front=0, rear=-1, count=0

enQueue(1):   [1, _, _]  front=0, rear=0, count=1
enQueue(2):   [1, 2, _]  front=0, rear=1, count=2
enQueue(3):   [1, 2, 3]  front=0, rear=2, count=3 (FULL)

deQueue():    [_, 2, 3]  front=1, rear=2, count=2
deQueue():    [_, _, 3]  front=2, rear=2, count=1

enQueue(4):   [4, _, 3]  front=2, rear=0, count=2  <- Wraps around!
enQueue(5):   [4, 5, 3]  front=2, rear=1, count=3 (FULL)
```

Alternative approach without count:
- You can use `front` and `rear` pointers only, but you need to leave one slot empty to distinguish between full and empty states.
- This uses `(rear + 1) % capacity == front` for full check.
- Using a count variable is cleaner and doesn't waste a slot.

## 5. Code Solutions

### C++ Solution

```cpp
class MyCircularQueue {
private:
    vector<int> data;    // Array to store queue elements
    int front;           // Index of the front element
    int rear;            // Index of the rear element
    int count;           // Current number of elements
    int capacity;        // Maximum capacity of the queue
    
public:
    MyCircularQueue(int k) {
        data.resize(k);
        capacity = k;
        front = 0;
        rear = -1;
        count = 0;
    }
    
    bool enQueue(int value) {
        // Cannot insert if queue is full
        if (isFull()) {
            return false;
        }
        
        // Move rear forward with wrap-around using modulo
        rear = (rear + 1) % capacity;
        // Store the value at the new rear position
        data[rear] = value;
        // Increment element count
        count++;
        
        return true;
    }
    
    bool deQueue() {
        // Cannot delete if queue is empty
        if (isEmpty()) {
            return false;
        }
        
        // Move front forward with wrap-around using modulo
        front = (front + 1) % capacity;
        // Decrement element count
        count--;
        
        return true;
    }
    
    int Front() {
        // Return -1 if queue is empty
        if (isEmpty()) {
            return -1;
        }
        // Return the element at front index
        return data[front];
    }
    
    int Rear() {
        // Return -1 if queue is empty
        if (isEmpty()) {
            return -1;
        }
        // Return the element at rear index
        return data[rear];
    }
    
    bool isEmpty() {
        // Queue is empty when count is 0
        return count == 0;
    }
    
    bool isFull() {
        // Queue is full when count equals capacity
        return count == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
```

### Python Solution

```python
class MyCircularQueue:

    def __init__(self, k: int):
        # Array to store queue elements
        self.data = [0] * k
        # Maximum capacity of the queue
        self.capacity = k
        # Index of the front element
        self.front = 0
        # Index of the rear element
        self.rear = -1
        # Current number of elements
        self.count = 0

    def enQueue(self, value: int) -> bool:
        # Cannot insert if queue is full
        if self.isFull():
            return False
        
        # Move rear forward with wrap-around using modulo
        self.rear = (self.rear + 1) % self.capacity
        # Store the value at the new rear position
        self.data[self.rear] = value
        # Increment element count
        self.count += 1
        
        return True

    def deQueue(self) -> bool:
        # Cannot delete if queue is empty
        if self.isEmpty():
            return False
        
        # Move front forward with wrap-around using modulo
        self.front = (self.front + 1) % self.capacity
        # Decrement element count
        self.count -= 1
        
        return True

    def Front(self) -> int:
        # Return -1 if queue is empty
        if self.isEmpty():
            return -1
        # Return the element at front index
        return self.data[self.front]

    def Rear(self) -> int:
        # Return -1 if queue is empty
        if self.isEmpty():
            return -1
        # Return the element at rear index
        return self.data[self.rear]

    def isEmpty(self) -> bool:
        # Queue is empty when count is 0
        return self.count == 0

    def isFull(self) -> bool:
        # Queue is full when count equals capacity
        return self.count == self.capacity


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()
```

## 6. Complexity Analysis

- **Time Complexity:** O(1) for all operations (`enQueue`, `deQueue`, `Front`, `Rear`, `isEmpty`, `isFull`). Each operation involves only constant-time array access and arithmetic operations.

- **Space Complexity:** O(k) - Where k is the capacity of the circular queue specified during initialization. We allocate a fixed-size array to store the elements.
