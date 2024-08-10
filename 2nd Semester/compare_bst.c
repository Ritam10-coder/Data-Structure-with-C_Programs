#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a node in a binary tree
struct Node* binaryTreeSearch(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    struct Node* left = binaryTreeSearch(root->left, data);
    struct Node* right = binaryTreeSearch(root->right, data);
    return (left != NULL) ? left : right;
}

// Function to search for a node in a binary search tree
struct Node* binarySearchTreeSearch(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return binarySearchTreeSearch(root->left, data);
    } else {
        return binarySearchTreeSearch(root->right, data);
    }
}

// Function to count the number of function calls
int functionCallCount = 0;
int countFunctionCalls(struct Node* root) {
    functionCallCount++;
    return functionCallCount;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    int searchData = 6;

    printf("Binary Tree Search Function Calls: %d\n", countFunctionCalls(binaryTreeSearch(root, searchData)));
    
    functionCallCount = 0; // Reset the function call count
    
    printf("Binary Search Tree Search Function Calls: %d\n", countFunctionCalls(binarySearchTreeSearch(root, searchData)));
    
    return 0;
}
