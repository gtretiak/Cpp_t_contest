#include <iostream>
#include <vector>
using namespace std;

int	ft_find_max(vector<int> arr, int size)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < size)
	{
		if (arr[i] > arr[res])
			res = i;
		i++;
	}
	return (res);
}

long long	ft_calculate_dif(vector<int> nums, int n, int moves)
{
	long long	dif;
	vector<int>	dif_arr;
	int	mult;
	int	index;
	int	size;

	if (moves == 0 || !nums[0])
		return (0);
	dif = 0;
	size = 0;
	while (n)
	{
		mult = 1;
		while (nums[n - 1] > 0)
		{
			if ((9 - nums[n - 1] % 10) * mult)
			{
				dif_arr.push_back((9 - nums[n - 1] % 10) * mult);
				size++;
			}
			nums[n - 1] /= 10;
			mult *= 10;
		}
		n--;
	}
	while (moves && size)
	{
		index = ft_find_max(dif_arr, size);
		dif += dif_arr[index];
		dif_arr.erase(dif_arr.begin() + index);
		size--;
		moves--;
	}
	return (dif);
}

int	main(void)
{
	vector<int>	nums;
	int	n;
	int	num;
	int	moves;
	int	i;
	long long	dif;

	cin >> n >> moves;
	i = 0;
	while (i < n)
	{
		cin >> num;
		nums.push_back(num);
		i++;
	}
	dif = ft_calculate_dif(nums, n, moves);
	cout << dif << endl;
}
