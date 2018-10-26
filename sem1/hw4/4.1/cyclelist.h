#pragma once

struct ListElement
{
    int value;
    ListElement* next;
};

struct List
{
    ListElement* head;
};

List* createCycleList();

void add(List* list, int value);

void deleteFrom(List* list, int index);

void printCycleList(List* list);

int size(List* list);

void deleteCycleList(List* list);