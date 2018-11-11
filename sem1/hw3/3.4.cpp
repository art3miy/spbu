#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

void transferIntoArray(int number, int* array);

bool ifAllDigitsAreUnique(int* numberArray)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = i + 1; j < 4; ++j)
		{
			if (numberArray[i] == numberArray[j])
			{
				return false;
			}
		}
	}
	return true;
}

int generateNumber()
{
	int numberArray[4] = {};
	srand(time(0));
	while (!ifAllDigitsAreUnique(numberArray) || numberArray[0] == 0)
	{
		int randomNumber = rand();
		transferIntoArray(randomNumber, numberArray);
	}
	int answer = 0;
	for (int i = 0; i < 4; ++i)
	{
		answer += numberArray[3 - i] * pow(10, i);
	}
	return answer;
}

void transferIntoArray(int number, int* array)
{
	for (int i = 0; i < 4; i++)
	{
		int digit = number % 10;
		array[3 - i] = digit;
		number /= 10;
	}
}

int countBulls(int* usersAnswerArray, int* correctAnswerArray)
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (usersAnswerArray[i] == correctAnswerArray[i])
		{
			++count;
		}
	}
	return count;
}

int countCows(int* usersAnswerArray, int* correctAnswerArray)
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		int potentialCow = usersAnswerArray[i];
		for (int j = 0; j < 4; j++)
		{
			if ((correctAnswerArray[j] == potentialCow) && (j != i))
			{
				++count;
			}
		}
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int correctAnswer = generateNumber();
	int correctAnswerArray[4] = {};
	transferIntoArray(correctAnswer, correctAnswerArray);
	int usersAnswer = 0;
	int usersAnswerArray[4] = {};
	cout << "try to figure out what the correct 4 digit natural number is (there are no repeated digits in this number)\n";
	while (usersAnswer != correctAnswer)
	{
		int localBullCounter = 0;
		int localCowCounter = 0;
		cin >> usersAnswer;
		transferIntoArray(usersAnswer, usersAnswerArray);
		localBullCounter = countBulls(usersAnswerArray, correctAnswerArray);
		localCowCounter = countCows(usersAnswerArray, correctAnswerArray);
		cout << localBullCounter << " Bulls " << localCowCounter << " Cows\n";
	}
	cout << "YOU WIN!\n";
	return 0;
}