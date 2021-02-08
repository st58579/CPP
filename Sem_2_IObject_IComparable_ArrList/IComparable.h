#pragma once
#ifndef ICOMPARABLE_H
#define ICOMPARABLE_H

class IComparable {
	virtual int compareTo(IComparable* c) const = 0;
};

#endif // !ICOMPARABLE_H