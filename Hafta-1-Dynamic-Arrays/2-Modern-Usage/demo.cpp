/*
 * demo.cpp
 * 
 * C++ std::vector<T> örneği - Kısa ve öz demo
 * C implementasyonunun type-safe modern versiyonu
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::cout << "=== C++ STD::VECTOR DEMO ===\n\n";
    
    // 1. Integer vector - type-safe, no malloc needed
    std::vector<int> numbers = {10, 20, 30};
    std::cout << "Integer vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\nSize: " << numbers.size() << ", Capacity: " << numbers.capacity() << "\n\n";
    
    // 2. String vector - automatic memory management
    std::vector<std::string> names = {"Ahmet", "Mehmet", "Ayşe"};
    std::cout << "String vector: ";
    for (const auto& name : names) {
        std::cout << "\"" << name << "\" ";
    }
    std::cout << "\n\n";
    
    // 3. Operations
    numbers.push_back(40);
    std::sort(names.begin(), names.end());
    
    std::cout << "After operations:\n";
    std::cout << "Numbers: ";
    for (int num : numbers) std::cout << num << " ";
    std::cout << "\nSorted names: ";
    for (const auto& name : names) std::cout << name << " ";
    std::cout << "\n\n";
    
    // 4. Key advantages over C
    std::cout << "=== C++ vs C ===\n";
    std::cout << "✓ Type safety (no void* casting)\n";
    std::cout << "✓ Automatic memory management\n";
    std::cout << "✓ No manual malloc/free\n";
    std::cout << "✓ STL algorithms\n";
    std::cout << "✓ Same O(1) performance as C\n";
    
    return 0;
}