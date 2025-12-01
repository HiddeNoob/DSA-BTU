import java.util.Stack;

public class Demo {
    public static void main(String[] args) {
        
        // Boş stack oluştur
        Stack<Integer> stack = new Stack<>();
        
        // Push: üste ekle
        System.out.println("\nPush:");
        stack.push(10);
        System.out.println("  stack.push(10)");
        stack.push(20);
        System.out.println("  stack.push(20)");
        stack.push(30);
        System.out.println("  stack.push(30)");
        
        System.out.println("  size: " + stack.size());
        
        // Peek: en üsttekine bak
        System.out.println("\nPeek: stack.peek() = " + stack.peek());
        
        // Pop: en üsttekini çıkar (LIFO)
        System.out.println("\nPop (LIFO):");
        System.out.println("  stack.pop() = " + stack.pop());
        System.out.println("  stack.pop() = " + stack.pop());
        System.out.println("  stack.pop() = " + stack.pop());
        
        System.out.println("\nBoş mu? " + stack.empty());
    }
}

