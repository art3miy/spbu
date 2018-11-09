#include <iostream>
using namespace std;

void readCoefficients(int *coefficientsArray, int polynomsPower)
{
	for (int i = 0; i <= polynomsPower; ++i)
	{
		cin >> coefficientsArray[polynomsPower - i];
	}
}

void printSpaces(int number)
{
	for (int i = 0; i < number; ++i)
	{
		cout << " ";
	}
}

int numberOfDigits(int number)
{
	int count = 0;
	while (number != 0)
	{
		++count;
		number /= 10;
	}
	return count;
}

int numberOfSpacesBeforePower(int *coefficientsArray, int power, int polynomsPower)
{
	
	if (coefficientsArray[power] == 0)
	{
		return 0;
	}
	else if (coefficientsArray[power] == 1 || coefficientsArray[power] == -1)
	{
		if (power == polynomsPower)
		{
			if (coefficientsArray[power] == 1)
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
		return 3;
	}
	else if (coefficientsArray[power] > 0)
	{
		if (power == polynomsPower)
		{
			return 1 + numberOfDigits(coefficientsArray[power]);
		}
		else
		{
			return 3 + numberOfDigits(coefficientsArray[power]);
		}
	}
	else
	{
		if (power == polynomsPower)
		{
			return 2 + numberOfDigits(coefficientsArray[power]);
		}
		else
		{
			return 3 + numberOfDigits(coefficientsArray[power]);
		}
	}
}

void printPowers(int *coefficientsArray, int polynomsPower)
{
	for (int i = 0; i <= polynomsPower; ++i)
	{
		int currentPower = polynomsPower - i;
		int numberOfSpaces = numberOfSpacesBeforePower(coefficientsArray, currentPower, polynomsPower);
		printSpaces(numberOfSpaces);
		if (coefficientsArray[currentPower] != 0 && currentPower != 0 && currentPower != 1)
		{
			cout << currentPower;
		}
	}
}

void printMonoms(int *coefficientsArray, int polynomsPower)
{
	for (int i = 0; i <= polynomsPower; ++i)
	{
		int currentPower = polynomsPower - i;
		int numberOfSpacesAfterX = numberOfDigits(currentPower);
		if (currentPower == polynomsPower)
		{
			if (coefficientsArray[currentPower] == 1)
			{
				cout << "x";
			}
			else if (coefficientsArray[currentPower] == -1)
			{
				cout << "-x";
			}
			else
			{
				cout << coefficientsArray[currentPower] << "x";
			}
		}
		else if (currentPower == 0)
		{
			if (coefficientsArray[currentPower] != 0)
			{
				if (coefficientsArray[currentPower] > 0)
				{
					cout << "+ " << coefficientsArray[currentPower];
				}
				else
				{
					int absValue = -coefficientsArray[currentPower];
					cout << "- " << absValue;
				}
			}
		}
		else if (coefficientsArray[currentPower] != 0)
		{
			if (coefficientsArray[currentPower] == 1)
			{
				cout << "+ x";
			}
			else if (coefficientsArray[currentPower] == -1)
			{
				cout << "- x";
			}
			else if (coefficientsArray[currentPower] > 0)
			{
				cout << "+ " << coefficientsArray[currentPower] << "x";
			}
			else if (coefficientsArray[currentPower] < 0)
			{
				int absValue = -coefficientsArray[currentPower];
				cout << "- " << absValue << "x";
			}
		}
		if (coefficientsArray[currentPower] != 0)
		{
			printSpaces(numberOfSpacesAfterX);
		}
	}
}

int main()
{
	cout << "input the power of your polynom\n";
	int polynomsPower = 0;
	cin >> polynomsPower;
	int *coefficientsArray = new int[polynomsPower + 1];
	cout << "input the coefs of your polynom\n";
	readCoefficients(coefficientsArray, polynomsPower);
	printPowers(coefficientsArray, polynomsPower);
	cout << "\n";
	printMonoms(coefficientsArray, polynomsPower);
}