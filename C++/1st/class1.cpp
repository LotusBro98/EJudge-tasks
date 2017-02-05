#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

class Time
{
	public:
		int hour;
		int min;
};

Time add(Time a, int min)
{
	Time b = a;

	b.min += min;
	b.hour += b.min / 60;
	b.min = b.min % 60;
	b.hour = b.hour % 24;

	return b;
}

int main()
{
	Time a, newTime;
	int min;

	cin >> a.hour >> a.min;
	cin >> min;

	newTime = add(a, min);

	cout << newTime.hour << ":" << newTime.min << endl;
	return 0;
}
