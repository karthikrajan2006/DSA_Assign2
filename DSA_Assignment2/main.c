#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "trees.h"

int main(void)
{
    Node* root = NULL;

    // Seed random number generator.
    srand((unsigned int)time(NULL));

    // Generate a random number between 11 and 20.
    int numberOfChars = rand() % 10 + 11;

    // Insert random characters into the tree.
    for (int i = 0; i < numberOfChars; i++)
    {
        char randomChar = 'a' + rand() % 26;

        root = insert(root, randomChar);
    }

    return 0;
}