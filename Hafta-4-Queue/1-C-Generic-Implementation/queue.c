#include <stdio.h>
#include <stdlib.h>


struct Node {
    void* data;
    struct Node* next;
};

/*
 * Queue Structure
 */
struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
};

/*
 * createQueue() - Yeni bir queue oluşturur
 * 
 * @return: Yeni queue pointer'ı veya NULL
 * 
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
struct Queue* createQueue();

/*
 * enqueue() - Queue'nun rear'ına yeni eleman ekler
 * 
 * @param queue: Queue pointer'ı
 * @param data: Eklenecek veri
 * 
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void enqueue(struct Queue* queue, void* data);

/*
 * dequeue() - Queue'nun front'undan eleman çıkarır
 * 
 * @param queue: Queue pointer'ı
 * @return: Çıkarılan data veya NULL
 * 
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void* dequeue(struct Queue* queue);

/*
 * isEmpty() - Queue boş mu kontrol et
 * 
 * @param queue: Queue pointer'ı
 * @return: 1 if empty, 0 if not empty
 */
int isEmpty(struct Queue* queue);