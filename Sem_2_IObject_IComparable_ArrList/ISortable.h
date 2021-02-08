#pragma once
#ifndef ISORTABLE_H
#define ISORTABLE_H
#include "IComparable.h"

class ISortable {
	virtual int size() const = 0;
	virtual IComparable* get(int pos) = 0;
	virtual void set(int i, IComparable* ic) = 0;
};

#endif // !ISORTABLE_H
