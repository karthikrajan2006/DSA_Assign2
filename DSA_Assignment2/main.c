#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "trees.h"

int main(void)
{
    Node* root = NULL;

    // Seed random number generator.
    srand((unsigned int)time(NULL));

    // Generate random number of characters from 11 to 20.
    int numberOfChars = rand() % 10 + 11;

    printf("Characters inserted:\n");

    // Insert random lowercase letters.
    for (int i = 0; i < numberOfChars; i++)
    {
        char randomChar = 'a' + rand() % 26;

        printf("%c ", randomChar);

        root = insert(root, randomChar);
    }

    printf("\n\nCharacters in alphabetical order:\n");

    // Display BST using inorder traversal.
    inorder(root);

    printf("\n\nNumber of nodes: %d\n", countNodes(root));

    printf("Tree height: %d\n", treeHeight(root));

    // Release allocated memory.
    freeTree(root);

    return 0;
}