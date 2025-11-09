#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // maximum size of the queue

// Queue structure
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Initialize queue
void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(struct Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

// Check if queue is full
int isFull(struct Queue *q) {
    return q->rear == MAX - 1;
}

// Insert an element into the queue
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("\nQueue Overflow! Cannot insert %d\n", value);
        return;
    }

    if (q->front == -1)  // first element
        q->front = 0;

    q->rear++;
    q->items[q->rear] = value;
    printf("\nInserted %d into the queue.\n", value);
}

// Delete an element from the queue
void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("\nQueue Underflow! Queue is empty.\n");
        return;
    }

    int deleted = q->items[q->front];
    printf("\nDeleted %d from the queue.\n", deleted);
    q->front++;

    // Reset queue if it becomes empty
    if (q->front > q->rear)
        q->front = q->rear = -1;
}

// Display the elements of the queue
void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nQueue elements are: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->items[i]);
    printf("\n");
}

// Main function with menu
int main() {
    struct Queue q;
    initQueue(&q);
    int choice, value;

    while (1) {
        printf("\n--- Queue Operations ---");
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
