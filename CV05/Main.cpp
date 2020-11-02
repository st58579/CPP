#include "PhoneList.h"

#include <iostream>
using namespace std;

int main() {
	Model::PhoneList pl = Model::PhoneList();
	pl.addPerson(new Entity::Person("Name1", "phone1", 1));
	pl.addPerson(new Entity::Person("Name2", "phone2", 2));
	pl.addPerson(new Entity::Person("Name3", "phone3", 3));
	pl.addPerson(new Entity::Person("Name4", "phone4", 4));
	pl.addPerson(new Entity::Person("Name5", "phone5", 5));

	cout << pl.getPhone(3) << endl;
	cout << pl.getPhone("Name4") << endl;
}