#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // maximum size of the deque

// Structure for Deque
struct Deque {
    int items[MAX];
    int front;
    int rear;
};

// Initialize the deque
void initDeque(struct Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

// Check if deque is empty
int isEmpty(struct Deque *dq) {
    return dq->front == -1;
}

// Check if deque is full
int isFull(struct Deque *dq) {
    return ((dq->front == 0 && dq->rear == MAX - 1) ||
            (dq->front == dq->rear + 1));
}

// Insert element at front
void insertFront(struct Deque *dq, int value) {
    if (isFull(dq)) {
        printf("\nDeque Overflow! Cannot insert %d at front.\n", value);
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }

    dq->items[dq->front] = value;
    printf("\nInserted %d at the front.\n", value);
}

// Insert element at rear
void insertRear(struct Deque *dq, int value) {
    if (isFull(dq)) {
        printf("\nDeque Overflow! Cannot insert %d at rear.\n", value);
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }

    dq->items[dq->rear] = value;
    printf("\nInserted %d at the rear.\n", value);
}

// Delete element from front
void deleteFront(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("\nDeque Underflow! Cannot delete from front.\n");
        return;
    }

    int deleted = dq->items[dq->front];
    printf("\nDeleted %d from the front.\n", deleted);

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1; // Deque is now empty
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
}

// Delete element from rear
void deleteRear(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("\nDeque Underflow! Cannot delete from rear.\n");
        return;
    }

    int deleted = dq->items[dq->rear];
    printf("\nDeleted %d from the rear.\n", deleted);

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1; // Deque is now empty
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear--;
    }
}

// Display the deque
void display(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("\nDeque is empty.\n");
        return;
    }

    printf("\nDeque elements are: ");
    int i = dq->front;
    while (1) {
        printf("%d ", dq->items[i]);
        if (i == dq->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function
int main() {
    struct Deque dq;
    initDeque(&dq);
    int choice, value;

    while (1) {
        printf("\n--- Double Ended Queue (Deque) Operations ---");
        printf("\n1. Insert at Front");
        printf("\n2. Insert at Rear");
        printf("\n3. Delete from Front");
        printf("\n4. Delete from Rear");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(&dq, value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;
            case 3:
                deleteFront(&dq);
                break;
            case 4:
                deleteRear(&dq);
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
