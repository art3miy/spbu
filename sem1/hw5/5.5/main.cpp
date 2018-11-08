#include <iostream>
#include "doublestack.h"
#include "charstack.h"
#include "stackcalculator.h"
using namespace std;

const int maxExpressionSize = 260;

void readExpression(char* expression)
{
	cin.getline(expression, maxExpressionSize);
}

char* transferIntoArray(CharStack* stack)
{
	if (!stack->head)
	{
		cout << "error : stack is empty\n";
		return nullptr;
	}
	const int sizeOfStack = sizeCharStack(stack);
	char* expression = new char[sizeOfStack];
	int index = 0;
	CharStackElement* current = stack->head;
	while (current)
	{
		expression[sizeOfStack - index - 1] = current->value;
		current = current->next;
		++index;
	}
	return expression;
}

int main()
{
	cout << "input your expression (you can only use digits, '(' and ')' and arithmetic operators '+' '-' '*' '/')\n";
	char expression[maxExpressionSize] = {};
	CharStack* result = createCharStack();
	readExpression(expression);
	translateExpression(expression, result);
	char* translatedExpression = transferIntoArray(result);
	deleteCharStack(result);
	cout << "this is value of your expression : " << calculateExpression(translatedExpression) << "\n";
	return 0;
}