# Reverse Linked List

**LeetCode No:** 206

**Level:** Easy

**Link:** https://leetcode.com/problems/reverse-linked-list/

## 1. Problem Description

Given the head of a singly linked list, reverse the list and return the reversed list.

In other words, you need to change the direction of all the "next" pointers in the linked list so that they point backwards. The first node becomes the last node, the second node becomes the second-to-last node, and so on. The last node becomes the first node of the new reversed list.

## 2. Examples

**Example 1:**
- **Input:** head = [1,2,3,4,5]
- **Output:** [5,4,3,2,1]

**Example 2:**
- **Input:** head = [1,2]
- **Output:** [2,1]

**Example 3:**
- **Input:** head = []
- **Output:** []

## 3. Constraints

- The number of nodes in the list is in the range [0, 5000]
- -5000 <= Node.val <= 5000

## 4. Solution Approach (Intuition)

To reverse a linked list, we need to make each node's "next" pointer point to its previous node instead of its next node. However, we must be careful not to lose track of the nodes as we modify the pointers.

The key insight is to use three pointers:
1. **previous** - keeps track of the node we just processed (initially null)
2. **current** - points to the node we are currently processing
3. **next_node** - temporarily stores the next node so we don't lose it when we change the current node's pointer

Here's the step-by-step process:
1. Start with previous = null and current = head
2. While current is not null:
   - Store the next node in next_node (so we don't lose it)
   - Make current's next pointer point to previous (this reverses the link)
   - Move previous to current (shift our window forward)
   - Move current to next_node (continue to the next node)
3. When current becomes null, previous will be pointing to the new head of the reversed list

Think of it like reversing the direction of arrows in a chain: →→→ becomes ←←←

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
    ListNode* reverseList(ListNode* head) {
        // Initialize three pointers
        ListNode* previous = nullptr;    // The node behind current (initially null)
        ListNode* current = head;        // The node we're currently processing
        ListNode* next_node = nullptr;   // Temporary storage for the next node
        
        // Traverse the list and reverse each link
        while (current != nullptr) {
            // Store the next node before we lose it
            next_node = current->next;
            
            // Reverse the current node's pointer to point backwards
            current->next = previous;
            
            // Move our window forward: shift previous and current pointers
            previous = current;
            current = next_node;
        }
        
        // When current becomes null, previous points to the new head
        return previous;
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
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Initialize three pointers
        previous = None      # The node behind current (initially None)
        current = head       # The node we're currently processing
        
        # Traverse the list and reverse each link
        while current is not None:
            # Store the next node before we lose it
            next_node = current.next
            
            # Reverse the current node's pointer to point backwards
            current.next = previous
            
            # Move our window forward: shift previous and current pointers
            previous = current
            current = next_node
        
        # When current becomes None, previous points to the new head
        return previous
```

## 6. Complexity Analysis

- **Time Complexity:** O(n) - We visit each node in the linked list exactly once, where n is the number of nodes.

- **Space Complexity:** O(1) - We only use a constant amount of extra space (three pointer variables) regardless of the size of the input list.