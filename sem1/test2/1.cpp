#include <iostream>
using namespace std;

int fibonacci(int number)
{
    if ((number == 1) || (number == 2))
    {
        return 1;
    }
    int current = 1;
    int previous = 1;
    for (int counter = 2; counter < number; counter++)
    {
        int temp = previous;
        previous = current;
        current += temp;
    }
    return current;
}

int main()
{
    cout << "input number\n";
    int number = 0;
    cin >> number;
    cout << "this is the " << number << "-th fibonacci number : " << fibonacci(number);
    return 0;
}
