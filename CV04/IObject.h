#pragma once
#ifndef IOBJECT_H
#define IOBJECT_H
#include <iostream>
class IObject {
public:
	virtual std::string toString() = 0;
};
#endif // IObject_H