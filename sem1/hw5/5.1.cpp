#include <iostream>
#include <cstdio>
using namespace std;

int** create2dArray(int numberOfLines, int numberOfColumns)
{
    int** array = new int*[numberOfLines];
    array[0] = new int[numberOfLines * numberOfColumns];
    for (int i = 1; i < numberOfLines; ++i)
    {
        array[i] = array[i - 1] + numberOfColumns;
    }
    return array;
}

void delete2dArray(int** array)
{
    delete [] array[0];
    delete [] array;
}

void initialize2dArray(int** array, int numberOfLines, int numberOfColumns)
{
    int current = 0;
    for (int i = 0; i < numberOfLines; ++i)
    {
        for (int j = 0; j < numberOfColumns; ++j)
        {
            ++current;
            array[i][j] = current;
        }
    }
}

void print2dArray(int** array, int numberOfLines, int numberOfColumns)
{
    for (int i = 0; i < numberOfLines; ++i)
    {
        for (int j = 0; j < numberOfColumns; ++j)
        {
            printf("%2d ", array[i][j]);
        }
        cout << "\n";
    }
}

void read2dArray(int** array, int numberOfLines, int numberOfColumns)
{
    for (int i = 0; i < numberOfLines; ++i)
    {
        for (int j = 0; j < numberOfColumns; ++j)
        {
           cin >> array[i][j];
        }
    }
}

void spiralPrint(int** array, int length)
{
    int right = 1, down = 1, left = 2, up = 2;
    int currentLine = length / 2;
    int currentColumn = length / 2;
    int previousLine = length / 2;
    int previousColumn = length / 2;
    cout << array[currentLine][currentColumn] << " ";
    while (currentLine != 0)
    {
        currentColumn += right;
        for (int i = previousColumn + 1; i <= currentColumn; ++i)
        {
            cout << array[currentLine][i] << " ";
        }
        previousColumn = currentColumn;
        currentLine += down;
        for (int i = previousLine + 1; i <= currentLine; ++i)
        {
            cout << array[i][currentColumn] << " ";
        }
        previousLine = currentLine;
        currentColumn -= left;
        for (int i = previousColumn - 1; i >= currentColumn; --i)
        {
            cout << array[currentLine][i] << " ";
        }
        previousColumn = currentColumn;
        currentLine -= up;
        for (int i = previousLine - 1; i >= currentLine; --i)
        {
            cout << array[i][currentColumn] << " ";
        }
        previousLine = currentLine;
        right += 2;
        down += 2;
        left += 2;
        up += 2;
    }
    for (int i = 1; i < length; ++i)
    {
        cout << array[0][i] << " ";
    }
}

int main()
{
    cout << "input n to create n x n array\n";
    int n = 0;
    cin >> n;
    int** array = create2dArray(n, n);
    cout << "Do you want to initialize this array by yourself? y/n\n";
    char temp = '\0';
    cin >> temp;
    while (temp != 'y' && temp != 'n')
    {
        cout << "type y for yes , n for no\n";
        cout << "Do you want to initialize this array by yourself? y/n\n";
        cin >> temp;
    }
    if (temp == 'y')
    {
        cout << "now input elements of your array\n";
        read2dArray(array, n, n);
        cout << "here is how you array looks like:\n";
        print2dArray(array, n, n);
        cout << "this is elements of your array printed by spiral:\n";
        spiralPrint(array, n);
    }
    else if (temp == 'n')
    {
        initialize2dArray(array, n, n);
        cout << "here is how you array looks like after auto-initializing:\n";
        print2dArray(array, n, n);
        cout << "this is elements of your array printed by spiral:\n";
        spiralPrint(array, n);
    }
    delete2dArray(array);
}