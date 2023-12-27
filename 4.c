#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a stack structure
struct Stack {
    struct Node* top;
};

// Function to initialize an empty stack
void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        exit(1);
    }

    struct Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = temp->next;
    free(temp);
    return poppedValue;
}

int main() {
    // Create a stack
    struct Stack stack;
    initializeStack(&stack);

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Pop elements from the stack and print them
    printf("Popped value: %d\n", pop(&stack));
    printf("Popped value: %d\n", pop(&stack));
    printf("Popped value: %d\n", pop(&stack));

    // Check if the stack is empty
    if (isEmpty(&stack)) {
        printf("The stack is empty.\n");
    } else {
        printf("The stack is not empty.\n");
    }

    return 0;
}
