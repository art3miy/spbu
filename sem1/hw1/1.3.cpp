#include <stdio.h>

void reverse(int array[], int leftBound, int rightBound)
{
    	const int middle = (leftBound + rightBound) / 2;
    	for (int i = leftBound, j = 0; i <= middle; i++, j++)
    	{
        	int tmp = array[i];
        	array[i] = array[rightBound - j];
        	array[rightBound - j] = tmp;
    	}
}

void readArray(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		scanf("%d", &array[i]);
	}
}

void printArray(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main()
{
	int mainArray[10000] = {0};
	printf("Enter n and m to swap first n elements of array with next m elements.\n");
	int firstArrayLength = 0;
	int secondArrayLength = 0;
	scanf("%d%d", &firstArrayLength, &secondArrayLength);
	const int mainArrayLength = firstArrayLength + secondArrayLength;
	printf("Now enter %d elements of array\n", mainArrayLength);
	readArray(mainArray, mainArrayLength);
	reverse(mainArray, 0, firstArrayLength - 1);
	reverse(mainArray, firstArrayLength, mainArrayLength - 1);
	reverse(mainArray, 0, mainArrayLength - 1);
	printArray(mainArray, mainArrayLength);
}