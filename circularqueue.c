#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // maximum size of the circular queue

// Structure for Circular Queue
struct CircularQueue {
    int items[MAX];
    int front;
    int rear;
};

// Initialize the circular queue
void initQueue(struct CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(struct CircularQueue *q) {
    return (q->front == -1);
}

// Check if queue is full
int isFull(struct CircularQueue *q) {
    return ((q->rear + 1) % MAX == q->front);
}

// Insert an element into the circular queue
void enqueue(struct CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("\nQueue Overflow! Cannot insert %d.\n", value);
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;

    printf("\nInserted %d into the circular queue.\n", value);
}

// Delete an element from the circular queue
void dequeue(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("\nQueue Underflow! Queue is empty.\n");
        return;
    }

    int deleted = q->items[q->front];
    printf("\nDeleted %d from the circular queue.\n", deleted);

    // If the queue now becomes empty
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
}

// Display the elements of the circular queue
void display(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nCircular Queue elements are: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function
int main() {
    struct CircularQueue q;
    initQueue(&q);
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Operations ---");
        printf("\n1. Insert (Enqueue)");
        printf("\n2. Delete (Dequeue)");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
