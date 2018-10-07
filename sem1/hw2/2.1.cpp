#include <iostream>
using namespace std;

int fibRecursive(int n)
{
	if ((n == 1) || (n == 2))
	{
		return 1;
	}
	else
	{

		return fibRecursive(n - 1) + fibRecursive(n - 2);
	}
}

int fibIterative(int n)
{
	if ((n == 1) || (n == 2))
	{
		return 1;
	}
	int current = 1;
	int previous = 1;
	for (int counter = 2; counter < n; counter++)
	{
		int temp = previous;
		previous = current;
		current += temp;
	}
	return current;
}

int main(int argc, char const *argv[])
{
	int n = 0;
	cout << "input the number of fibonacci sequence element\n";
	cin >> n;
	cout << fibIterative(n) << " " << fibRecursive(n) << "\n";
	return 0;
}