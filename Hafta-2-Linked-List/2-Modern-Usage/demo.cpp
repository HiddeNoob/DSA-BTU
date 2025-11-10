/*
 * demo.cpp
 * 
 * C++ Singly Linked Lists - std::list demo
 * Cuma dersi için kısa örnek
 * 
 * C++'ta linked list: std::list<T>
 * Template kullanır, type-safe, STL container
 */

#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    cout << "=== C++ STD::LIST DEMO ===\n\n";
    
    // Type-safe integer list
    list<int> numbers;
    
    // Push operations (C'deki insertAtHead/Tail)
    numbers.push_front(10);  // Head'e ekle
    numbers.push_front(20);
    numbers.push_back(5);    // Tail'e ekle
    numbers.push_back(15);
    
    cout << "Numbers: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << "\nSize: " << numbers.size() << "\n\n";
    
    // String list
    list<string> names = {"Alice", "Bob", "Charlie"};
    names.push_front("David");
    names.insert(next(names.begin(), 2), "Eve");  // Insert at position
    
    cout << "Names: ";
    for (const string& name : names) {
        cout << name << " ";
    }
    cout << "\n\n";
    
    // Operations
    auto it = find(numbers.begin(), numbers.end(), 15);
    if (it != numbers.end()) {
        cout << "Found 15 at position: " 
             << distance(numbers.begin(), it) << "\n";
    }
    
    // Remove elements
    numbers.remove(10);  // Remove by value
    numbers.pop_front(); // Remove first
    numbers.pop_back();  // Remove last
    
    cout << "After removals: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << "\n\n";
    
    // C ile karşılaştırma
    cout << "C vs C++ karşılaştırması:\n";
    cout << "- C: void*, manuel memory, function pointers\n";
    cout << "- C++: Template<T>, automatic memory, STL\n";
    cout << "- C++: Type safety + performance + easy use\n";
    
    return 0;
}

/*
 * COMPILE: g++ -std=c++11 demo.cpp -o demo
 * RUN: ./demo
 * 
 * Key differences from C implementation:
 * 1. Type safety (template<T>)
 * 2. Automatic memory management
 * 3. Rich STL algorithms
 * 4. Iterator-based design
 * 5. Exception safety
 */