#ifndef CVICENI_07_PERSON_H
#define CVICENI_07_PERSON_H

#include <iostream>
#include "Address.h"
#include "Date.h"
using namespace std;


struct Person {
public:
    Person();

    Person(string name, string surname, Address address, Date date);
private:
    string name, surname;
    Address address;
    Date birthDate;

    friend ostream &operator<<(ostream &os, const Person &address);

    friend istream &operator>>(istream &is, Person &person);
};

#endif //CVICENI_07_PERSON_H
