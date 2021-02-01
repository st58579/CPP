#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <api.h>
struct Student {
public:
	Student(StringValue* jmeno, StringValue* prijmeni, StringValue* datum, NumberValue* id, NumberValue* rocnik, BoolValue* jePrvniStudium, ArrayValue* polePredmetu);
	~Student();
	StringValue* getJmeno() const;
	StringValue* getPrijmeni() const;
	StringValue* getDatumNarozeni() const;
	ArrayValue* getPolePredmetu() const;
	BoolValue* jePrvniStudium() const;
	NumberValue* getRocnik() const;
	void print() const;
	std::string serialize() const;
private:
	StringValue* jmeno;
	StringValue* prijmeni;
	StringValue* datumNarozeni;
	NumberValue* id;
	NumberValue* rocnik;
	BoolValue* prvniStudium;
	ArrayValue* polePredmetu;
	//NumberValue* pocetPredmetu;
};

#endif