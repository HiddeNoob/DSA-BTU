import java.util.Queue;
import java.util.LinkedList;

public class Demo {
    public static void main(String[] args) {
        Queue<String> queue = new LinkedList<>();
        
        // Enqueue
        queue.offer("Task-1");
        queue.offer("Task-2");
        queue.offer("Task-3");
        
        // Dequeue
        queue.poll();
        queue.poll();
    }
}
