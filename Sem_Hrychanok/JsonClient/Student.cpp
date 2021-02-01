#include "Student.h"
#include <iostream>


Student::Student(StringValue* jmeno, StringValue* prijmeni, StringValue* datum, NumberValue* id, NumberValue* rocnik, BoolValue* jePrvniStudium, ArrayValue* polePredmetu)
{
    this->jmeno = jmeno;
    this->prijmeni = prijmeni;
    this->datumNarozeni = datum;
    this->id = id;
    this->rocnik = rocnik;
    this->prvniStudium = jePrvniStudium;
    this->polePredmetu = polePredmetu;
    //this->pocetPredmetu = pocetPredmetu;
}


Student::~Student()
{
    delete jmeno;
    delete prijmeni;
    delete datumNarozeni;
    delete id;
    delete rocnik;
    delete prvniStudium;
    polePredmetu->~ArrayValue();
}

StringValue* Student::getJmeno() const
{
    return jmeno;
}

StringValue* Student::getPrijmeni() const
{
    return prijmeni;
}

StringValue* Student::getDatumNarozeni() const
{
    return datumNarozeni;
}

ArrayValue* Student::getPolePredmetu() const
{
    return polePredmetu;
}

BoolValue* Student::jePrvniStudium() const
{
    return prvniStudium;
}

NumberValue* Student::getRocnik() const
{
    return rocnik;
}

//NumberValue* Student::getPocetPredmetu() const
//{
//    return pocetPredmetu;
//}

void Student::print() const
{
    std::cout << "Jmeno : " << jmeno->get() << " " << prijmeni->get() << "; id = " << id->get() << "; datum narozeni : " << datumNarozeni->get() << "; rocnik : " << rocnik->get()
        << "; ";
    if (prvniStudium->get()) std::cout << "je to prvni studium studenta; ";
    else std::cout << "neni to prvni studium studenta; ";
    std::cout << "predmety studenta : ";
    for (size_t i = 0; i < polePredmetu->getSize(); i++)
    {
        std::cout << dynamic_cast<StringValue*>(polePredmetu->get(i))->get() << " ";
    }
    std::cout << std::endl;
}

std::string Student::serialize() const
{
    std::string str = "";
    KeyValuePair kvpName = KeyValuePair("name", jmeno);
    KeyValuePair kvpSurname = KeyValuePair("surname", prijmeni);
    KeyValuePair kvpBirth = KeyValuePair("birthday date", datumNarozeni);
    KeyValuePair kvpID = KeyValuePair("id", id);
    KeyValuePair kvpYear = KeyValuePair("study year", rocnik);
    KeyValuePair kvpFirstStudy = KeyValuePair("is first study", prvniStudium);
    ArrayValue* av = new  ArrayValue();
    for (size_t i = 0; i < polePredmetu->getSize(); i++)
    {
        av->append(polePredmetu->get(i));
    }
    KeyValuePair kvpSubjectsArray = KeyValuePair("subjects", av);
    ObjectValue ov = ObjectValue();
    ov.append(kvpName);
    ov.append(kvpSurname);
    ov.append(kvpBirth);
    ov.append(kvpID);
    ov.append(kvpYear);
    ov.append(kvpFirstStudy);
    ov.append(kvpSubjectsArray);
    str = ov.serialize();
    ov.~ObjectValue();
    return str;
}
