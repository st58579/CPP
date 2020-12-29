#include "EvidenceStudentu.h"
#include <vector>

EvidenceStudentu::EvidenceStudentu()
{
	studentsArray = DynamicArray<Student*>();
}

EvidenceStudentu::~EvidenceStudentu()
{
	studentsArray.~DynamicArray();
}

void EvidenceStudentu::pridejStudenta(Student* student)
{
	studentsArray.append(student);
}

void EvidenceStudentu::odeberStudenta(int index)
{
	studentsArray.remove(index);
}

Student* EvidenceStudentu::dejStudenta(int index) const
{
	return studentsArray.getElementAt(index);
}

void EvidenceStudentu::process(ArrayValue* av)
{
	int sz = av->getSize();
	for (size_t i = 0; i < av->getSize(); i++)
	{
		ObjectValue* ov = dynamic_cast<ObjectValue*>(av->get(i));
		size_t j = 0;
		KeyValuePair kvpName = ov->get(j++);
		std::string name = dynamic_cast<StringValue*>(kvpName.getValue())->get();
		KeyValuePair kvpSurname = ov->get(j++);
		std::string surname = dynamic_cast<StringValue*>(kvpSurname.getValue())->get();
		KeyValuePair kvpDatum = ov->get(j++);
		std::string birthDate = dynamic_cast<StringValue*>(kvpDatum.getValue())->get();
		KeyValuePair kvpID = ov->get(j++);
		int id = dynamic_cast<NumberValue*>(kvpID.getValue())->get();
		KeyValuePair kvpYear = ov->get(j++);
		int year = dynamic_cast<NumberValue*>(kvpYear.getValue())->get();
		KeyValuePair kvpIsFirstStudy = ov->get(j++);
		bool isFirstStudy = dynamic_cast<BoolValue*>(kvpIsFirstStudy.getValue())->get();
		KeyValuePair kvpSubjects = ov->get(j++);
		ArrayValue* sbj = dynamic_cast<ArrayValue*>(kvpSubjects.getValue());
		std::string* subjectArray = new std::string[sbj->getSize()];
		for (size_t i = 0; i < sbj->getSize(); i++)
		{
			subjectArray[i] = dynamic_cast<StringValue*>(sbj->get(i))->get();
		}
		Student* st = new Student(name, surname, birthDate, id, year, isFirstStudy, subjectArray, sbj->getSize());
		studentsArray.append(st);
		delete ov;
	}
}

void EvidenceStudentu::print() const
{
	for (size_t i = 0; i < studentsArray.getSize(); i++)
	{
		studentsArray.getElementAt(i)->print();
	}
}
