#include <iostream>
using namespace std;

void merge(int* array1, int* array2, int length1, int length2, int* result)
{
	int i = 0, j = 0, k = 0;
	while ((i < length1) && (j < length2))
	{
		if (array1[i] > array2[j])
		{
			result[k] = array1[i];
			i++;
			k++;
		}
		else
		{
			result[k] = array2[j];
			j++;
			k++;
		}
	}
	if (i == length1)
	{
		for (;j < length2; j++)
		{
			result[k] = array2[j];
			k++;
		}
	}
	else if (j == length2)
	{
		for (;i < length1; i++)
		{
			result[k] = array1[i];
			k++;
		}
	}
}

int main(int argc, char const *argv[])
{
	int stack1[10000] = {};
	int stack2[10000] = {};
	cout << "input length of the Vasya`s stack\n";
	int length1 = 0;
	cin >> length1;
	cout << "input the elements of the Vasya`s stack\n";
	for (int i = 0; i < length1; i++)
	{
		cin >> stack1[i];
	}
	cout << "input length of the Petya`s stack\n";
	int length2 = 0;
	cin >> length2;
	cout << "input the elements of the Petya`s stack\n";
	for (int i = 0; i < length2; i++)
	{
		cin >> stack2[i];
	}
	int mergedStack[20000] = {};
	merge(stack1, stack2, length1, length2, mergedStack);
	const int resultLength = length1 + length2;
	for (int i = 0; i < resultLength; i++)
	{
		cout << mergedStack[i] << " ";
	}
	return 0;
}