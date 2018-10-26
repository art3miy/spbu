#include <iostream>
#include "doublestack.h"
#include "charstack.h"
using namespace std;

void readExpression(char* expression)
{
    cin.getline(expression, 255);
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

void translateExpression(char* expression, CharStack* result)
{
    CharStack* operatorsStack = createCharStack();
    for (int i = 0; expression[i] != '\0'; ++i)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            pushCharStack(result, expression[i]);
        }
        else if (expression[i] == '(')
        {
            pushCharStack(operatorsStack, expression[i]);
        }
        else if (expression[i] == ')')
        {
            if (!operatorsStack->head)
            {
                cout << "error with brackets!\n";
                return;
            }
            while (topCharStack(operatorsStack) != '(')
            {
                pushCharStack(result, topCharStack(operatorsStack));
                popCharStack(operatorsStack);
            }
            popCharStack(operatorsStack);
        }
        else if (expression[i] == '+' || expression[i] == '-')
        {
            if (!operatorsStack->head)
            {
                pushCharStack(operatorsStack, expression[i]);
            }
            else if (topCharStack(operatorsStack) == '+' || topCharStack(operatorsStack) == '-' ||
            topCharStack(operatorsStack) == '*' || topCharStack(operatorsStack) == '/')
            {
                pushCharStack(result, topCharStack(operatorsStack));
                popCharStack(operatorsStack);
                pushCharStack(operatorsStack, expression[i]);
            }
            else
            {
                pushCharStack(operatorsStack, expression[i]);
            }
        }
        else if (expression[i] == '*' || expression[i] == '/')
        {
            if (!operatorsStack->head)
            {
                pushCharStack(operatorsStack, expression[i]);
            }
            else if (topCharStack(operatorsStack) == '*' || topCharStack(operatorsStack) == '/')
            {
                pushCharStack(result, topCharStack(operatorsStack));
                popCharStack(operatorsStack);
                pushCharStack(operatorsStack, expression[i]);
            }
            else if (topCharStack(operatorsStack) == '+' || topCharStack(operatorsStack) == '-')
            {
                pushCharStack(operatorsStack, expression[i]);
            }
            else
            {
                pushCharStack(operatorsStack, expression[i]);
            }
        }
    }
    while (operatorsStack->head)
    {
        pushCharStack(result, topCharStack(operatorsStack));
        popCharStack(operatorsStack);
    }
}

double calculateExpression(char* expression)
{
    DoubleStack *stack = createDoubleStack();
    for (int i = 0; expression[i] != '\0'; ++i)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            pushDoubleStack(stack, expression[i] - '0');
        } else if (expression[i] == '+')
        {
            double sum = 0;
            sum = topDoubleStack(stack);
            popDoubleStack(stack);
            sum += topDoubleStack(stack);
            popDoubleStack(stack);
            pushDoubleStack(stack, sum);
        } else if (expression[i] == '*')
        {
            double composition = 0;
            composition = topDoubleStack(stack);
            popDoubleStack(stack);
            composition *= topDoubleStack(stack);
            popDoubleStack(stack);
            pushDoubleStack(stack, composition);
        } else if (expression[i] == '/')
        {
            double quotient = 0;
            quotient = 1 / topDoubleStack(stack);
            popDoubleStack(stack);
            quotient *= topDoubleStack(stack);
            popDoubleStack(stack);
            pushDoubleStack(stack, quotient);
        } else if (expression[i] == '-')
        {
            double difference = 0;
            difference = -topDoubleStack(stack);
            popDoubleStack(stack);
            difference += topDoubleStack(stack);
            popDoubleStack(stack);
            pushDoubleStack(stack, difference);
        }
    }
    double result = topDoubleStack(stack);
    deleteDoubleStack(stack);
    return result;
}
int main()
{
    cout << "input your expression (you can only use digits, '(' and ')' and arithmetic operators '+' '-' '*' '/')\n";
    char expression[255] = {};
    CharStack* result = createCharStack();
    readExpression(expression);
    translateExpression(expression, result);
    char* translatedExpression = transferIntoArray(result);
    deleteCharStack(result);
    cout << "this is value of your expression : " << calculateExpression(translatedExpression) << "\n";
    return 0;
}