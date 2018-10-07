#include <iostream>

int main()
{
    int x = 0;
    std::cout << "enter the value of x variable\n";
    std::cin >> x;
    const int xSquared = x * x;
    const int value = (xSquared + x) * (xSquared + 1) + 1;
    std::cout << "x^4 + x^3 + x^2 + x + 1 = " << value << "\n";
    return 0;
}