#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to delete a node by value
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found. Cannot delete.\n", value);
    } else {
        if (prev == NULL) {
            // If the node to be deleted is the first node
            *head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
        printf("Node with value %d deleted successfully.\n", value);
    }
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("Linked List: ");
        while (head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);

    // Insert nodes at the end
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    // Display the initial list
    displayList(head);

    // Delete a node
    deleteNode(&head, 20);

    // Display the updated list
    displayList(head);

    // Delete a non-existing node
    deleteNode(&head, 50);

    // Display the final list
    displayList(head);

    return 0;
}
