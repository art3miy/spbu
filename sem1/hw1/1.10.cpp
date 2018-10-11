#include <iostream>
using namespace std;

int main()
{
	char string[10000] = {};
	cout << "input length of the string (length > 1)\n";
	int length = 0;
	cin >> length;
	if (length <= 1)
	{
		if (length >= 0)
		{
			cout << "this will be palindrome\n";
			return 0;
		}
		else
		{
			cout << "it`s not correct\n";
			return 0;
		}		
	}
	cout << "input string without spaces\n";
	for (int i = 0; i < length; i++)
	{
		cin >> string[i];
	}
	const int middleIndex = length / 2;
	for (int i = 0; i < middleIndex; i++)
	{
		if (string[i] != string[length - 1 - i])
		{
			cout << "this string is not palindrome\n";
			return 0;
		}
	}
	cout << "this string is palindrome\n";
	return 0;
}