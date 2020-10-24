#include "DateTime.h"
using namespace std;

DateTime::DateTime(Date* date, Time* time)
{
	this->date = date;
	this->time = time;
}

DateTime::~DateTime()
{
	delete date;
	delete time;
}

Date* DateTime::getDate()
{
	return date;
}

Time* DateTime::getTime()
{
	return time;
}

int DateTime::compareTo(IComparable* obj)
{
	DateTime* dt = dynamic_cast<DateTime*>(obj);
	if (date->compareTo(dt->getDate()) == -1) {
		return -1;
	}
	else if (date->compareTo(dt->getDate()) == 1) {
		return 1;
	}
	else {
		if (time->compareTo(dt->getTime()) == -1) {
			return -1;
		}
		else if (time->compareTo(dt->getTime()) == 1) {
			return 1;
		}
		else return 0;
	}
	return 0;
}

std::string DateTime::toString()
{
	string str = date->toString() + ", t = " + time->toString();
	return str;
}
