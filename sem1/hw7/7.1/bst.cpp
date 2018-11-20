#include "bst.h"
#include <iostream>
using namespace std;

BinarySearchTree *createBst()
{
    return new BinarySearchTree {nullptr};
}

void deleteBst(BinarySearchTreeNode *&node)
{
    if (node)
    {
        deleteBst(node->leftChild);
        deleteBst(node->rightChild);
        delete node;
        node = nullptr;
    }
}

void deleteBst(BinarySearchTree *tree)
{
    deleteBst(tree->root);
}

bool isFindInBst(BinarySearchTreeNode *node, int value)
{
    if (!node)
    {
        return false;
    }
    else if (node->key == value)
    {
        return true;
    }
    else if (node->key > value)
    {
        return isFindInBst(node->leftChild, value);
    }
    else if (node->key < value)
    {
        return isFindInBst(node->rightChild, value);
    }
    else
    {
        cout << "impossible!!\n";
        return false;
    }
}

bool isFindInBst(BinarySearchTree *tree, int value)
{
    return isFindInBst(tree->root, value);
}

void addToBst(BinarySearchTreeNode *&node, int value)
{
    if (!node)
    {
        node = new BinarySearchTreeNode {value, nullptr, nullptr};
    }
    else if (node->key == value)
    {
        return;
    }
    else if (node->key > value)
    {
        addToBst(node->leftChild, value);
    }
    else if (node->key < value)
    {
        addToBst(node->rightChild, value);
    }
    else
    {
        cout << "impossible!!\n";
        return;
    }
}

void addToBst(BinarySearchTree *tree, int value)
{
    addToBst(tree->root, value);
}

int deleteMin(BinarySearchTreeNode *&node)
{
    if (!node->leftChild)
    {
        int deletedValue = node->key;
        BinarySearchTreeNode *temp = node->rightChild;
        delete node;
        node = temp;
        return deletedValue;
    }
    else
    {
        return deleteMin(node->leftChild);
    }
}

void deleteFromBst(BinarySearchTreeNode *&node, int value)
{
    if (!node)
    {
        return;
    }
    else if (node->key == value && !node->leftChild && !node->rightChild)
    {
        delete node;
        node = nullptr;
    }
    else if (node->key == value && !node->leftChild && node->rightChild)
    {
        BinarySearchTreeNode *temp = node->rightChild;
        delete node;
        node = temp;
    }
    else if (node->key == value && node->leftChild && !node->rightChild)
    {
        BinarySearchTreeNode *temp = node->leftChild;
        delete node;
        node = temp;
    }
    else if (node->key == value && node->leftChild && node->rightChild)
    {
        node->key = deleteMin(node->rightChild);
    }
    else if (node->key > value)
    {
        deleteFromBst(node->leftChild, value);
    }
    else if (node->key < value)
    {
        deleteFromBst(node->rightChild, value);
    }
    else
    {
        cout << "impossible!!!";
        return;
    }
}

void deleteFromBst(BinarySearchTree *tree, int value)
{
    if (isFindInBst(tree, value))
    {
        deleteFromBst(tree->root, value);
    }
}
