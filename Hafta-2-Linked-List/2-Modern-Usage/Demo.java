/*
 * Demo.java
 * 
 * Java LinkedList demo - Cuma dersi için kısa örnek
 * java.util.LinkedList<T> kullanır
 * 
 * Java'da linked list: LinkedList<T>
 * Generics kullanır, garbage collection, Collections framework
 */

import java.util.LinkedList;
import java.util.Iterator;

public class Demo {
    public static void main(String[] args) {
        System.out.println("=== JAVA LINKEDLIST DEMO ===\n");
        
        // Type-safe String LinkedList
        LinkedList<String> cities = new LinkedList<>();
        
        // Add operations
        cities.addFirst("Istanbul");  // Head'e ekle
        cities.addFirst("Ankara");
        cities.addLast("Izmir");      // Tail'e ekle
        cities.add(2, "Bursa");       // Index'e ekle
        
        System.out.println("Cities: " + cities);
        System.out.println("Size: " + cities.size() + "\n");
        
        // Access operations
        System.out.println("First: " + cities.getFirst());
        System.out.println("Last: " + cities.getLast());
        System.out.println("Index 1: " + cities.get(1) + "\n");
        
        // Search operation
        int index = cities.indexOf("Bursa");
        if (index >= 0) {
            System.out.println("Bursa found at index: " + index);
        }
        
        // Integer LinkedList
        LinkedList<Integer> scores = new LinkedList<>();
        for (int i = 1; i <= 5; i++) {
            scores.addLast(i * 20);  // 20, 40, 60, 80, 100
        }
        
        System.out.println("\nScores: " + scores);
        
        // Remove operations
        scores.removeFirst();         // Remove head
        scores.removeLast();          // Remove tail
        scores.remove(Integer.valueOf(60)); // Remove by value
        
        System.out.println("After removals: " + scores);
        
        // Iterator pattern
        System.out.print("Using iterator: ");
        Iterator<Integer> it = scores.iterator();
        while (it.hasNext()) {
            System.out.print(it.next() + " ");
        }
        System.out.println("\n");
        
        // C ile karşılaştırma
        System.out.println("C vs Java karşılaştırması:");
        System.out.println("- C: void*, malloc/free, manual type handling");
        System.out.println("- Java: Generics<T>, GC, Collections framework");
        System.out.println("- Java: Type safety + automatic memory + rich API");
    }
}

/*
 * COMPILE: javac Demo.java
 * RUN: java Demo
 * 
 * Key features:
 * 1. Generic type safety: LinkedList<T>
 * 2. Garbage collection (no manual free)
 * 3. Rich Collections API
 * 4. Iterator design pattern
 * 5. Exception handling for invalid operations
 * 6. Implements List, Deque, Queue interfaces
 */