
#ifndef CVICENI_07_DATE_H
#define CVICENI_07_DATE_H

#include <iostream>

using namespace std;

struct Date {
public:
    Date();

    Date(int day, int month, int year);
private:
    int day, month, year;

    friend ostream &operator<<(ostream &os, const Date &date);

    friend istream &operator>>(istream &is, Date &date);
};

#endif //CVICENI_07_DATE_H
