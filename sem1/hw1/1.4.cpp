#include <iostream>

int main()
{
    int sums[28] = {0};
    const int numberOfDigits = 10;
    for (int i = 0; i < numberOfDigits; i++)
    {
        for (int j = 0; j < numberOfDigits; j++)
        {
            for (int k = 0; k < numberOfDigits; k++)
            {
                sums[i + j + k]++;
            }
        }
    }
    int answer = 0;
    const int numberOfSums = 28;
    for (int i = 0; i < numberOfSums; i++)
    {
        answer += sums[i] * sums[i];
    }
    std::cout << "There are " << answer << " six digits lucky tickets\n";
    return 0;
}