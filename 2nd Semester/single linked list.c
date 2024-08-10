#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* createLinkedList() {
    return NULL;
}

void displayLinkedList(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

struct Node* insertBeforeNode(struct Node* head, int data, int target) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    if (head->data == target) {
        newNode->next = head;
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL && current->next->data != target) {
        current = current->next;
    }
    if (current->next != NULL) {
        newNode->next = current->next;
        current->next = newNode;
    } else {
        printf("Node with data %d not found.\n", target);
        free(newNode);
    }
    return head;
}

struct Node* insertAfterNode(struct Node* head, int data, int target) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current != NULL && current->data != target) {
        current = current->next;
    }
    if (current != NULL) {
        newNode->next = current->next;
        current->next = newNode;
    } else {
        printf("Node with data %d not found.\n", target);
        free(newNode);
    }
    return head;
}

struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

struct Node* deleteAfterNode(struct Node* head, int target) {
    struct Node* current = head;
    while (current != NULL && current->data != target) {
        current = current->next;
    }
    if (current != NULL && current->next != NULL) {
        struct Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    } else {
        printf("Node with data %d not found or it's the last node.\n", target);
    }
    return head;
}

struct Node* deleteLinkedList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    return NULL;
}

int main() {
    struct Node* head = createLinkedList();
    int choice, data, target;

    do {
        printf("1. Create  single linked list\n");
        printf("2. Display the elements \n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Insert a node before  given node\n");
        printf("6. Insert a node after  given node\n");
        printf("7. Delete a node from  beginning\n");
        printf("8. Delete a node from  end\n");
        printf("9. Delete a node after a given node\n");
        printf("10. Delete the entire linked list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for the first node: ");
                scanf("%d", &data);
                head = createNode(data);
                break;
            case 2:
                displayLinkedList(head);
                break;
            case 3:
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 4:
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 5:
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                printf("Enter the data of the target node: ");
                scanf("%d", &target);
                head = insertBeforeNode(head, data, target);
                break;
            case 6:
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                printf("Enter the data of the target node: ");
                scanf("%d", &target);
                head = insertAfterNode(head, data, target);
                break;
            case 7:
                head = deleteFromBeginning(head);
                break;
            case 8:
                head = deleteFromEnd(head);
                break;
            case 9:
                printf("Enter the data of the target node: ");
                scanf("%d", &target);
                head = deleteAfterNode(head, target);
                break;
            case 10:
                head = deleteLinkedList(head);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

