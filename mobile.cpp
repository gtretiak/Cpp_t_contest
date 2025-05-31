#include <iostream>
#include <vector>
using namespace std;

int	main(void)
{
	vector<int>	nums;
	int	i;
	int	n;

	i = 0;
	while (i < 4)
	{
		cin >> n;
		nums.push_back(n);
		i++;
	}
	if (nums[3] > nums[1])
	{
		nums[0] += (nums[3] - nums[1]) * nums[2];
	}
	cout << nums[0] << endl;
}
