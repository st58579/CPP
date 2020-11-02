#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <iostream>

namespace Entity {
	class Person {
	public:
		Person();
		Person(std::string name, std::string phone, int id);
		~Person();
		int getId() const;
		std::string getName() const;
		std::string getPhone() const;
	private:
		std::string name;
		std::string phone;
		int id;
	};
}

#endif // !PERSON_H
