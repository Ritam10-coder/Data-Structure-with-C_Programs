#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
        /**printf("Circular linked list:");**/
    } while (current != head);
    printf("NULL\n");
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = head->next;
    head->next = newNode;
    return head;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = head->next;
    head->next = newNode;
    return newNode;
}

struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty, cannot delete\n");
        return head;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }
    struct Node* temp = head->next;
    head->next = temp->next;
    free(temp);
    return head;
}

struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty, cannot delete\n");
        return head;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }
    struct Node* current = head;
    while (current->next->next != head) {
        current = current->next;
    }
    struct Node* temp = current->next;
    current->next = head;
    free(temp);
    return head;
}

struct Node* deleteAfterNode(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty, cannot delete\n");
        return head;
    }
    struct Node* current = head;
    while (current->next != head) {
        if (current->data == key) {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
            return head;
        }
        current = current->next;
    }
    printf("Node with key %d not found\n", key);
    return head;
}

void deleteCircularList(struct Node* head) {
    if (head == NULL) {
        return;
    }
    struct Node* current = head;
    while (current->next != head) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
}

int main() {
    struct Node* head = NULL;
    int choice, data, key;

    do {
       /** printf("\nCircular Linked List Menu\n");**/
        printf("1. Create a linked list\n");
        printf("2. Display the elements\n");
        printf("3. Insert at beginning\n");
        printf("4. Insert at  end\n");
        printf("5. Delete from the beginning\n");
        printf("6. Delete from the end\n");
        printf("7. Delete after a given node\n");
        printf("8. Delete  entire list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for the first node: ");
                scanf("%d", &data);
                head = createNode(data);
                head->next = head;
                printf("Circular linked list created.\n");
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                printf("Node inserted at the beginning.\n");
                break;
            case 4:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                printf("Node inserted at the end.\n");
                break;
            case 5:
                head = deleteFromBeginning(head);
                printf("Node deleted from the beginning.\n");
                break;
            case 6:
                head = deleteFromEnd(head);
                printf("Node deleted from the end.\n");
                break;
            case 7:
                printf("Enter the key value after which to delete a node: ");
                scanf("%d", &key);
                head = deleteAfterNode(head, key);
                break;
            case 8:
                deleteCircularList(head);
                head = NULL;
                printf("Circular linked list deleted.\n");
                break;
            case 9:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);

    return 0;
}

