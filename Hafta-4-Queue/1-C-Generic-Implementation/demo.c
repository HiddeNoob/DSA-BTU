#include "queue.c"
#include <string.h>

struct Process {
    int pid;
    char name[50];
    int priority;
};


void printProcess(void* data) {
    if (data != NULL) {
        struct Process* p = (struct Process*)data;
        printf("Process(PID:%d, Name:%s, Priority:%d)", p->pid, p->name, p->priority);
    } else {
        printf("NULL");
    }
}


int main() {
    printf("=== PROCESS SCHEDULING QUEUE DEMO ===\n\n");
    
    // Queue oluştur
    struct Queue* processQueue = createQueue();
    
    struct Process p1 = {101, "Chrome", 1};
    struct Process p2 = {102, "Firefox", 2};
    struct Process p3 = {103, "VSCode", 1};
    struct Process p4 = {104, "Spotify", 3};
    
    enqueue(processQueue, &p1);
    printProcess(&p1);
    printf("\n");
    
    enqueue(processQueue, &p2);
    printProcess(&p2);
    printf("\n");
    
    enqueue(processQueue, &p3);
    printProcess(&p3);
    printf("\n");
    
    enqueue(processQueue, &p4);
    printProcess(&p4);
    printf("\n");
    
    // Queue durumunu göster
    printf("\nQueue is empty: %s\n", isEmpty(processQueue) ? "Yes" : "No");
    
    // Process'leri FIFO sırasıyla işle
    printf("\nProcessing (FIFO order):\n");
    while (!isEmpty(processQueue)) {
        struct Process* p = (struct Process*)dequeue(processQueue);
        if (p != NULL) {
            printf("  Processing: PID=%d, Name=%s\n", p->pid, p->name);
        }
    }
    
    printf("\nQueue is empty: %s\n", isEmpty(processQueue) ? "Yes" : "No");
    
    return 0;
}