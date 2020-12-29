#include "Student.h"
#include <iostream>
Student::Student(std::string jmeno, std::string prijmeni, std::string datum, int id, int rocnik, bool jePrvniStudium, std::string* polePredmetu, int pocetPredmetu)
{
    this->jmeno = jmeno;
    this->prijmeni = prijmeni;
    this->datumNarozeni = datum;
    this->id = id;
    this->rocnik = rocnik;
    this->prvniStudium = jePrvniStudium;
    this->polePredmetu = polePredmetu;
    this->pocetPredmetu = pocetPredmetu;
}

Student::~Student()
{
    delete[] polePredmetu;
}

std::string Student::getJmeno() const
{
    return jmeno;
}

std::string Student::getPrijmeni() const
{
    return prijmeni;
}

std::string Student::getDatumNarozeni() const
{
    return datumNarozeni;
}

std::string* Student::getPolePredmetu() const
{
    return polePredmetu;
}

bool Student::jePrvniStudium() const
{
    return prvniStudium;
}

int Student::getRocnik() const
{
    return rocnik;
}

int Student::getPocetPredmetu() const
{
    return pocetPredmetu;
}

void Student::print() const
{
    std::cout << "Jmeno : " << jmeno << " " << prijmeni << "; id = " << id << "; datum narozeni : " << datumNarozeni << "; rocnik : " << rocnik
        << "; ";
    if (prvniStudium) std::cout << "je to prvni studium studenta; ";
    else std::cout << "neni to prvni studium studenta; ";
    std::cout << "predmety studenta : ";
    for (size_t i = 0; i < pocetPredmetu; i++)
    {
        std::cout << polePredmetu[i] << " ";
    }
    std::cout << std::endl;
}
