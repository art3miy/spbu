#include <iostream>
#include <fstream>
using namespace std;

void readPath(char* path)
{
    cin.getline(path, 260);
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
    cout << "input path to your file\n";
    char path[260] = {};
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
        char string[255] = {};
        int counter = 0;
        while (!file.eof())
        {
            file.getline(string, 255);
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