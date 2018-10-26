#pragma once

struct StackElement
{
    char value;
    StackElement* next;
};

struct Stack
{
    StackElement* head;
};

Stack* createStack();

void deleteStack(Stack* stack);

void push(Stack* stack, char value);

void pop(Stack* stack);

void printStack(Stack* stack);

char top(Stack* stack);

int size(Stack* stack);
