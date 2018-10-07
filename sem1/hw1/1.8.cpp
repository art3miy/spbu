#include <iostream>

int recursive(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * recursive(n - 1);
    }
}

int iterative(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res *= i;
    }
    return res;
}

int main()
{
    int x = 0;
    std::cin >> x;
    std::cout << recursive(x) << " " << iterative(x);
    return 0;
}