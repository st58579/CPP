#include "JVZ.h"

JVZ::JVZ(int x, int y)
{
	this->x = x;
	this->y = y;
}

JVZ::~JVZ()
{
}

bool JVZ::jeKorektneZapojen(const IPotrubi* potrubi) const
{
	if (x == 0 || x == potrubi->getSize() - 1 || potrubi->DejPrvek(x + 1, y) == nullptr || (potrubi->DejPrvek(x - 1, y)) == nullptr
		|| y == potrubi->getSize() -1 || potrubi->DejPrvek(x, y+1) == nullptr) {
		return false;
	}
	return true;
}
