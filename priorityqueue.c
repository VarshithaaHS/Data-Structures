#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // maximum size of the priority queue

// Structure for Priority Queue
struct PriorityQueue {
    int items[MAX];
    int size;
};

// Initialize queue
void initQueue(struct PriorityQueue *pq) {
    pq->size = 0;
}

// Check if queue is empty
int isEmpty(struct PriorityQueue *pq) {
    return pq->size == 0;
}

// Check if queue is full
int isFull(struct PriorityQueue *pq) {
    return pq->size == MAX;
}

// Insert an element into the priority queue
// Here smaller integer = higher priority
void insert(struct PriorityQueue *pq, int value) {
    if (isFull(pq)) {
        printf("\nQueue Overflow! Cannot insert %d.\n", value);
        return;
    }

    int i = pq->size - 1;

    // Shift elements to make space for the new element
    // Ensures queue remains sorted by priority
    while (i >= 0 && pq->items[i] > value) {
        pq->items[i + 1] = pq->items[i];
        i--;
    }

    pq->items[i + 1] = value;
    pq->size++;

    printf("\nInserted %d into the priority queue.\n", value);
}

// Delete the element with the highest priority (smallest number)
void delete(struct PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("\nQueue Underflow! Priority Queue is empty.\n");
        return;
    }

    int deleted = pq->items[0];

    // Shift remaining elements to the left
    for (int i = 0; i < pq->size - 1; i++) {
        pq->items[i] = pq->items[i + 1];
    }

    pq->size--;

    printf("\nDeleted element with highest priority: %d\n", deleted);
}

// Display the priority queue
void display(struct PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("\nPriority Queue is empty.\n");
        return;
    }

    printf("\nPriority Queue elements (in order of priority): ");
    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->items[i]);
    }
    printf("\n");
}

// Main function
int main() {
    struct PriorityQueue pq;
    initQueue(&pq);
    int choice, value;

    while (1) {
        printf("\n--- Priority Queue Operations ---");
        printf("\n1. Insert");
        printf("\n2. Delete (Highest Priority)");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(&pq, value);
                break;
            case 2:
                delete(&pq);
                break;
            case 3:
                display(&pq);
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
