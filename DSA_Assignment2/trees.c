#include <stdio.h>
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
    // Insert larger values and duplicates into the right subtree.
    else
    {
        root->right = insert(root->right, value);
    }

    // Return the root node after insertion.
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

    // Return node when the value is found.
    if (root->data == value)
    {
        return root;
    }

    // Search left subtree for smaller values.
    if (value < root->data)
    {
        return search(root->left, value);
    }

    // Search right subtree for larger values.
    return search(root->right, value);
}


// Counts the number of nodes in the tree.
int countNodes(Node* root)
{
    // Empty branches contain no nodes.
    if (root == NULL)
    {
        return 0;
    }

    // Count current node and both subtrees.
    return 1 + countNodes(root->left) + countNodes(root->right);
}


// Calculates the height of the tree.
int treeHeight(Node* root)
{
    // Empty tree has height -1.
    if (root == NULL)
    {
        return -1;
    }

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    // Return the larger subtree height.
    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }
    else
    {
        return rightHeight + 1;
    }
}


// Prints nodes using inorder traversal.
void inorder(Node* root)
{
    // Stop when reaching an empty branch.
    if (root == NULL)
    {
        return;
    }

    // Visit left subtree first.
    inorder(root->left);

    // Print current node.
    printf("%c ", root->data);

    // Visit right subtree last.
    inorder(root->right);
}


// Releases all allocated tree memory.
void freeTree(Node* root)
{
    // Stop when reaching an empty branch.
    if (root == NULL)
    {
        return;
    }

    // Free child nodes before freeing parent.
    freeTree(root->left);
    freeTree(root->right);

    free(root);
}