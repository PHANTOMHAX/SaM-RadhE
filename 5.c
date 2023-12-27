#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize an empty queue
void initializeQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to enqueue (add) an element to the rear of the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        // If the queue is empty, set both front and rear to the new node
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // Otherwise, add the new node to the rear and update the rear pointer
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue (remove) an element from the front of the queue
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        // Queue underflow, cannot dequeue from an empty queue
        printf("Queue underflow. Cannot dequeue from an empty queue.\n");
        exit(1);
    }

    struct Node* temp = queue->front;
    int dequeuedValue = temp->data;

    // Update the front pointer to the next node
    queue->front = temp->next;

    // If the queue becomes empty after dequeue, update the rear pointer as well
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return dequeuedValue;
}

// Function to display the elements of the queue
void displayQueue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    struct Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create a queue
    struct Queue myQueue;
    initializeQueue(&myQueue);

    // Enqueue elements to the queue
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    // Display the elements of the queue
    displayQueue(&myQueue);

    // Dequeue elements from the queue and display the result
    printf("Dequeued value: %d\n", dequeue(&myQueue));
    printf("Dequeued value: %d\n", dequeue(&myQueue));

    // Display the remaining elements of the queue
    displayQueue(&myQueue);

    return 0;
}
