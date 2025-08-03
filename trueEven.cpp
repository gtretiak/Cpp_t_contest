#include <iostream>
using namespace std;

int	main()
{
	int	n;
	int	digit;
	cout << "Enter a number: ";
	cin >> n;
	cout << n << " is";
	while (n > 0)
	{
		digit = n % 10;
		if (digit % 2)
		{
			cout << "n't a true even number (not all digits are even).\n";
			return 0;
		}
		n /= 10;
	}
	cout << " a true even number (all digits are even).\n";
	return 0;
}
