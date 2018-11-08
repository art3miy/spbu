#include <iostream>
#include "doublestack.h"
using namespace std;

DoubleStack* createDoubleStack()
{
	return new DoubleStack{ nullptr };
}

void pushDoubleStack(DoubleStack* stack, double value)
{
	if (stack->head == nullptr)
	{
		stack->head = new DoubleStackElement{ value, nullptr };
	}
	else
	{
		DoubleStackElement* firstElement = stack->head;
		stack->head = new DoubleStackElement{ value, firstElement };
	}
}

void printDoubleStack(DoubleStack* stack)
{
	if (stack->head == nullptr)
	{
		cout << "error : stack is empty";
		return;
	}
	else
	{
		DoubleStackElement* current = stack->head;
		while (current)
		{
			cout << current->value << " ";
			current = current->next;
		}
	}
	cout << "\n";
}

void popDoubleStack(DoubleStack* stack)
{
	if (stack->head == nullptr)
	{
		cout << "error : stack is empty\n";
		return;
	}
	else
	{
		DoubleStackElement* nextElement = stack->head->next;
		delete stack->head;
		stack->head = nextElement;
	}
}

int sizeDoubleStack(DoubleStack* stack)
{
	if (stack->head == nullptr)
	{
		return 0;
	}
	else
	{
		DoubleStackElement* current = stack->head;
		int count = 0;
		while (current)
		{
			++count;
			current = current->next;
		}
		return count;
	}
}

double topDoubleStack(DoubleStack* stack)
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

void deleteDoubleStack(DoubleStack* stack)
{
	if (stack->head == nullptr)
	{
		cout << "error : stack is already empty\n";
		return;
	}
	else
	{
		DoubleStackElement* current = stack->head;
		while (current)
		{
			DoubleStackElement* nextElement = current->next;
			delete current;
			current = nextElement;
		}
		delete stack;
	}
}