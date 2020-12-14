#include "NIC.h"

NIC::NIC(int x, int y)
{
	this->x = x;
	this->y = y;
}

NIC::~NIC()
{
}

bool NIC::jeKorektneZapojen(const IPotrubi* potrubi) const
{
	return true;
}
