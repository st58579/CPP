
#ifndef CVICENI_07_ADDRESS_H
#define CVICENI_07_ADDRESS_H

#include <iostream>
using namespace std;

struct Address {
public:
    Address();

    Address(string street, string city, string ZIP);
private:
    string street, city, ZIP;

    friend ostream &operator<<(ostream &os, const Address &address);

    friend istream &operator>>(istream &is, Address &address);
};

#endif //CVICENI_07_ADDRESS_H
