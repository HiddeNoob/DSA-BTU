#!/usr/bin/env python3
"""
demo.py

Python Linked Lists demo - Cuma dersi için kısa örnek
collections.deque kullanır (double-ended queue)

Python'da linked list: deque (double-ended queue)
Dynamic typing, automatic memory, built-in operations
"""

from collections import deque

def main():
    print("=== PYTHON DEQUE DEMO ===\n")
    
    # Dynamic typing - mixed data types
    data = deque()
    
    # Add operations
    data.appendleft("First")      # Head'e ekle (C'deki insertAtHead)
    data.appendleft(42)           # Head'e integer
    data.append("Last")           # Tail'e ekle (C'deki insertAtTail)
    data.append(3.14)             # Tail'e float
    
    print(f"Mixed data: {list(data)}")
    print(f"Length: {len(data)}\n")
    
    # Access operations
    print(f"First item: {data[0]}")
    print(f"Last item: {data[-1]}")
    print(f"Second item: {data[1]}\n")
    
    # String deque
    names = deque(["Alice", "Bob", "Charlie"])
    names.appendleft("David")     # Add to head
    names.insert(2, "Eve")        # Insert at index
    
    print(f"Names: {list(names)}")
    
    # Search operation
    try:
        index = list(names).index("Eve")
        print(f"Eve found at index: {index}")
    except ValueError:
        print("Eve not found")
    
    # Remove operations
    first = data.popleft()        # Remove from head
    last = data.pop()             # Remove from tail
    print(f"\nRemoved first: {first}, last: {last}")
    print(f"Remaining: {list(data)}")
    
    # Number operations
    numbers = deque(range(1, 6))  # [1, 2, 3, 4, 5]
    numbers.rotate(2)             # Rotate right by 2
    print(f"After rotation: {list(numbers)}")
    
    # List comprehension with deque
    squares = deque([x**2 for x in range(5)])
    print(f"Squares: {list(squares)}")
    
    # Iterator usage
    print("Iterating through names:")
    for i, name in enumerate(names):
        print(f"  [{i}] {name}")
    
    print("\nC vs Python karşılaştırması:")
    print("- C: void*, malloc/free, manual type handling")
    print("- Python: Dynamic typing, GC, built-in operations")
    print("- Python: Flexibility + automatic memory + rich syntax")

if __name__ == "__main__":
    main()

"""
RUN: python3 demo.py

Key features:
1. Dynamic typing (no type declarations)
2. Automatic memory management (GC)
3. Rich built-in operations
4. List-like interface with O(1) head/tail ops
5. Mixed data types in same container
6. Pythonic syntax and idioms

Note: Python lists are actually dynamic arrays (like C++ vector)
deque is the closest to linked list with O(1) head operations
"""