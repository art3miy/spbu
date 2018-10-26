#pragma once

struct StackElement
{
    double value;
    StackElement* next;
};

struct Stack
{
    StackElement* head;
};

Stack* createStack();

void deleteStack(Stack* stack);

void push(Stack* stack, double value);

void pop(Stack* stack);

void printStack(Stack* stack);

double top(Stack* stack);

int size(Stack* stack);
