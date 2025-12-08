#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    void* data;
    struct Node* next;
}Node;

/*
 * Queue Structure
 */
typedef struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
}Queue;

/*
 * createQueue() - Yeni bir queue oluşturur
 * 
 * @return: Yeni queue pointer'ı veya NULL
 * 
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
Queue* createQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));

    q->size = 0;
    q->front = 0;
    q->rear = 0;

    return q;
}

/*
 * enqueue() - Queue'nun rear'ına yeni eleman ekler
 * 
 * @param queue: Queue pointer'ı
 * @param data: Eklenecek veri
 * 
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void enqueue(Queue* queue, void* data){

    // datayi wrapleyelim
    Node* dataNode = (Node*)malloc(sizeof(Node));
    dataNode->data = data;
    dataNode->next = NULL;

    if(queue->size == 0){
        queue->front = dataNode;
        queue->rear = dataNode;
    }else{
        queue->rear->next = dataNode;
        queue->rear = dataNode;
    }

    queue->size++;
}

/*
 * dequeue() - Queue'nun front'undan eleman çıkarır
 * 
 * @param queue: Queue pointer'ı
 * @return: Çıkarılan data veya NULL
 * 
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void* dequeue(Queue* queue){

    if(queue->size <= 0) return NULL;

    void* data = queue->front->data;

    Node* silenecek = queue->front;

    queue->front = silenecek->next;

    free(silenecek);

    queue->size--;

    return data;
}

/*
 * isEmpty() - Queue boş mu kontrol et
 * 
 * @param queue: Queue pointer'ı
 * @return: 1 if empty, 0 if not empty
 */
int isEmpty(Queue* queue){
    return queue->size == 0 ? 1 : 0;
}