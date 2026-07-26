#ifndef TREES_H
#define TREES_H

// Node used in the binary search tree.
typedef struct Node
{
    char data;
    struct Node* left;
    struct Node* right;
} Node;

// Inserts a character into the tree.
Node* insert(Node* root, char value);

// Searches the tree for a character.
Node* search(Node* root, char value);

// Counts the number of nodes in the tree.
int countNodes(Node* root);

// Calculates the height of the tree.
int treeHeight(Node* root);

// Prints the tree in alphabetical order.
void inorder(Node* root);

// Frees all memory used by the tree.
void freeTree(Node* root);

#endif