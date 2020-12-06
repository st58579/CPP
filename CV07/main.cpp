#include <fstream>
#include <string>
#include <exception>
#include "Person.h"

static const string path = "../file.txt";
static const string path_bin = "../file.bin";


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
