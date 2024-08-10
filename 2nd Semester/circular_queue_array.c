#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int circularQueue[MAX_SIZE];
int front = -1, rear = -1;

int isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

int isEmpty() {
    return front == -1;
}

void insertElement(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot insert.\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        circularQueue[rear] = item;
        printf("Inserted %d into the queue.\n", item);
    }
}

void deleteElement() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot delete.\n");
    } else {
        int deletedItem = circularQueue[front];
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
        printf("Deleted %d from the queue.\n", deletedItem);
    }
}

int frontElement() {
    if (isEmpty()) {
        printf("Queue is empty. No front element.\n");
        return -1;
    } else {
        return circularQueue[front];
    }
}

void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Elements in the queue: ");
        int i = front;
        do {
            printf("%d ", circularQueue[i]);
            if (i == rear && front != rear) {
                break;
            }
            if (i == MAX_SIZE - 1) {
                i = 0;
            } else {
                i++;
            }
        } while (i != front);
        printf("\n");
    }
}

int main() {
    int choice, item;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Front element\n");
        printf("4. Display queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &item);
                insertElement(item);
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                printf("Front element: %d\n", frontElement());
                break;
            case 4:
                displayQueue();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
