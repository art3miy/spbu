#pragma once
#include "bst.h"

BinarySearchTree *createSet();
void deleteSet(BinarySearchTree *set);

void printIncreasingOrder(BinarySearchTree *set);
void printDecreasingOrder(BinarySearchTree *set);
void printSetParsing(BinarySearchTree *set);

bool isFindInSet(BinarySearchTree *set, int value);
void addToSet(BinarySearchTree *set, int value);
void deleteFromSet(BinarySearchTree *set, int value);
