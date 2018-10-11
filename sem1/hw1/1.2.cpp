#include <iostream>
using namespace std;

int abs(int variable)
{
	if (variable >= 0)
	{
		return variable;
	}
	else
	{
		return -variable;
	}
}

int main(int argc, char const *argv[])
{
	int a = 0, b = 0;
	cout << "input values of a and b variables (b != 0)\n";
	cin >> a >> b;
	if (a == 0)
	{
		cout << 0;
		return 0;
	}
	int quotient = 0, remainder = a;
	if (a * b >= 0)
	{
		while ((remainder < 0) || (remainder >= abs(b)))
		{
			remainder -= b;
			quotient++;
		}
		cout << quotient;
	}
	else
	{			
		while ((remainder < 0) || (remainder >= abs(b)))
		{
			remainder += b;
			quotient++;
		}
		cout << -quotient;
	}
	return 0;
}