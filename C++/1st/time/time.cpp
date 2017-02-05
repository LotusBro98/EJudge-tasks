#include <iostream>

using namespace std;

class Time
{
public:
	int hours;
	int minutes;

	Time(){}

	Time(int hours, int minutes)
	{
		if (hours > 12 || hours < 0 || minutes > 59 || minutes < 0)
		{
			this->hours = 0;
			this->minutes = 0;
		}
		else
		{
			this->hours = hours;
			this->minutes = minutes;
		}
	}

	bool operator==(Time time)
	{
		return (time.hours == this->hours) && (time.minutes == this->minutes);
	}

	Time operator+(Time time)
	{
		int minutes = this->minutes + time.minutes;
		int hours = this->hours + time.hours + minutes / 60;
		minutes = minutes % 60;
		if (hours > 12)
			hours = hours % 12;
		return Time(hours, minutes);
	}

	friend ostream& operator<<(ostream& out, const Time& time)
	{
		out << time.hours << '.';
		if (time.minutes < 10)
			out << '0' << time.minutes;
		else
			out << time.minutes;
		return out;
	}
};

/*
int main()
{
	Time time1 = Time(2,6);
	Time time2 = Time(10, 10);
	cout << time1 << endl << time1+time2 << endl;
	return 0;
}
*/
