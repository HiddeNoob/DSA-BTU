/*
 * Demo.java
 * 
 * Java ArrayList<T> örneği - Kısa ve öz demo
 * C implementasyonunun type-safe Java versiyonu
 */

import java.util.*;

public class Demo {
    public static void main(String[] args) {
        System.out.println("=== JAVA ARRAYLIST DEMO ===\n");
        
        // 1. Integer ArrayList - type-safe, auto-boxing
        ArrayList<Integer> numbers = new ArrayList<>();
        Collections.addAll(numbers, 10, 20, 30);
        System.out.println("Integer ArrayList: " + numbers);
        System.out.println("Size: " + numbers.size() + "\n");
        
        // 2. String ArrayList - automatic garbage collection
        ArrayList<String> names = new ArrayList<>();
        Collections.addAll(names, "Ahmet", "Mehmet", "Ayşe");
        System.out.println("String ArrayList: " + names);
        
        // Enhanced for loop
        System.out.print("Names: ");
        for (String name : names) {
            System.out.print("\"" + name + "\" ");
        }
        System.out.println("\n");
        
        // 3. Operations
        numbers.add(40);
        Collections.sort(names);
        
        System.out.println("After operations:");
        System.out.println("Numbers: " + numbers);
        System.out.println("Sorted names: " + names + "\n");
        
        // 4. Mixed data with ArrayList<Object>
        ArrayList<Object> mixed = new ArrayList<>();
        mixed.add(42);
        mixed.add("Hello");
        mixed.add(3.14);
        
        System.out.println("Mixed ArrayList:");
        for (int i = 0; i < mixed.size(); i++) {
            Object obj = mixed.get(i);
            System.out.print("  [" + i + "] ");
            if (obj instanceof Integer) {
                System.out.println("Integer: " + obj);
            } else if (obj instanceof String) {
                System.out.println("String: \"" + obj + "\"");
            } else if (obj instanceof Double) {
                System.out.println("Double: " + obj);
            }
        }
        
        // 5. Key advantages over C
        System.out.println("\n=== JAVA vs C ===");
        System.out.println("✓ Type safety with generics");
        System.out.println("✓ Automatic garbage collection");
        System.out.println("✓ No manual malloc/free");
        System.out.println("✓ Built-in methods (sort, search, etc.)");
        System.out.println("✓ Exception handling");
    }
}

/*
 * COMPILATION:
 * javac Demo.java
 * 
 * ÇALIŞTIRIM:
 * java Demo
 * 
 * KEY FEATURES OF JAVA ARRAYLIST:
 * 
 * 1. Type Safety:
 *    - Generics provide compile-time type checking
 *    - ArrayList<Integer> only accepts Integer objects
 *    - No void* casting or type confusion
 * 
 * 2. Memory Management:
 *    - Automatic garbage collection
 *    - No manual malloc/free
 *    - Memory leaks much less common
 *    - Reference counting and mark-sweep GC
 * 
 * 3. Performance:
 *    - Same O(1) amortized append as C version
 *    - Automatic capacity doubling
 *    - JIT compilation can optimize hot paths
 *    - GC overhead vs manual management trade-off
 * 
 * 4. Rich API:
 *    - Built-in methods for common operations
 *    - Integration with Collections framework
 *    - Stream API for functional programming
 *    - Exception-based error handling
 * 
 * 5. Safety Features:
 *    - Bounds checking (IndexOutOfBoundsException)
 *    - Type checking (ClassCastException)
 *    - Null safety considerations
 *    - Exception stack traces for debugging
 * 
 * 6. Platform Independence:
 *    - Write once, run anywhere (WORA)
 *    - JVM handles platform differences
 *    - Consistent behavior across systems
 * 
 * TRADE-OFFS:
 * 
 * Memory: Higher overhead due to object headers, GC metadata
 * Performance: GC pauses vs manual control
 * Complexity: Simpler to use correctly, but JVM complexity
 * Control: Less direct control over memory layout
 * 
 * This shows the evolution from manual to managed memory!
 */