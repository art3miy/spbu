#include <iostream>
#include "stack.h"
using namespace std;

const int maxExpressionLength = 260;

void printExpression(char* expression, int length)
{
	for (int i = 0; i < length; ++i)
	{
		cout << expression[i] << " ";
	}
	cout << "\n";
}

void readExpression(char* expression)
{
	cin.getline(expression, maxExpressionLength);
}

void printStackReverse(Stack* stack)
{
	if (!stack->head)
	{
		cout << "error : stack is empty\n";
		return;
	}
	Stack* expression = createStack();
	StackElement* current = stack->head;
	while (current)
	{
		push(expression, current->value);
		current = current->next;
	}
	printStack(expression);
	deleteStack(expression);
}

void translateExpression(char* expression, Stack* result)
{
	Stack* operatorsStack = createStack();
	for (int i = 0; expression[i] != '\0'; ++i)
	{
		if (expression[i] >= '0' && expression[i] <= '9')
		{
			push(result, expression[i]);
		}
		else if (expression[i] == '(')
		{
			push(operatorsStack, expression[i]);
		}
		else if (expression[i] == ')')
		{
			if (!operatorsStack->head)
			{
				cout << "error with brackets!\n";
				return;
			}
			while (top(operatorsStack) != '(')
			{
				push(result, top(operatorsStack));
				pop(operatorsStack);
			}
			pop(operatorsStack);
		}
		else if (expression[i] == '+' || expression[i] == '-')
		{
			if (!operatorsStack->head)
			{
				push(operatorsStack, expression[i]);
			}
			else if (top(operatorsStack) == '+' || top(operatorsStack) == '-' || top(operatorsStack) == '*' || top(operatorsStack) == '/')
			{
				push(result, top(operatorsStack));
				pop(operatorsStack);
				push(operatorsStack, expression[i]);
			}
			else
			{
				push(operatorsStack, expression[i]);
			}
		}
		else if (expression[i] == '*' || expression[i] == '/')
		{
			if (!operatorsStack->head)
			{
				push(operatorsStack, expression[i]);
			}
			else if (top(operatorsStack) == '*' || top(operatorsStack) == '/')
			{
				push(result, top(operatorsStack));
				pop(operatorsStack);
				push(operatorsStack, expression[i]);
			}
			else if (top(operatorsStack) == '+' || top(operatorsStack) == '-')
			{
				push(operatorsStack, expression[i]);
			}
			else
			{
				push(operatorsStack, expression[i]);
			}
		}
	}
	while (operatorsStack->head)
	{
		push(result, top(operatorsStack));
		pop(operatorsStack);
	}
}

int main()
{
	cout << "input your expression (you can only use digits, '(' and ')' and arithmetic operators '+' '-' '*' '/')\n";
	char expression[maxExpressionLength] = {};
	Stack* result = createStack();
	readExpression(expression);
	translateExpression(expression, result);
	cout << "here is your expression now\n";
	printStackReverse(result);
	deleteStack(result);
	return 0;
}