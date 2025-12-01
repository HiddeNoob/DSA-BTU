#!/usr/bin/env python3
def main():
    print("=== PYTHON STACK (list) ===")
    
    # Boş stack oluştur
    stack = []
    
    # Push: sonuna ekle
    print("\nPush:")
    stack.append(10)
    print(f"  stack.append(10) -> {stack}")
    stack.append(20)
    print(f"  stack.append(20) -> {stack}")
    stack.append(30)
    print(f"  stack.append(30) -> {stack}")
    
    # Peek: en üsttekine bak
    print(f"\nPeek: stack[-1] = {stack[-1]}")
    
    # Pop: en üsttekini çıkar (LIFO)
    print("\nPop (LIFO):")
    print(f"  stack.pop() = {stack.pop()}  -> {stack}")
    print(f"  stack.pop() = {stack.pop()}  -> {stack}")
    print(f"  stack.pop() = {stack.pop()}  -> {stack}")
    
    print(f"\nBoş mu? {len(stack) == 0}")

if __name__ == "__main__":
    main()
