#include <iostream>

double power(double a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        double halfPower = power(a, n / 2);
        return halfPower * halfPower;
    }
    else if (n > 0)
    {
        return a * power(a, n - 1);
    }
    else
    {
        return 1 / power(a, -n);
    }
}

int main()
{
    double a = 0;
    int n = 0;
    std::cin >> a >> n;
    std::cout << power(a, n);
    return 0;
}