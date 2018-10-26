#include <iostream>
using namespace std;

int partition(int *array, int leftBound, int rightBound)
{
	int pivot = array[leftBound];
	int j = leftBound;
	for (int i = leftBound + 1; i <= rightBound; i++)
	{
		if (array[i] <= pivot)
		{
			j++;
			swap(array[i], array[j]);
		}
	}
	swap(array[leftBound], array[j]);
	return j;
}

void quicksort(int *array, int leftBound, int rightBound)
{
	if (leftBound >= rightBound)
	{
		return;
	}
	int middle = partition(array, leftBound, rightBound);
	quicksort(array, leftBound, middle - 1);
	quicksort(array, middle + 1, rightBound);
}

int main(int argc, char const *argv[])
{
	int numberDigits[10000] = {};
	cout << "input the natural number\n";
	int number = 0;
	cin >> number;
	int digitCounter = 0;
	int zeroCounter = 0;
	while (number > 0)
	{
		if (number % 10 != 0)
		{
			numberDigits[digitCounter] = number % 10;
			number /= 10;
			digitCounter++;
		}
		else
		{
			zeroCounter++;
			number /= 10;
		}
	}
	quicksort(numberDigits, 0, digitCounter - 1);
	if (digitCounter == 1)
	{
		cout << numberDigits[0];
		for (int j = 0; j < zeroCounter; j++)
		{
			cout << 0;
		}
	}
	else
	{
		for (int i = 0; i < digitCounter; i++)
		{
			if (i == 1)
			{
				for (int j = 0; j < zeroCounter; j++)
				{
					cout << 0;
				}
			}
			cout << numberDigits[i];
		}
	}
	return 0;
} 