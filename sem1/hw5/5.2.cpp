#include <iostream>
#include <fstream>
using namespace std;

const int maxStringSize = 260;
const int numberOfLetters = 26;

void clear(bool* letterBoolArray)
{
	for (int i = 0; i < numberOfLetters; ++i)
	{
		letterBoolArray[i] = false;
	}
}

void readPath(char* path)
{
	cin.getline(path, maxStringSize);
}

int calculateIndex(char letter)
{
	if (letter >= 'a' && letter <= 'z')
	{
		return letter - 'a';
	}
	else if (letter >= 'A' && letter <= 'Z')
	{
		return letter - 'A';
	}
	else
	{
		cout << "error!\n";
		return -1;		
	}
}

int main()
{
	char path[maxStringSize] = "5.2.test.txt";
	cout << "Do you want to input path of the file by yourself y/n\n";
	char answer = '\0';
	cin >> answer;
	if (answer != 'y' && answer != 'n')
	{
		cerr << "input the correct answer\n";
		return 1;
	}
	else if (answer == 'y')
	{
		cout << "input path to your file\n";
		cin.ignore();
		readPath(path);
		cout << "here is path from your input\n";
		cout << path << "\n";
	}
	ifstream file(path);
	if (!file)
	{
		cerr << "error reading file, input the correct path\n";
		return -1;
	}
	else
	{
		char temp = '\0';
		bool isWord = false;
		bool wasFoundSmall[numberOfLetters] = {};
		bool wasFoundBig[numberOfLetters] = {};
		while (file.get(temp))
		{
			if (!isWord)
			{
				if (temp >= 'a' && temp <= 'z')
				{
					cout << temp;
					isWord = true;
					int index = calculateIndex(temp);
					wasFoundSmall[index] = true;
					wasFoundBig[index] = true;
				}
				else if (temp >= 'A' && temp <= 'Z')
				{
					cout << temp;
					isWord = true;
					int index = calculateIndex(temp);
					wasFoundSmall[index] = true;
					wasFoundBig[index] = true;
				}
				else
				{
					cout << temp << " ";
				}
			}
			else
			{
				if (temp >= 'a' && temp <= 'z')
				{
					int index = calculateIndex(temp);
					if (!(wasFoundSmall[index] || wasFoundBig[index]))
					{
						wasFoundSmall[index] = true;
						cout << temp;
					}
				}
				else if (temp >= 'A' && temp <= 'Z')
				{
					int index = calculateIndex(temp);
					if (!(wasFoundSmall[index] || wasFoundBig[index]))
					{
						wasFoundBig[index] = true;
						cout << temp;
					}
				}
				else
				{
					clear(wasFoundBig);
					clear(wasFoundSmall);
					cout << temp;
				}
			}
		}
	}
	return 0;
}