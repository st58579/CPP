#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

static const string path = "../file.txt";
static const string path_bin = "../file.bin";

struct Date {
public:
    Date() : Date(0, 0, 0) {};

    Date(int day, int month, int year) : day(day), month(month), year(year) {};
private:
    int day, month, year;

    friend ostream &operator<<(ostream &os, const Date &date);

    friend istream &operator>>(istream &is, Date &date);
};

ostream &operator<<(ostream &os, const Date &date) {
    os << date.day << " " << date.month << " " << date.year;
    return os;
}

istream &operator>>(istream &is, Date &date) {
    is >> date.day >> date.month >> date.year;
    return is;
}

struct Address {
public:
    Address() : Address("", "", "") {};

    Address(string street, string city, string ZIP) : street(street), city(city), ZIP(ZIP) {};
private:
    string street, city, ZIP;

    friend ostream &operator<<(ostream &os, const Address &address);

    friend istream &operator>>(istream &is, Address &address);
};

ostream &operator<<(ostream &os, const Address &address) {
    os << address.street << " " << address.city << " " << address.ZIP;
    return os;
}

istream &operator>>(istream &is, Address &address) {
    is >> address.street >> address.city >> address.ZIP;
    return is;
}

struct Person {
public:
    Person() : Person(("asd"), ("asd"), (Address()), (Date())) {};

    Person(string name, string surname, Address address, Date date) : name(name), surname(surname), address(address),
                                                                      birthDate(date) {};
private:
    string name, surname;
    Address address;
    Date birthDate;

    friend ostream &operator<<(ostream &os, const Person &address);

    friend istream &operator>>(istream &is, Person &person);
};

ostream &operator<<(ostream &os, const Person &person) {
    os << person.name << " " << person.surname << " " << person.address << " " << person.birthDate << endl;
    return os;
}

istream &operator>>(istream &is, Person &person) {
    is >> person.name >> person.surname >> person.address >> person.birthDate;
    return is;
}


void write() {
    ofstream ofs;
    ofs.open(path);
    if (!ofs.is_open()) {
        throw std::runtime_error("File not opened");
    }
    Person arr[3]{{"Person", "One",   Address("street1", "city1", "zip1"), Date(1, 1, 1)},
                  {"Person", "Two",   Address("street2", "city2", "zip2"), Date(2, 2, 2)},
                  {"Person", "Three", Address("street3", "city3", "zip3"), Date(3, 3, 3)}};
    ofs << arr[0] << arr[1] << arr[2];
}

Person *read() {
    ifstream ifs;
    ifs.open("../file.txt");
    if (!ifs.is_open()) {
        throw std::runtime_error("File not opened");
    }
    size_t arrSize = 0;
    while (!ifs.eof()) {
        Person p;
        ifs >> p;
        arrSize++;
        if (ifs.eof()) {
            ifs.clear();
            ifs.seekg(0, ios::beg);
            break;
        }
        cout << p;
    }
    Person *arr = new Person[arrSize];
    for (int i = 0; i < arrSize; ++i) {
        ifs >> arr[i];
    }
    ifs.close();
    return arr;
}

void writeBin() {
    ofstream ofs(path_bin, ios::binary | ios::out);
    if (!ofs) {
        throw std::runtime_error("File not opened");
    }
    Person arr[3]{{"Person", "One",   Address("street1", "city1", "zip1"), Date(1, 1, 1)},
                  {"Person", "Two",   Address("street2", "city2", "zip2"), Date(2, 2, 2)},
                  {"Person", "Three", Address("street3", "city3", "zip3"), Date(3, 3, 3)}};
    cout << endl << endl << endl;
    size_t arrSize = 3;
    ofs.write((char *) &arrSize, sizeof(size_t));
    for (int i = 0; i < 3; ++i) {
        ofs.write((char *) &arr[i], sizeof(Person));
        cout << arr[i];
    }
    ofs.close();
}

Person *readBin() {
    ifstream ifs(path_bin, ios::binary | ios::in);
    if (!ifs) {
        throw std::runtime_error("File not opened");
    }
    size_t arrSize = 0;
    ifs.read((char *) &arrSize, sizeof(size_t));
    Person *arr = new Person[arrSize];
    for (int i = 0; i < arrSize; ++i) {
        ifs.read((char *) &arr[i], sizeof(Person));
    }
    ifs.close();
    return arr;
}


int main() {
    write();
    Person *arr = read();
    delete[] arr;
    writeBin();
    Person *arrBin = readBin();
    delete[] arrBin;
    return 0;
}
