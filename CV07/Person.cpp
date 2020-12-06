#include "Person.h"

Person::Person() : Person(("asd"), ("asd"), (Address()), (Date())) {};

Person::Person(string name, string surname, Address address, Date date) : name(name), surname(surname),
                                                                          address(address),
                                                                          birthDate(date) {};

ostream &operator<<(ostream &os, const Person &person) {
    os << person.name << " " << person.surname << " " << person.address << " " << person.birthDate << endl;
    return os;
}

istream &operator>>(istream &is, Person &person) {
    is >> person.name >> person.surname >> person.address >> person.birthDate;
    return is;
}
