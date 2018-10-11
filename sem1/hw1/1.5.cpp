#include <iostream>
using namespace std;

int main()
{
	cout << "input length of bracket sequence\n";
	int length = 0;
	cin >> length;
	if (length % 2 != 0)
	{
		cout << "this can`t be correct bracket sequence\n";
		return 0;
	}
	cout << "input the bracket sequence (only '{' or '}' symbols without spaces between)\n";
	int balance = 0;
	for (int i = 0; i < length; i++)
	{
		char current = '\0';
		cin >> current;
		if (current == '{')
		{
			balance++;
		}
		else if (current == '}')
		{
			balance--;
			if (balance < 0)
			{
				cout << "This bracket sequence is not correct\n";
				return 0;
			}
		}
	}
	if (balance == 0)
	{
		cout << "This bracket sequence is correct\n";
	}
	else
	{
		cout << "This bracket sequence is not correct\n";
	}
}