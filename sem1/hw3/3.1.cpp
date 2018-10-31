#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int localMaxFinder(int array[], int length)
{
    for (int i = 1; i < length; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (array[i] == array[j])
            {
                return array[i];
            }
        }
    }
    cout << "error, restart the program and enter the correct element sequence\n";
    return -1; 
}

int main()
{
    printf("input the number of elements\n");
    int length = 0;
    scanf("%d", &length);
    int* array = new int[length]; 
    printf("input elements\n");
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &array[i]);
    }
    int localMax = localMaxFinder(array, length);
    for (int i = 1; i < length; i++)
    {
        bool isCurrentElementWasFoundMoreThanOnce = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (array[i] == array[j])
            {
                isCurrentElementWasFoundMoreThanOnce = 1;
            }
        }
        if ((isCurrentElementWasFoundMoreThanOnce) && (array[i] > localMax))
        {
            localMax = array[i];
        }
    }
    delete [] array;
    printf("%d\n", localMax);
} 