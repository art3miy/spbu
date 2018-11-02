#include <iostream>
#include <fstream>
using namespace std;

const int maxPathSize = 256;

void readPath(char* path)
{
    cin.getline(path, maxPathSize);
}


int main()
{
    cout << "input path to your file (256 symbols max)\n";
    char path[maxPathSize] = {};
    readPath(path);
    cout << "here is path from your input\n";
    cout << path << "\n";
    ifstream file(path);
    if (!file)
    {
        cerr << "error reading file, input the correct path\n";
        return -1;
    }
    else
    {
    	int counter[26] = {};
    	char temp = '\0';
    	while (file.get(temp))
        {
            if (temp >= 'a' && temp <= 'z')
			{
				++counter[temp - 'a'];
			}
        }
        file.close();
    	ofstream file("result.txt");
    	for (int i = 0; i < 26; ++i)
    	{
    		char currentSymbol = (i + 'a');
    		file << currentSymbol << " : " << counter[i] << "\n";
    	}
    	file.close();
    }
}