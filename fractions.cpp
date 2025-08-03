#include <iostream>
using namespace std;

int	main()
{
	int	a, b, c, d;
	cout << "Given 2 fractions, we need to get back a sum of them (as an irreducible fraction).\n";
	cout << "Enter consequetively numerator & denumerator of one fraction, then another one: ";
	cin >> a >> b >> c >> d;
	int num = a * d + c * b;
	int denum = b * d;
	int reducer = num;
	while (reducer > 1)
	{
		if (!(num % reducer) && !(denum % reducer))
		{
			num /= reducer;
			denum /= reducer;
			reducer = num;
			continue ;
		}
		reducer--;
	}
	cout << "The sum (as an irreducible fraction) is " << num << "/" << denum;
}
