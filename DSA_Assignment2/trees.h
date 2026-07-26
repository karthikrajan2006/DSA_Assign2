#ifndef TREES_H
#define TREES_H

typedef struct Node
{
    char data;
    struct Node* left;
    struct Node* right;
} Node;

Node* insert(Node* root, char value);

Node* search(Node* root, char value);

int countNodes(Node* root);

int treeHeight(Node* root);

void inorder(Node* root);

void freeTree(Node* root);

#endif