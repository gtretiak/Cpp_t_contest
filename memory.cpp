#include <iostream>
#include <vector>
using namespace std;

int	maxMood(vector<int> A, int skip)
{
	int	total = 0;
	int	i = -1;
	while (++i < A.size())
	{
		if (A[i] >= 0)
			total += A[i];
		else
		{
			if (!skip)
			{
				if (i + 1 < A.size() && A[i] <= A[i + 1])
					i++;
				total += A[i];
			}
			else
			{
				while (i + 1 < A.size() && A[i] <= 0)
					i++;
				skip--;
				if (i >= A.size())
					return (total);
				else
					i--;
			}
		}
	}
	return (total);
}

int	main(void)
{
	int	n;
	int	k;
	int	mood;
	cout << "A boy came up to a staircase.\n"
		"Each step on it is associated with a certain moment in his life.\n"
		"When recalled, it will change his current mood.\n"
		"The boy can step over to the next step, or jump over a step.\n"
		"He can also abstract himself from memories.\nIt means that he can go forward "
		"any number of steps without changing his mood (up to the last step).\n"
		"However, he can do this a certain number of times.\n\n"
		"Q: What is the maximum mood he can get when he ends up on the last step?\n\n";
	cout << "Enter the number of steps on the staircase: ";
	cin >> n;
	cout << "Enter how many times he can skip the steps not causing mood changes: ";
	cin >> k;
	vector<int>	A;
	for (int i = 0; i < n; i++)
	{
		cin >> mood;
		A.insert(A.end(), mood);
	}
	cout << "\nA: The max mood he can get is " << maxMood(A, k);
	return 0;
}
