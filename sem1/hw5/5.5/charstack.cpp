#include <iostream>
#include "charstack.h"
using namespace std;

CharStack* createCharStack()
{
	return new CharStack{ nullptr };
}

void pushCharStack(CharStack* stack, char value)
{
	if (stack->head == nullptr)
	{
		stack->head = new CharStackElement{ value, nullptr };
	}
	else
	{
		CharStackElement* firstElement = stack->head;
		stack->head = new CharStackElement{ value, firstElement };
	}
}

void printCharStack(CharStack* stack)
{
	if (stack->head == nullptr)
	{
		cout << "error : stack is empty";
		return;
	}
	else
	{
		CharStackElement* current = stack->head;
		while (current)
		{
			cout << current->value << " ";
			current = current->next;
		}
	}
	cout << "\n";
}

void popCharStack(CharStack* stack)
{
	if (stack->head == nullptr)
	{
		cout << "error : stack is empty\n";
		return;
	}
	else
	{
		CharStackElement* nextElement = stack->head->next;
		delete stack->head;
		stack->head = nextElement;
	}
}

int sizeCharStack(CharStack* stack)
{
	if (stack->head == nullptr)
	{
		return 0;
	}
	else
	{
		CharStackElement* current = stack->head;
		int count = 0;
		while (current)
		{
			++count;
			current = current->next;
		}
		return count;
	}
}

char topCharStack(CharStack* stack)
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

void deleteCharStack(CharStack* stack)
{
	if (stack->head == nullptr)
	{
		cout << "error : stack is already empty\n";
		return;
	}
	else
	{
		CharStackElement* current = stack->head;
		while (current)
		{
			CharStackElement* nextElement = current->next;
			delete current;
			current = nextElement;
		}
		delete stack;
	}
}