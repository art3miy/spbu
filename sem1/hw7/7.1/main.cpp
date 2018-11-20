#include "bst.h"
#include <iostream>
#include "set.h"
using namespace std;

int main()
{
    BinarySearchTree *set = createSet();
    cout << "input number of elements\n";
    int number = 0;
    cin >> number;
    cout << "input elements\n";
    for (int i = 0; i < number; ++i)
    {
        int temp = 0;
        cin >> temp;
        addToSet(set, temp);
    }
    cout << "here`s your set`s elements\n";
    printIncreasingOrder(set);
    printDecreasingOrder(set);
    cout << "input value of element u want to delete\n";
    int value = 0;
    cin >> value;
    deleteFromSet(set, value);
    cout << "here`s your set now\n";
    printIncreasingOrder(set);
    cout << "this is parsing of your set\n";
    printSetParsing(set);
}
