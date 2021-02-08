#pragma once
#ifndef IOBJECT_H
#define IOBJECT_H
#include <string>

class IObject {
	virtual std::string toString() = 0;
};

#endif // !IOBJECT_H
