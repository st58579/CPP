#pragma once
#ifndef PHONE_LIST_H
#define PHONE_LIST_H
#include <iostream>
#include "Person.h"

namespace Model {
	class PhoneList {
		struct Node {
			Node* next;
			Entity::Person* data;
			Node(Entity::Person* data) {
				this->data = data;
				next = nullptr;
			}
		};

	public:
		PhoneList();
		~PhoneList();
		void addPerson(Entity::Person* p);
		std::string getPhone(std::string name) const;
		std::string getPhone(int id) const;

	private:
		Node* first;
	};

}


#endif //PHONE_LIST_H