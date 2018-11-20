#include "bst.h"
#include <iostream>
#include "set.h"
using namespace std;

BinarySearchTree *createSet()
{
    return createBst();
}

void deleteSet(BinarySearchTree *set)
{
    deleteBst(set);
}

bool isFindInSet(BinarySearchTree *set, int value)
{
    return isFindInBst(set, value);
}

void addToSet(BinarySearchTree *set, int value)
{
    addToBst(set, value);
}

void deleteFromSet(BinarySearchTree *set, int value)
{
    deleteFromBst(set, value);
}

void printIncreasingOrder(BinarySearchTreeNode *node)
{
    if (node)
    {
        printIncreasingOrder(node->leftChild);
        cout << node->key << " ";
        printIncreasingOrder(node->rightChild);
    }
}

void printIncreasingOrder(BinarySearchTree *set)
{
    printIncreasingOrder(set->root);
    cout << "\n";
}

void printDecreasingOrder(BinarySearchTreeNode *node)
{
    if (node)
    {
        printDecreasingOrder(node->rightChild);
        cout << node->key << " ";
        printDecreasingOrder(node->leftChild);
    }
}

void printDecreasingOrder(BinarySearchTree *set)
{
    printDecreasingOrder(set->root);
    cout << "\n";
}

void printSetParsing(BinarySearchTreeNode *node)
{
    cout << " ";
    if (!node)
    {
        cout << "null";
    }
    else
    {
        cout << "(" << node->key;
        printSetParsing(node->leftChild);
        printSetParsing(node->rightChild);
        cout << ")";
    }
}

void printSetParsing(BinarySearchTree *set)
{
    printSetParsing(set->root);
}
