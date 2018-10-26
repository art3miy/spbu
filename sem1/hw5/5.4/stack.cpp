#include <iostream>
#include "stack.h"
using namespace std;

Stack* createStack()
{
    return new Stack {nullptr};
}

void push(Stack* stack, double value)
{
    if (stack->head == nullptr)
    {
        stack->head = new StackElement {value, nullptr};
    }
    else
    {
        StackElement* firstElement = stack->head;
        stack->head = new StackElement {value, firstElement};
    }
}

void printStack(Stack* stack)
{
    if (stack->head == nullptr)
    {
        cout << "error : stack is empty";
        return;
    }
    else
    {
        StackElement* current = stack->head;
        while (current)
        {
            cout << current->value << " ";
            current = current->next;
        }
    }
    cout << "\n";
}

void pop(Stack* stack)
{
    if (stack->head == nullptr)
    {
        cout << "error : stack is empty\n";
        return;
    }
    else
    {
        StackElement* nextElement = stack->head->next;
        delete stack->head;
        stack->head = nextElement;
    }
}

int size(Stack* stack)
{
    if (stack->head == nullptr)
    {
        return 0;
    }
    else
    {
        StackElement* current = stack->head;
        int count = 0;
        while (current)
        {
            ++count;
            current = current->next;
        }
        return count;
    }
}

double top(Stack* stack)
{
    if (stack->head)
    {
        return stack->head->value;
    }
    else
    {
        cout << "error\n";
        return -1;
    }
}

void deleteStack(Stack* stack)
{
    if (stack->head == nullptr)
    {
        cout << "error : stack is already empty\n";
        return;
    }
    else
    {
        StackElement* current = stack->head;
        while (current)
        {
            StackElement* nextElement = current->next;
            delete current;
            current = nextElement;
        }
        delete stack;
    }
}