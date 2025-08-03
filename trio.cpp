#include <iostream>
using namespace std;

int	res(string s)
{
	int	i = -1;
	int	count = 0;
	if (s.length() < 3)
		return (0);
	while (s[++i])
	{
		if (s[i] != 'a')
			continue ;
		if (s[++i] && s[i] != 'b')
			continue ;
		if (s[++i] && s[i] != 'c')
			continue ;
		count++;
	}
	return (count);
}

int main()
{
	string	s;
	cout << "In a given string we can find the number of specific triples.\n";
	cout << "For example, let's calculate how many time \"abc\" occurs in the string.\n";
	cout << "Enter the string: ";
	cin >> s;
	cout << "The \"abc\" triple occurs in the string " << res(s) << " times.";
}
