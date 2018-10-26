#include <iostream>
#include <fstream>
using namespace std;

void clear(bool* letterBoolArray)
{
    for (int i = 0; i < 25; ++i)
    {
        letterBoolArray[i] = false;
    }
}

void readPath(char* path)
{
    cin.getline(path, 260);
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
        cout << "Here`s your file with deleted duplicate letters from any words (for example word PpRrIiVvEeTt "
                "will turn into PRIVET)\n";
        char temp = '\0';
        bool isWord = false;
        bool wasFoundSmall[25] = {}; // 0 - 24 == a - z
        bool wasFoundBig[25] = {}; // 0 - 24 == A - Z
        while (file.get(temp))
        {
            if (!isWord)
            {
                if (temp >= 'a' && temp <= 'z')
                {
                    cout << temp;
                    isWord = true;
                    wasFoundSmall[temp - 'a'] = true;
                    wasFoundBig[temp - 'a'] = true;
                }
                else if (temp >= 'A' && temp <= 'Z')
                {
                    cout << temp;
                    isWord = true;
                    wasFoundBig[temp - 'A'] = true;
                    wasFoundSmall[temp - 'A'] = true;
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
                    if (!(wasFoundSmall[temp - 'a'] || wasFoundBig[temp - 'a']))
                    {
                        wasFoundSmall[temp - 'a'] = true;
                        cout << temp;
                    }
                }
                else if (temp >= 'A' && temp <= 'Z')
                {
                    if (!(wasFoundSmall[temp - 'A'] || wasFoundBig[temp - 'A']))
                    {
                        wasFoundBig[temp - 'A'] = true;
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