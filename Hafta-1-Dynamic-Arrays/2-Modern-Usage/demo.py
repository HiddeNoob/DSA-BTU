#!/usr/bin/env python3
"""
demo.py

Python list örneği - Kısa ve öz demo
C implementasyonunun dynamic typing versiyonu
"""

def main():
    print("=== PYTHON LIST DEMO ===\n")
    
    # 1. Integer list - no type declaration needed
    numbers = [10, 20, 30]
    print(f"Integer list: {numbers}")
    print(f"Size: {len(numbers)}\n")
    
    # 2. String list - automatic memory management
    names = ["Ahmet", "Mehmet", "Ayşe"]
    print(f"String list: {names}")
    
    # List comprehension (Pythonic way)
    upper_names = [name.upper() for name in names]
    print(f"Uppercase: {upper_names}\n")
    
    # 3. Operations
    numbers.append(40)
    names.sort()
    
    print("After operations:")
    print(f"Numbers: {numbers}")
    print(f"Sorted names: {names}\n")
    
    # 4. Mixed data - Python's superpower!
    mixed = [42, "Hello", 3.14, [1, 2, 3], {"key": "value"}]
    print("Mixed list (different types in same list):")
    for i, item in enumerate(mixed):
        print(f"  [{i}] {type(item).__name__}: {item}")
    
    # Type checking at runtime
    print("\nRuntime type checking:")
    for item in mixed[:3]:  # First 3 items
        if isinstance(item, int):
            print(f"  Integer: {item} * 2 = {item * 2}")
        elif isinstance(item, str):
            print(f"  String: '{item}' length = {len(item)}")
        elif isinstance(item, float):
            print(f"  Float: {item} rounded = {round(item, 2)}")
    
    # 5. Key advantages over C
    print("\n=== PYTHON vs C ===")
    print("✓ Dynamic typing - ultimate flexibility")
    print("✓ Automatic memory management")
    print("✓ No malloc/free needed")
    print("✓ Rich built-in methods")
    print("✓ List comprehensions")
    print("✓ Duck typing")

if __name__ == "__main__":
    main()

"""
KEY DIFFERENCES FROM C VERSION:

1. Dynamic Typing:
   - No need to declare types
   - Runtime type checking
   - Duck typing for polymorphism
   - Same list can hold any types

2. Memory Management:
   - Automatic garbage collection
   - Reference counting
   - No manual malloc/free
   - Circular reference detection

3. Built-in Features:
   - Rich set of list methods
   - List comprehensions
   - Slicing notation
   - Generator expressions

4. Performance Trade-offs:
   - Interpreter overhead
   - Dynamic dispatch costs
   - Memory overhead per object
   - But: highly optimized C internals
"""