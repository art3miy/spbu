#include "bst.h"
#include <iostream>
#include "set.h"
using namespace std;

Set *createSet()
{
    BinarySearchTree *tree = createBst();
    return new Set {tree};
}

bool isFindInSet(Set *set, int value)
{
    return isFindInBst(set->tree, value);
}

void addToSet(Set *set, int value)
{
    addToBst(set->tree, value);
}

void deleteFromSet(Set *set, int value)
{
    deleteFromBst(set->tree, value);
}

void deleteSet(Set *set)
{
    deleteBst(set->tree);
    delete set;
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

void printIncreasingOrder(Set *set)
{
    printIncreasingOrder(set->tree->root);
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

void printDecreasingOrder(Set *set)
{
    printDecreasingOrder(set->tree->root);
    cout << "\n";
}

void printInABCFormat(BinarySearchTreeNode *node)
{
    cout << " ";
    if (!node)
    {
        cout << "null";
    }
    else
    {
        cout << "(" << node->key;
        printInABCFormat(node->leftChild);
        printInABCFormat(node->rightChild);
        cout << ")";
    }
}

void printInABCFormat(Set *set)
{
    printInABCFormat(set->tree->root);
    cout << "\n";
}
