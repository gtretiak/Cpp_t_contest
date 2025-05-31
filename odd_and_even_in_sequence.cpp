#include <iostream>
#include <vector>
using namespace std;

bool	is_possible(vector<int> arr, int n)
{
	int	i;
	int	one;
	int	two;
	int	check;

	i = 0;
	check = 0;
	one = -1;
	two = -1;
	while (i < n && check <= 2)
	{
		if ((arr[i] % 2) && !(i % 2)) // even match
			i++;
		else if (!(arr[i] % 2) && (i % 2)) // odd match
 			i++;
		else
		{
			check++;
			if (one == -1)
			       one = i;
			else
				two = i;
			i++;
		}
	}
	if (check > 2 || one == -1 || two == -1)
		return (false);
	one++;
	two++;
	cout << one << " " << two << endl;
	return (true);
}

int	main(void)
{
	int	n;
	int	i;
	int	height;
	vector<int>	arr;

	cin >> n;
	i = 0;
	while (i < n)
	{
		cin >> height;
		arr.push_back(height);
		i++;
	}
	if (!is_possible(arr, n))
		cout << "-1 -1" << endl;
}
