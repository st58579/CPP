#pragma once
#ifndef ICOMPARABLE_H
#define ICOMPARABLE_H

#include <string>
#include "IObject.h"

class IComparable : public IObject{
public:
	virtual int compareTo(IComparable* obj) = 0;
};

#endif // !ICOMPARABLE_H