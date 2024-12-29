#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the queue

// Queue structure
struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(struct Queue* q) {
    return q->rear == MAX - 1;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

// Enqueue function (add an element to the queue)
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;  // If the queue is empty, set the front to 0
    }
    q->rear++;  // Increment the rear index
    q->arr[q->rear] = value;  // Add the value at the rear position
    printf("Enqueued %d\n", value);
}

// Dequeue function (remove an element from the queue)
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;  // Return -1 to indicate the queue is empty
    }
    int dequeuedValue = q->arr[q->front];
    q->front++;  // Increment the front index to remove the element
    if (q->front > q->rear) {
        q->front = q->rear = -1;  // Reset the queue if it becomes empty
    }
    printf("Dequeued %d\n", dequeuedValue);
    return dequeuedValue;
}

// Function to peek at the front element of the queue
int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->arr[q->front];
}

// Main function to demonstrate the queue operations
int main() {
    struct Queue q;
    initQueue(&q);  // Initialize the queue

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    
    // Try to enqueue when the queue is full
    enqueue(&q, 60);

    printf("Front element: %d\n", peek(&q));  // Peek at the front element
    
    // Dequeue elements
    dequeue(&q);
    dequeue(&q);

    // Peek again
    printf("Front element after dequeue: %d\n", peek(&q));

    // Dequeue remaining elements
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    // Try to dequeue from an empty queue
    dequeue(&q);

    return 0;
}
