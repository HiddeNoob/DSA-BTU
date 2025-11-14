# Middle of the Linked List

**LeetCode No:** 876

**Level:** Easy

**Link:** https://leetcode.com/problems/middle-of-the-linked-list/

## 1. Problem Description

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes (which happens when the list has an even number of nodes), return the second middle node.

For example, if the list has nodes [1,2,3,4], the two middle nodes are 2 and 3, but we should return node 3.

## 2. Examples

**Example 1:**
- **Input:** head = [1,2,3,4,5]
- **Output:** [3,4,5]
- **Explanation:** The middle node of the list is node 3.

**Example 2:**
- **Input:** head = [1,2,3,4,5,6]
- **Output:** [4,5,6]
- **Explanation:** Since the list has two middle nodes with values 3 and 4, we return the second one.

## 3. Constraints

- The number of nodes in the list is in the range [1, 100]
- 1 <= Node.val <= 100

## 4. Solution Approach (Intuition)

The most elegant solution uses the "tortoise and hare" technique (also known as Floyd's cycle-finding algorithm). This approach uses two pointers moving at different speeds:

1. **Slow pointer (tortoise)** - moves one step at a time
2. **Fast pointer (hare)** - moves two steps at a time

Here's the key insight: When the fast pointer reaches the end of the list, the slow pointer will be exactly at the middle!

Why does this work?
- If the fast pointer moves twice as fast as the slow pointer, when the fast pointer has traveled the entire length of the list, the slow pointer has traveled half the length
- This means the slow pointer will be pointing to the middle node

For lists with even length:
- When there are two middle nodes, this method naturally returns the second middle node
- This happens because when the fast pointer can't make its next two-step move, the slow pointer is positioned at the second middle node

This approach is much more efficient than first counting all nodes and then traversing to the middle, because we only need to traverse the list once.

## 5. Code Solutions

### C++ Solution

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Initialize two pointers at the head
        ListNode* slow = head;    // Tortoise: moves 1 step at a time
        ListNode* fast = head;    // Hare: moves 2 steps at a time
        
        // Move pointers until fast reaches the end
        while (fast != nullptr && fast->next != nullptr) {
            // Move slow pointer one step forward
            slow = slow->next;
            
            // Move fast pointer two steps forward
            fast = fast->next->next;
        }
        
        // When fast reaches the end, slow is at the middle
        return slow;
    }
};
```

### Python Solution

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Initialize two pointers at the head
        slow = head    # Tortoise: moves 1 step at a time
        fast = head    # Hare: moves 2 steps at a time
        
        # Move pointers until fast reaches the end
        while fast is not None and fast.next is not None:
            # Move slow pointer one step forward
            slow = slow.next
            
            # Move fast pointer two steps forward
            fast = fast.next.next
        
        # When fast reaches the end, slow is at the middle
        return slow
```

## 6. Complexity Analysis

- **Time Complexity:** O(n) - We traverse the linked list once, where n is the number of nodes. Even though we have two pointers, the fast pointer determines the number of iterations, which is n/2, still O(n).

- **Space Complexity:** O(1) - We only use two pointer variables regardless of the size of the input list, so we use constant extra space.