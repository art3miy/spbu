#include <iostream>
#include "cyclelist.h"
using namespace std;

int main()
{
    List* list = createCycleList();
    cout << "input the number of warriors\n";
    int length = 0;
    cin >> length;
    if (length <= 1)
    {
        if (length == 1)
        {
            cout << "the position of the only alive warrior was : 1 (he will not kill himself)";
        }
        else
        {
            cout << "input the correct number";
        }
        return 0;
    }
    cout << "now input the number of warrior that will be killed\n";
    int index = 0;
    cin >> index;
    for (int i = 1; i <= length; i++)
    {
        add(list, i);
    }
    for (int i = 0; i < length - 1; i++)
    {
        deleteFrom(list, index);
    }
    cout << "the position of the only alive warrior was : ";
    printCycleList(list);
    deleteCycleList(list);
}