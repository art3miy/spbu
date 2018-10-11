#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char mainString[10000] = {};
	char subString[10000] = {};
	cout << "input the length of the main string\n";
	int mainStringLength = 0;
	cin >> mainStringLength;
	cout << "now input the main string without spaces\n";
	for (int i = 0; i < mainStringLength; i++)
	{
		cin >> mainString[i];
	}
	cout << "input the length of substring\n";
	int subStringLength = 0;
	cin >> subStringLength;
	if (subStringLength > mainStringLength)
	{
		cout << "this string can`t be substring\n";
		return 0;
	}
	cout << "input the substring\n";
	for (int i = 0; i < subStringLength; i++)
	{
		cin >> subString[i];
	}
	const int numberOfSubstrings = mainStringLength - subStringLength + 1;
	int counter = 0;
	bool isLocalyEqual = false;
	for (int i = 0; i < numberOfSubstrings; i++)
	{
		for (int j = i, k = 0; j < i + subStringLength; j++, k++)
		{
			if (mainString[j] == subString[k])
			{
				isLocalyEqual = true;
			}
			else
			{
				isLocalyEqual = false;
				break;
			}
		}
		if (isLocalyEqual)
		{
			counter++;
		}
		isLocalyEqual = false;
	}
	cout << counter << "\n";
	return 0;
}