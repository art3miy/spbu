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
	int array[10000] = {};
	cout << "input the length of array\n";
	int length = 0;
	cin >> length;
	cout << "input the elements of array\n";
	for (int i = 0; i < length; i++)
	{
		cin >> array[i];
	}
	cout << "input the left and right borders of sorting (1, 2, 3 ... length)\n";
	int leftBound = 0;
	int rightBound = 0;
	cin >> leftBound >> rightBound;
	leftBound--;
	rightBound--;
	quicksort(array, leftBound, rightBound);
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	return 0;
}