#pragma once
#include "bst.h"

struct Set
{
    BinarySearchTree *tree;
};

Set *createSet();
void deleteSet(Set *set);

void printIncreasingOrder(Set *set);
void printDecreasingOrder(Set *set);
void printInABCFormat(Set *set);

bool isFindInSet(Set *set, int value);
void addToSet(Set *set, int value);
void deleteFromSet(Set *set, int value);
