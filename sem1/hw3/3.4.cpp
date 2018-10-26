#include <iostream>
using namespace std;

int generateNumber(int* availableNumbers, int index)
{
	return availableNumbers[index];
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
	int availableNumbers[10] = {1234, 9127, 6305, 8256, 1924, 5293, 4103, 7777, 4050, 3010};
	cout << "input the natural number (from 1 to 10)\n";
	int index = 0;
	cin >> index;
	cout << "now you are playing level " << index << "\n";
	--index;
	int correctAnswer = generateNumber(availableNumbers, index);
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