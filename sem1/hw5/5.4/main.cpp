#include <iostream>
#include "stack.h"
using namespace std;

const int maxExpressionSize = 260;

void readExpression(char* expression)
{
	cin.getline(expression, maxExpressionSize);
}

double calculateExpression(char* expression)
{
	Stack* stack = createStack();
	for (int i = 0; expression[i] != '\0'; ++i)
	{
		if (expression[i] >= '0' && expression[i] <= '9')
		{
			push(stack, expression[i] - '0');
		}
		else if (expression[i] == '+')
		{
			double sum = 0;
			sum = top(stack);
			pop(stack);
			sum += top(stack);
			pop(stack);
			push(stack, sum);
		}
		else if (expression[i] == '*')
		{
			double composition = 0;
			composition = top(stack);
			pop(stack);
			composition *= top(stack);
			pop(stack);
			push(stack, composition);
		}
		else if (expression[i] == '/')
		{
			double quotient = 0;
			quotient = 1 / top(stack);
			pop(stack);
			quotient *= top(stack);
			pop(stack);
			push(stack, quotient);
		}
		else if (expression[i] == '-')
		{
			double difference = 0;
			difference = -top(stack);
			pop(stack);
			difference += top(stack);
			pop(stack);
			push(stack, difference);
		}
	}
	double result = top(stack);
	deleteStack(stack);
	return result;
}

int main()
{
	char expression[maxExpressionSize] = {};
	cout << "input the expression (you can use only digits and only this operations '+' '-' '*' '/')\n";
	readExpression(expression);
	cout << "here is the result of calculation of your expression\n";
	cout << calculateExpression(expression);
	calculateExpression(expression);
	return 0;
}
