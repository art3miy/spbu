#pragma once

struct BinarySearchTreeNode
{
    int key;
    BinarySearchTreeNode *leftChild;
    BinarySearchTreeNode *rightChild;
};

struct BinarySearchTree
{
    BinarySearchTreeNode *root;
};

BinarySearchTree *createBst();
void deleteBst(BinarySearchTree *tree);

bool isFindInBst(BinarySearchTree *tree, int value);
void addToBst(BinarySearchTree *tree, int value);
void deleteFromBst(BinarySearchTree *tree, int value);
