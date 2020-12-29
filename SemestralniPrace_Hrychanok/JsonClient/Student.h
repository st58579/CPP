#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <string>

struct Student {
public:
	Student(std::string jmeno, std::string prijmeni, std::string datum, int id, int rocnik, bool jePrvniStudium, std::string* polePredmetu, int pocetPredmetu);
	~Student();
	std::string getJmeno() const;
	std::string getPrijmeni() const;
	std::string getDatumNarozeni() const;
	std::string* getPolePredmetu() const;
	bool jePrvniStudium() const;
	int getRocnik() const;
	int getPocetPredmetu() const;
	void print() const;
private:
	std::string jmeno;
	std::string prijmeni;
	std::string datumNarozeni;
	int id;
	int rocnik;
	bool prvniStudium;
	std::string* polePredmetu;
	int pocetPredmetu;
};

#endif