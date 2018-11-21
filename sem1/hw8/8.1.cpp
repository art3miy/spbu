#include <iostream>
using namespace std;

bool isFind(int studentsNumber)
{
    if (studentsNumber == 1 || studentsNumber == 2 || studentsNumber == 3 || studentsNumber == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int calculateRealNumber(int *studentsArray, int workNumber)
{
    int current = workNumber;
    while (!isFind(current))
    {
        current = studentsArray[current];
    }
    return current;
}

int main()
{
    cout << "input number of students\n";
    int numberOfStudents = 0;
    cin >> numberOfStudents;
    int *studentsArray = new int[numberOfStudents + 1];
    cout << "input students number and number of student, who allowed to copy his work\n";
    for (int i = 0; i < numberOfStudents; ++i)
    {
        int studentsNumber = 0;
        cin >> studentsNumber;
        int workNumber = 0;
        cin >> workNumber;
        studentsArray[studentsNumber] = workNumber;
    }
    cout << "this is the list of students with numbers of students who allowed to copy their works\n";
    for (int i = 1; i <= numberOfStudents; ++i)
    {
        cout << i  << " " << calculateRealNumber(studentsArray, studentsArray[i]) << "\n";
    }
    delete [] studentsArray;
    return 0;
}
