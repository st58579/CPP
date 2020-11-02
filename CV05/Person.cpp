#include "Person.h"



namespace Entity {

	Person::Person() : Person(nullptr, nullptr, 0)
	{
	}

	Person::Person(std::string name, std::string phone, int id) : name(name), phone(phone), id(id)
	{
	}

	Person::~Person()
	{
	}

	int Person::getId() const
	{
		return id;
	}

	std::string Person::getName() const
	{
		return name;
	}

	std::string Person::getPhone() const
	{
		return phone;
	}
}