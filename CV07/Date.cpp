#include "Date.h"

Date::Date() : Date(0, 0, 0) {};

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {};


ostream &operator<<(ostream &os, const Date &date) {
    os << date.day << " " << date.month << " " << date.year;
    return os;
}

istream &operator>>(istream &is, Date &date) {
    is >> date.day >> date.month >> date.year;
    return is;
}
