#include <iostream>
#include <vector>
using namespace std;

bool	is_single_cycle(const vector<int>& arr, int n) // where arr is a current gift assignment
{
	vector<bool>	visited(n, false); // boolean vector with all members initialized to false
	int	current;
	int	steps; // to not exceed the number of people

	current = 0;
	steps = 0;
	while (!visited[current] && steps < n) // if we haven't visited the curr person yet
	{
		visited[current] = true;
		current = arr[current] - 1; // at first try we assign current to 0 again
		steps++;
	}
	// if we visited all (all true), and ended back at person 1, we return:
	return (current == 0 && steps == n && visited == vector<bool>(n, true));
}

bool	is_possible(vector<int> arr, vector<int> who, int n)
{
	int	i;
	int	x;
	int	y;
	vector<int>	candidates;

	i = 0;
	no_gift = -1;
	two_gifts = -1;
	while (i < n)
	{
		if (who[i] == 0) // not chosen by anyone, who[1] in our case
			no_gifts = i + 1; // no_gifts becomes 2
		if (who[i] == 2) // chosen by two people, who[0] in our case
			two_gifts = i + 1; // two_gifts becomes 1
		i++;
	}
	if (two_gifts == -1 || no_gifts == -1)
		return (false);
	i = 0;
	while (i < n)
	{
		if (arr[i] == two_gifts) // reassigning a person from a twice gifted to a new pair
			candidates.push_back(i + 1);// we add both 1s, namely 1 and 3
		i++;
	}
	for (int candidate : candidates) // iteration through all candidates to reassign
	{
		vector<int>	modified = arr; // copy creation to not affect the original
		modified[candidate - 1] = no_gifts; // redirection to a person without a gift
		// first try [1 3 2] failed, second [2 3 1] worked
		if (is_single_cycle(modified, n)) // check if it's a valid single cycle
		{
			cout << candidate << " " << no_gifts << endl; // The answer 1 2
			return (true);
		}
	}		
	return (false);
}

int	main(void) // imagine we have a set of 1 3 1...
{
	int	n;
	int	i;

	cin >> n;
	vector<int>	arr(n);
	vector<int>	who(n, 0); // all intialized to 0
	i = 0;
	while (i < n)
	{
		cin >> arr[i];
		who[arr[i] - 1]++; // who[0] becomes 1, who[2] becomes 1, !who[0] becomes 2
		i++;
	}
	if (!is_possible(arr, who, n)) // with [1 3 1], [2 0 1], 3
		cout << "-1 -1" << endl;
}
