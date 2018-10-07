#include <iostream>

int main()
{
    int n = 0;
    std::cout << "Enter the value of n variable\n";
    std::cin >> n;
    bool isComposite[1000000] = {false};
    for (int i = 2; i <= n; i++)
    {
        if (!isComposite[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isComposite[j] = true;
            }
        }
    }
    std::cout << "All prime numbers that are not bigger than " << n << " are: ";
    for (int i = 2; i <= n; i++)
    {
        if (!isComposite[i])
        {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";
    return 0;
}