#include "Date.h"
using namespace std;


Date::Date(int year, int month, int day)
{
	if (year >= 0 && year < 10000 && month > 0 && month < 13 && day > 0 && day < 30) {
		this->year = year;
		this->month = month;
		this->day = day;
	}
}

Date::~Date()
{
}

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}

int Date::compareTo(IComparable* obj)
{
	Date* date2 = dynamic_cast<Date*>(obj);
	if (year < date2->getYear()) {
		return -1;
	}
	else if (year > date2->getYear()) {
		return 1;
	}
	else {
		if (month < date2->getMonth()) {
			return -1;
		}
		else if (month > date2->getMonth()) {
			return 1;
		}
		else {
			if (day < date2->getDay()) {
				return -1;
			}
			else if (day > date2->getDay()) {
				return 1;
			}
			else return 0;
		}
	}
}

std::string Date::toString()
{
	string str = to_string(year) + "." + to_string(month) + "." + to_string(day);
	return str;
}
