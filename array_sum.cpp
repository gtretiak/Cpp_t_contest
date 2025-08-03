#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void	getNum(vector<pair<int, int>> &A, int N)
{
	sort(A.begin(), A.end());
	int	count = 0;
	int	covered = 1;
	int	i = 0;
	int	maxRight;

	while (covered <= N)
	{
		maxRight = -1;
		while (i < A.size() && A[i].first <= covered)
		{
			maxRight = max(maxRight, A[i].second);
			i++;
		}
		if (maxRight < covered)
		{
			cout << "No, it's impossible.";
			return ;
		}
		count++;
		covered = maxRight + 1;
	}
	cout << "Yes" << endl << "The " << count << " number of clues is needed.";
}

int	main(void)
{
	int	N;
	int	Q;
	int 	x;
	int	y;
	bool	flag1 = false;
	bool	flagn = false;
	cout << "The array of integers is given and we want to find the sum of its elements.\n"
		"We have certain number of clues (ranges of the array's numbers with known values).\n"
		"\nQ: Can we find the sum of the array? "
		"If possible, how many clues do we need?\n\n";
	cout << "The array's length: ";
	cin >> N;
	cout << "How many clues do we have: ";
	cin >> Q;
	vector<pair<int, int>>	A;
	cout << "Insert clues (ranges of the array's numbers with known values):\n";
	for (int i = 0; i < Q; i++)
	{
		cin >> x >> y;
		if (x == 1)
			flag1 = true;
		if (y == N)
			flagn = true;
		A.push_back({x, y});
	}
	if (!flag1 || !flagn)
	{
		cout << "No, it's impossible.";
		return (0);
	}
	getNum(A, N);
	return (0);
}
