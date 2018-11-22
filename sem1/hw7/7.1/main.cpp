#include "bst.h"
#include <iostream>
#include "set.h"
using namespace std;

int main()
{
    cout << "Hello, this is my interpretation of set based on binary search tree.\n\n";
    cout << "Do you want to create set? y/n\n";
    char answer = '\0';
    cin >> answer;
    if (answer != 'y')
    {
        cout << "Ok, bye\n";
        return 0;
    }
    cout << "this is the list of commands you can use:\n\n";
    cout << "input \n";
    cout << "1 : to add element to set\n";
    cout << "2 : to delete element to your set\n";
    cout << "3 : to check if element is in your set\n";
    cout << "4 : to print set in increasing order\n";
    cout << "5 : to print set in decreasing order\n";
    cout << "6 : to print set in abc format\n";
    cout << "7 : to quit the programm\n";
    Set *set = createSet();
    int input = 0;
    while (input != 7)
    {
        cin >> input;
        if (input == 1)
        {
            cout << "input the value of element you want to add\n";
            int value = 0;
            cin >> value;
            addToSet(set, value);
            cout << "the element was succesfully added\n";
        }
        else if (input == 2)
        {
            cout << "input the value of element you want to delete\n";
            int value = 0;
            cin >> value;
            deleteFromSet(set, value);
            cout << "the element was succesfully deleted (or there is no element with the same value)\n";
        }
        else if (input == 3)
        {
            cout << "input the value of element you want to check\n";
            int value = 0;
            cin >> value;
            if (isFindInSet(set, value))
            {
                cout << "this element is in your set\n";
            }
            else
            {
                cout << "this element is not in your set\n";
            }
        }
        else if (input == 4)
        {
            cout << "here is your set in increasing order :\n";
            printIncreasingOrder(set);
        }
        else if (input == 5)
        {
            cout << "here is your set in decreasing order :\n";
            printDecreasingOrder(set);
        }
        else if (input == 6)
        {
            cout << "here is your set in ABC format :\n";
            printInABCFormat(set);
        }
        else if (input != 7)
        {
            cerr << "error: you can`t use this command, quiting\n";
            return 1;
        }
    }
    cout << "Bye\n";
    return 0;
}
