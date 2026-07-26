#include <stdlib.h>
#include "trees.h"

// Inserts a character into the binary search tree.
Node* insert(Node* root, char value)
{
    // Create a new node when an empty position is found.
    if (root == NULL)
    {
        Node* newNode = malloc(sizeof(Node));

        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    // Insert smaller values into the left subtree.
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    // Insert larger values into the right subtree.
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    // Return the unchanged root pointer.
    return root;
}