#include <iostream>
using namespace std;

void countSymbolsOfTheString(int *string, int length)
{
	for (int i = 0; i < length; i++)
	{
		char temp = '\0';
		cin >> temp;
		string[temp]++;
	}
}

int main()
{
	int string1SymbolsCounter[128] = {};
	int string2SymbolsCounter[128] = {};
	cout << "input the length of the first string\n";
	int length1 = 0;
	cin >> length1;
	cout << "input the first string\n";
	countSymbolsOfTheString(string1SymbolsCounter, length1);
	cout << "input the length of the second string\n";
	int length2 = 0;
	cin >> length2;
	cout << "input the second string\n";
	countSymbolsOfTheString(string2SymbolsCounter, length2);
	if (length1 != length2)
	{
		cout << "NO\n";
		return 0;
	}
	bool canReplace = true;
	for (int i = 0; i < 128 && canReplace; i++)
	{
		if (string1SymbolsCounter[i] != string2SymbolsCounter[i])
		{
			canReplace = false;
		}
	}
	if (canReplace)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}