#include <iostream>
using namespace std;

void printBinary(int number)
{
    for (int i = 8 * sizeof(number) - 1; i >= 0; --i)
    {
        cout << ((number >> i) & 1);
    }
    cout << "\n";
}

void convertToArray(int number, int *numberArray)
{
    for (int i = 8 * sizeof(number) - 1; i >= 0; --i)
    {
        int temp = (number >> i) & 1;
        numberArray[i] = temp;
    }
}

void printIntNumArray(int *numArray)
{
    for (int i = 0; i < 32; ++i)
    {
        cout << numArray[31 - i];
    }
}

void printSumBinary(int *firstNumArray, int *secondNumArray)
{
    int result[32] = {};
    int bonusValue = 0;
    for (int i = 0; i < 32; ++i)
    {
        int currentSum = firstNumArray[i] + secondNumArray[i] + bonusValue;
        result[i] = (currentSum <= 1) ? currentSum : (currentSum % 2);
        bonusValue = (currentSum <= 1) ? 0 : 1;
    }
    printIntNumArray(result);
}

int main()
{
    cout << "input first number\n";
    int val1 = 0;
    cin >> val1;
    cout << "input second number\n";
    int val2 = 0;
    cin >> val2;
    cout <<  "here is the first number in ";
    cout << ((val1 >= 0) ? "direct code\n" : "additional code\n");
    printBinary(val1);
    cout <<  "here is the second number in ";
    cout << ((val2 >= 0) ? "direct code\n" : "additional code\n");
    printBinary(val2);
    int firstNumArray[32] = {};
    convertToArray(val1, firstNumArray);
    int secondNumArray[32] = {};
    convertToArray(val2, secondNumArray);
    int sum = val1 + val2;
    cout << "this is the sum of your numbers in ";
    cout << ((sum >= 0) ? "direct code\n" : "additional code\n");
    printSumBinary(firstNumArray, secondNumArray);
}
