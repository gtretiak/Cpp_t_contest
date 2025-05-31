#include <iostream>
using namespace std;

int	main(void)
{
	int	n;
	int	i;

	i = 0;
	cin >> n;
	while (n / 2)
	{
		n = (n / 2) + (n % 2);
		i++;
	}
	cout << i << endl;
}
