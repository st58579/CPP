#pragma once
#ifndef DATETIME_H
#define DATETIME_H
#include "IComparable.h"
#include "Date.h"
#include "time.h"

class DateTime : public IComparable {
public:
	DateTime(Date* date, Time* time);
	~DateTime();
	Date* getDate();
	Time* getTime();
	int compareTo(IComparable* obj) override;
	std::string toString() override;
private:
	Date* date;
	Time* time;
};

#endif // DATETIME_H