#include "Address.h"

Address::Address() : Address("", "", "") {};

Address::Address(string street, string city, string ZIP) : street(street), city(city), ZIP(ZIP) {};

ostream &operator<<(ostream &os, const Address &address) {
    os << address.street << " " << address.city << " " << address.ZIP;
    return os;
}

istream &operator>>(istream &is, Address &address) {
    is >> address.street >> address.city >> address.ZIP;
    return is;
}