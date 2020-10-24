#pragma once
#ifndef DATE_H
#define DATE_H
#include "IComparable.h"

class Date : public IComparable{
public:
	Date(int year, int month, int day);
	~Date();
	int getDay();
	int getMonth();
	int getYear();
	int compareTo(IComparable* obj) override;
	std::string toString() override;
private:
	int day;
	int month;
	int year;
};

#endif // DATE_H