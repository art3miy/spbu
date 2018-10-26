#pragma once

struct DoubleStackElement
{
    double value;
    DoubleStackElement* next;
};

struct DoubleStack
{
    DoubleStackElement* head;
};

DoubleStack* createDoubleStack();

void deleteDoubleStack(DoubleStack* stack);

void pushDoubleStack(DoubleStack* stack, double value);

void popDoubleStack(DoubleStack* stack);

void printDoubleStack(DoubleStack* stack);

double topDoubleStack(DoubleStack* stack);

int sizeDoubleStack(DoubleStack* stack);
