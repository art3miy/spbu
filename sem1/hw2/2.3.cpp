#include <iostream>
using namespace std;

void build(int leftNumerator, int leftDenominator, int rightNumerator, int rightDenominator, int maxDenominator)
{
	int mediantNumerator = leftNumerator + rightNumerator;
	int mediantDenominator = leftDenominator + rightDenominator;
	if (mediantDenominator <= maxDenominator)
	{
		cout << mediantNumerator << "/" << mediantDenominator << " ";
		build(leftNumerator, leftDenominator, mediantNumerator, mediantDenominator, maxDenominator);
		build(mediantNumerator, mediantDenominator, rightNumerator, rightDenominator, maxDenominator);
	}
}

int main(int argc, char const *argv[])
{
	
	cout << "input max denominator of your fractions\n";
	int maxDenominator = 0;
	cin >> maxDenominator;
	cout << "there are your fractions\n";
	build(0, 1, 1, 1, maxDenominator);
	return 0;
}