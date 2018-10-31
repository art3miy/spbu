#include <iostream>
using namespace std;

void printArray(int *array, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}

void readArray(int *array, int length)
{
	for (int i = 0; i < length; i++)
	{
		cin >> array[i];
	}
}

void siftDownElement(int *heap, int length, int elementIndex)
{
	int rootIndex = elementIndex;
	int leftChildIndex = 2 * elementIndex + 1;
	int rightChildIndex = 2 * elementIndex + 2;
	if (leftChildIndex < length && heap[leftChildIndex] > heap[rootIndex])
	{
		rootIndex = leftChildIndex;
	}
	if (rightChildIndex < length && heap[rightChildIndex] > heap[rootIndex])
	{
		rootIndex = rightChildIndex;
	}
	if (rootIndex != elementIndex)
	{
		swap(heap[rootIndex], heap[elementIndex]);
		siftDownElement(heap, length, rootIndex);
	}
}

void buildMaxHeap(int *heap, int length)
{
	for (int i = length - 1; i >= 0; i--)
	{
		siftDownElement(heap, length, i);
	}
}

void heapSort(int *array, int length)
{
	buildMaxHeap(array, length);
	for (int i = length - 1; i >= 0; i--)
	{
		swap(array[i], array[0]);
		siftDownElement(array, i, 0);
	}
}

int main(int argc, char const *argv[])
{
	int array[10000] = {};
	cout << "input length of your array\n";
	int length = 0;
	cin >> length;
	cout << "input elements of your array\n";
	readArray(array, length);
	heapSort(array, length);
	printArray(array, length);
	return 0;
} 