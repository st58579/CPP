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
		StringValue* name = new StringValue(dynamic_cast<StringValue*>(kvpName.getValue())->get());
		KeyValuePair kvpSurname = ov->get(j++);
		StringValue* surname = new StringValue(dynamic_cast<StringValue*>(kvpSurname.getValue())->get());
		KeyValuePair kvpDatum = ov->get(j++);
		StringValue* birthDate = new StringValue(dynamic_cast<StringValue*>(kvpDatum.getValue())->get());
		KeyValuePair kvpID = ov->get(j++);
		NumberValue* id = new NumberValue(dynamic_cast<NumberValue*>(kvpID.getValue())->get());
		KeyValuePair kvpYear = ov->get(j++);
		NumberValue* year = new NumberValue(dynamic_cast<NumberValue*>(kvpYear.getValue())->get());
		KeyValuePair kvpIsFirstStudy = ov->get(j++);
		BoolValue* isFirstStudy = new BoolValue(dynamic_cast<BoolValue*>(kvpIsFirstStudy.getValue())->get());
		KeyValuePair kvpSubjects = ov->get(j++);
		ArrayValue* sbj = dynamic_cast<ArrayValue*>(kvpSubjects.getValue());
		ArrayValue* arrayv = new ArrayValue();
		for (size_t i = 0; i < sbj->getSize(); i++)
		{
			arrayv->append(sbj->get(i));
		}
		
		Student* st = new Student(name, surname, birthDate, id, year, isFirstStudy, arrayv);
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

std::string EvidenceStudentu::serialize() const
{
	std::string str = "[";
	for (size_t i = 0; i < studentsArray.getSize(); i++)
	{
		str.append(studentsArray.getElementAt(i)->serialize());
		if (i+1 < studentsArray.getSize()) str.append(",");
	}
	str.append("]");
	return str;
}
