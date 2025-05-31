#include <iostream>
#include <vector>
using namespace std;

int	main(void)
{
	vector<int>	floors;
	int	floor;
	int	t;
	int	n;
	int	i;
	int	who_leaving;

	cin >> n >> t;
	i = 0;
	while (i < n)
	{
		cin >> floor;
		floors.push_back(floor);
		i++;
	}
	cin >> who_leaving;
	if (floors[who_leaving - 1] == floors[0]
		|| t >= floors[who_leaving - 1] - floors[0]
		|| floors[who_leaving - 1] == floors[n - 1]
		|| t >= floors[n - 1] - floors[who_leaving - 1])
		i = floors[n - 1] - floors[0]; // from one side to another one
	else if (floors[who_leaving - 1] - floors[0]
		< floors[n - 1] - floors[who_leaving - 1])
		i = floors[who_leaving - 1] - floors[0]
			+ floors[n - 1] - floors[0]; // first down, then up
	else
		i = floors[n - 1] - floors[who_leaving - 1]
			+ floors[n - 1] - floors[0]; // first up, then down
	cout << i << endl;
}
