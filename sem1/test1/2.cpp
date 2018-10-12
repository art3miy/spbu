#include <iostream>
using namespace std;

void readArray(int *array, int length)
{
	for (int i = 0; i < length; i++)
	{
		cin >> array[i];
	}	
}

void printArray(int *array, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}

void insertionSort(int* array, int length)
{
	for (int i = 2; i < length; i += 2)
	{
		int j = i - 2;
		while ((array[i] < array[j]) && (j >= 0) && (i >= 0))
		{
			swap(array[i], array[j]);
			i = j;
			j -= 2;
		}
	}
}

void randomGeneration(int *array, int length)
{
	for (int i = 0; i < length; i++)
	{
		int temp = rand() % 33 + 11;
		array[i] = temp;
	}
}



int main(int argc, char const *argv[])
{
	int array[10000];
	cout << "input length of array\n";
	int length = 0;
	cin >> length;
	cout << "input elements of array\n";
	readArray(array, length);
	insertionSort(array, length);
	printArray(array, length);
	cout << "input length of the second array (randomly generated)\n";
	int length2 = 0;
	cin >> length2;
	randomGeneration(array, length2);
	cout << "this is array before sorting\n";
	printArray(array, length2);
	insertionSort(array, length2);
	cout << "this is array after sorting\n";
	printArray(array,length2);
	return 0;
}