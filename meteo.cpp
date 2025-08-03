#include <iostream>
using namespace std;

int	shouldbe(int n, int m)
{
	int	days;
	days = 14 - n + m;
	return (m + 7 - days);
}

int	main(void)
{
	int	today;
	int	last_note;
	cout << "Sean is a meteorologist who makes diary notes every Sunday.\n";
	cout << "Today is another Sunday.\n";
	cout << "The problem is he forgot to make the notes on last Sunday.\n";
	cout << "So the notes were made by him 2 weeks ago.\n";
	cout << "We know what day is today. Also, we can see in the diary the day of the last note.\n";
	cout << "But we can't remember what month we are in...\n";
	cout << "Enter today's day (1-31): ";
	cin >> today;
	cout << "Enter the day of the last note (1-31): ";
	cin >> last_note;
	cout << "The day that we should make the notes on last week is ";
	cout << shouldbe(today, last_note);
}
