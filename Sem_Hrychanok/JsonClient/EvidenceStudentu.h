#pragma once
#ifndef EVIDENCE_STUDENTU_H
#define EVIDENCE_STUDENTU_H

#include <api.h>
#include "Student.h"
struct EvidenceStudentu {
public:
	EvidenceStudentu();
	~EvidenceStudentu();
	void pridejStudenta(Student* student);
	void odeberStudenta(int index);
	Student* dejStudenta(int index) const;
	void process(ArrayValue* av);
	void print() const;
	std::string serialize() const;
private:
	DynamicArray<Student*> studentsArray;

};


#endif