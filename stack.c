#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of stack

int stack[MAX];
int top = -1;

// Function to push an element into the stack
void push() {
    int val;
    if (top == MAX - 1) {
        printf("\nStack Overflow! Cannot push more elements.\n");
    } else {
        printf("Enter the element to push: ");
        scanf("%d", &val);
        top++;
        stack[top] = val;
        printf("%d pushed into the stack.\n", val);
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("\nStack Underflow! No elements to pop.\n");
    } else {
        printf("%d popped from the stack.\n", stack[top]);
        top--;
    }
}

// Function to display all elements of the stack
void display() {
    if (top == -1) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nStack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
