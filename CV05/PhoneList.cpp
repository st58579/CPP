#include "PhoneList.h"
#include <exception>
using namespace Entity;


namespace Model {
	PhoneList::PhoneList()
	{
		first = nullptr;
	}

	PhoneList::~PhoneList()
	{
		while (first != nullptr) {
			Node* tmp = first->next;
			delete first;
			first = tmp;
		}
	}

	void PhoneList::addPerson(Person* p)
	{
		if (first == nullptr) {
			first = new Node(p);
		}
		else {
			Node* tmp = first;
			first = new Node(p);
			first->next = tmp;
		}
	}

	std::string PhoneList::getPhone(std::string name) const
	{
		if (name.size() <= 0) {
			throw std::exception("Parameter name can not be less than 1");
		}
		else {
			Node* pointer = first;
			while (pointer != nullptr) {
				if (pointer->data->getName() == name) {
					return pointer->data->getPhone();
				}
				else {
					pointer = pointer->next;
				}
			}
			throw std::exception("Person was not found");
		}
	}

	std::string PhoneList::getPhone(int id) const
	{
		if (id < 0) {
			throw std::exception("Parameter id can not be less than 0");
		}
		else {
			Node* pointer = first;
			while (pointer != nullptr) {
				if (pointer->data->getId() == id) {
					return pointer->data->getPhone();
				}
				else {
					pointer = pointer->next;
				}
			}
			throw std::exception("Person was not found");
		}
	}
}