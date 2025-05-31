#include <iostream>
#include <vector>
using namespace std;

long long	ft_calculate_res(long long l, long long r)
{
	long long	res;
	int	i;
	long long	j;

	res = 0;
	i = 1;
	while (i <= 9)
	{
		j = i;
	       	while ((j * 10) + i <= r)
		{
			j = (j * 10) + i;
			if (j >= l)
				res++;
		}
		i++;
	}
	return (res);
}

int	main(void)
{
	long long	l;
	long long	r;
	long long	res;

	cin >> l >> r;
	res = 0;
	if (l < 10 && r < 10)
	{	
		res = r - l + 1;
		cout << res << endl;
		return (0);
	}
	else if (l < 10)
		res = 9 - l + 1;
	res += ft_calculate_res(l, r);
	cout << res << endl;
}
