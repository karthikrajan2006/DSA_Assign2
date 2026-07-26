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


// Searches the tree for a specific character.
Node* search(Node* root, char value)
{
    // Stop searching if the node does not exist.
    if (root == NULL)
    {
        return NULL;
    }

    // Return the node when the value is found.
    if (root->data == value)
    {
        return root;
    }

    // Search the left subtree for smaller values.
    if (value < root->data)
    {
        return search(root->left, value);
    }

    // Search the right subtree for larger values.
    return search(root->right, value);
}


// Counts the number of nodes in the tree.
int countNodes(Node* root)
{
    // Empty branches do not contain nodes.
    if (root == NULL)
    {
        return 0;
    }

    // Count current node plus left and right subtrees.
    return 1 + countNodes(root->left) + countNodes(root->right);
}