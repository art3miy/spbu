#include <iostream>
#include <fstream>
using namespace std;

const int maxStringSize = 260;

void readPath(char* path)
{
    cin.getline(path, maxStringSize);
}

bool isEmpty(char* string)
{
    bool isEmpty = true;
    for (int i = 0; string[i] != '\0'; ++i)
    {
        if (string[i] != ' ' && string[i] != '\n' && string[i] != '\t')
        {
            isEmpty = false;
            return isEmpty;
        }
    }
    return isEmpty;
}

int main()
{
	char path[maxStringSize] = "test.txt";
	cout << "Do you want to input path of the file by yourself y/n\n";
	char answer = '\0';
	cin >> answer;
	if (answer != 'y' && answer != 'n')
	{
		cerr << "input the correct answer";
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
        return 2;
    }
    else
    {
        char string[maxStringSize] = {};
        int counter = 0;
        while (!file.eof())
        {
            file.getline(string, maxStringSize);
            if (!isEmpty(string))
            {
                ++counter;
            }
        }
        cout << "there are " << counter << " not empty strings in your file\n";
    }
    file.close();
    return 0;
}