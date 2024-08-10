#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for BST node
struct Node {
    char data;
    struct Node *left, *right;
};

// Function to create a new BST node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a character into BST
struct Node* insert(struct Node* root, char data) {
    if (root == NULL)
        return createNode(data);
    
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to traverse BST in inorder (sorted order)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%c ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to free memory allocated for BST
void freeBST(struct Node* root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

int main() {
    char username[100];
    int i;
    printf("Enter your name: ");
    scanf("%s", username);

    struct Node* root = NULL;

    // Insert characters of the user name into BST
    for(i = 0; i < strlen(username); i++) {
        root = insert(root, username[i]);
    }

    // Display the sorted sequence of characters
    printf("Sorted sequence of characters: ");
    inorderTraversal(root);
    printf("\n");

    // Free memory allocated for BST
    freeBST(root);

    return 0;
}
