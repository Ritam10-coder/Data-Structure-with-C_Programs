#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to display the elements of the doubly linked list
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning of the doubly linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

// Function to insert a node before a given node in the doubly linked list
void insertBeforeNode(struct Node* head, int data, int targetData) {
    struct Node* newNode = createNode(data);
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == targetData) {
            newNode->prev = current->prev;
            newNode->next = current;
            if (current->prev != NULL) {
                current->prev->next = newNode;
            }
            current->prev = newNode;
            break;
        }
        current = current->next;
    }
}

// Function to insert a node after a given node in the doubly linked list
void insertAfterNode(struct Node* head, int data, int targetData) {
    struct Node* newNode = createNode(data);
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == targetData) {
            newNode->prev = current;
            newNode->next = current->next;
            if (current->next != NULL) {
                current->next->prev = newNode;
            }
            current->next = newNode;
            break;
        }
        current = current->next;
    }
}

// Function to delete a node from the beginning of the doubly linked list
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct Node* newHead = head->next;
    free(head);
    if (newHead != NULL) {
        newHead->prev = NULL;
    }
    return newHead;
}

// Function to delete a node from the end of the doubly linked list
void deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        return;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    if (current->prev != NULL) {
        current->prev->next = NULL;
    }
    free(current);
}

// Function to delete a node after a given node in the doubly linked list
void deleteAfterNode(struct Node* head, int targetData) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == targetData && current->next != NULL) {
            struct Node* nodeToDelete = current->next;
            current->next = nodeToDelete->next;
            if (nodeToDelete->next != NULL) {
                nodeToDelete->next->prev = current;
            }
            free(nodeToDelete);
            break;
        }
        current = current->next;
    }
}

// Function to delete the entire doubly linked list
void deleteList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data, targetData;

    do {
        printf("\nMenu:\n");
        printf("1. Create a doubly linked list\n");
        printf("2. Display elements\n");
        printf("3. Insert at the beginning\n");
        printf("4. Insert at the end\n");
        printf("5. Insert before a given node\n");
        printf("6. Insert after a given node\n");
        printf("7. Delete from the beginning\n");
        printf("8. Delete from the end\n");
        printf("9. Delete after a given node\n");
        printf("10. Delete the entire list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for the first node: ");
                scanf("%d", &data);
                head = createNode(data);
                printf("Doubly linked list created.\n");
                break;

            case 2:
                display(head);
                break;

            case 3:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;

            case 4:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(head, data);
                break;

            case 5:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter target data: ");
                scanf("%d", &targetData);
                insertBeforeNode(head, data, targetData);
                break;

            case 6:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter target data: ");
                scanf("%d", &targetData);
                insertAfterNode(head, data, targetData);
                break;

            case 7:
                head = deleteFromBeginning(head);
                break;

            case 8:
                deleteFromEnd(head);
                break;

            case 9:
                printf("Enter target data: ");
                scanf("%d", &targetData);
                deleteAfterNode(head, targetData);
                break;

            case 10:
                deleteList(head);
                head = NULL;
                printf("Doubly linked list deleted.\n");
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
