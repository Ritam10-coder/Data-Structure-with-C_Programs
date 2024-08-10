#include<stdio.h>
#include<stdlib.h>

// Define structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to count internal nodes in a binary tree
int countInternalNodes(struct TreeNode* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0; // Base case: empty tree or leaf node
    else
        return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

int main() {
    // Create a sample binary tree
    struct TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Calculate and print the number of internal nodes
    printf("Number of internal nodes in the binary tree: %d\n", countInternalNodes(root));

    return 0;
}

