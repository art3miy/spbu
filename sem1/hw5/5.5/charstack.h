#pragma once

struct CharStackElement
{
    char value;
    CharStackElement* next;
};

struct CharStack
{
    CharStackElement* head;
};

CharStack* createCharStack();

void deleteCharStack(CharStack* stack);

void pushCharStack(CharStack* stack, char value);

void popCharStack(CharStack* stack);

void printCharStack(CharStack* stack);

char topCharStack(CharStack* stack);

int sizeCharStack(CharStack* stack);
