#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree
void insertNode(struct Node** root, int data) {
    struct Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    struct Node* temp = *root;
    while (1) {
        if (data < temp->data) {
            if (temp->left == NULL) {
                temp->left = newNode;
                break;
            }
            temp = temp->left;
        } else {
            if (temp->right == NULL) {
                temp->right = newNode;
                break;
            }
            temp = temp->right;
        }
    }
}

// Function to display the binary tree level-wise
void displayLevelOrder(struct Node* root) {
    if (root == NULL)
        return;

    // Create a queue for level order traversal
    struct Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        struct Node* current = queue[++front];
        printf("%d ", current->data);

        if (current->left != NULL)
            queue[++rear] = current->left;
        if (current->right != NULL)
            queue[++rear] = current->right;
    }
}

int main() {
    struct Node* root = NULL;
    int n, data;
    int i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the values of the nodes:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &data);
        insertNode(&root, data);
    }

    printf("Level-wise display of the binary tree:\n");
    displayLevelOrder(root);

    return 0;
}
