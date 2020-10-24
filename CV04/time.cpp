#include "time.h"
using namespace std;

Time::Time(int hrs, int min, int sec)
{
	if (hrs >= 0 && hrs < 24 && min >= 0 && min < 60 && sec >= 0 && sec < 60) {
		this->hours = hrs;
		this->minutes = min;
		this->seconds = sec;
	}
	else {
		throw exception("Wrong data");
	}
}

Time::~Time()
{
}

int Time::getHours() {
	return hours;
}
int Time::getMinutes() {
	return minutes;
}
int Time::getSeconds() {
	return seconds;
}

int Time::compareTo(IComparable* obj)
{
	Time* time2 = dynamic_cast<Time*>(obj);
	if (hours < time2->getHours()) {
		return -1;
	}
	else if (hours > time2->getHours()) {
		return 1;
	}
	else {
		if (minutes < time2->getMinutes()) {
			return -1;
		}
		else if (minutes > time2->getMinutes()) {
			return 1;
		}
		else {
			if (seconds < time2->getSeconds()) {
				return -1;
			}
			else if (seconds > time2->getSeconds()) {
				return 1;
			}
			else return 0;
		}
	}
}

string Time::toString()
{
	string str = to_string(hours) + ":" + to_string(minutes) + ":" + to_string(seconds);
	return str;
}
