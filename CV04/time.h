#pragma once
#ifndef TIME_H
#define TIME_H
#include "IComparable.h"

class Time : public IComparable{
public:
	Time(int hrs, int min, int sec);
	~Time();
	int getHours();
	int getMinutes();
	int getSeconds();
	int compareTo(IComparable* obj) override;
	std::string toString() override;

private:
	int hours;
	int minutes;
	int seconds;
};
#endif // !TIME_H
