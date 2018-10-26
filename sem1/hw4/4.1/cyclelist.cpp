#include <iostream>
#include "cyclelist.h"
using namespace std;

List* createCycleList()
{
    return new List {nullptr};
}

void deleteCycleList(List* list)
{
    ListElement* current = list->head->next;
    while (current != list->head)
    {
        ListElement* nextElement = current->next;
        delete current;
        current = nextElement;
    }
    delete list->head;
    delete list;
}

void add(List* list, int value)
{
    if (list->head == nullptr)
    {
        ListElement* newElement = new ListElement {value, nullptr};
        newElement->next = newElement;
        delete list->head;
        list->head = newElement;
        return;
    }
    ListElement* current = list->head;
    while (current->next != list->head)
    {
        current = current->next;
    }
    ListElement* newElement = new ListElement {value, list->head};
    current->next = newElement;
}

int size(List* list)
{
    if (list->head)
    {
        if (list->head == list->head->next)
        {
            return 1;
        }
        else
        {
            int count = 1;
            ListElement* current = list->head->next;
            while (current != list->head)
            {
                ++count;
                current = current->next;
            }
            return count;
        }
    }
    return 0;
}

void printCycleList(List* list)
{
    if (list->head)
    {
        ListElement* current = list->head;
        cout << current->value << " ";
        current = current->next;
        while (current != list->head)
        {
            cout << current->value << " ";
            current = current->next;
        }
    }
    cout << "\n";
}

void deleteFrom(List* list, int index)
{
    if (list->head)
    {
        if (size(list) == 1)
        {
            delete list->head;
            list->head = nullptr;
            return;
        }
        if (index == 1)
        {
            ListElement* last = list->head->next;
            while (last->next != list->head)
            {
                last = last->next;
            }
            ListElement* nextElement = list->head->next;
            delete list->head;
            list->head = nextElement;
            last->next = list->head;
            return;
        }
        ListElement *current = list->head;
        int count = 1;
        while (count != index - 1)
        {
            ++count;
            current = current->next;
        }
        if (current->next != list->head)
        {
            ListElement *afterNextElement = current->next->next;
            delete current->next;
            current->next = afterNextElement;
        }
        else
        {
            ListElement *afterNextElement = current->next->next;
            delete current->next;
            current->next = afterNextElement;
            list->head = afterNextElement;
        }
    }
}