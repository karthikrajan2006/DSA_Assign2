#ifndef TREES_H
#define TREES_H

// Node used in the binary search tree.
typedef struct Node
{
    char data;
    struct Node* left;
    struct Node* right;
} Node;

#endif