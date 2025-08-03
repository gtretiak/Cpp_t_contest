#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int	main(void)
{
	vector<int>	A;
	string	s;
	int	N;
	int	i = -1;
	int	j = 0;
	cout << "You are given a sequence A, initially consisting of one element 0 (A=(0)).\n"
		"You are also given a string S of length N, consisting only of the symbols L and R.\n"
		"Then, for i = 1,2,3,…,N:\n"
		"If Si = L, then the number i goes to the left of the number i−1 in the sequence A.\n"
		"If Si = R, then the number i goes to the right of the number i−1 in the sequence A.\n";
	cout << "Enter the size of the string: ";
	cin >> N;
	cout << "Insert the string (it should only consist of L and R): ";
	cin >> s;
	A.insert(A.begin(), 0);
	while (++i < N)
	{
		if (s[i] == 'R')
			A.insert(A.begin() + j + 1, i + 1);
		else
			A.insert(A.begin() + j, i + 1);
		j = distance(A.begin(), find(A.begin(), A.end(), i + 1));
	}
	cout << "The sequence: ";
	for (int n : A)
		cout << n << " ";
}
