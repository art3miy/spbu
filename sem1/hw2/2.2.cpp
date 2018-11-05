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

void printAllUniquePartitions(int n)
{
	int* partition = new int[n];
	int currentIndex = 0; // all elements with indexes from 0 to currentIndex make up a current partition
	partition[currentIndex] = n;
	while (true)
	{
		int currentLength = currentIndex + 1;
		printArray(partition, currentLength);
		int remainingValue = 0;
		while (currentIndex >= 0 && partition[currentIndex] == 1)
		{
			remainingValue += partition[currentIndex];
			currentIndex--;
		}
		if (currentIndex < 0)
		{
			delete [] partition;
			return;
		}
		partition[currentIndex]--;
		remainingValue++;
		while (remainingValue > partition[currentIndex])
		{
			partition[currentIndex + 1] = partition[currentIndex];
			remainingValue -= partition[currentIndex];
			currentIndex++;
		}
		partition[currentIndex + 1] = remainingValue;
		currentIndex++;
	}
	delete [] partition;
}

int main(int argc, char const *argv[])
{
	cout << "input the natural number\n";
	int n = 0;
	cin >> n;
	cout << "there are all integer partitions of this number:\n";
	printAllUniquePartitions(n);
	return 0;
} 