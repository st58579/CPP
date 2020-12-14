#include "VZ.h"

VZ::VZ(int x, int y)
{
	this->x = x;
	this->y = y;
}

VZ::~VZ()
{
}

bool VZ::jeKorektneZapojen(const IPotrubi* potrubi) const
{
	if (x == 0 || x == potrubi->getSize() - 1 || potrubi->DejPrvek(x + 1, y) == nullptr || (potrubi->DejPrvek(x - 1, y)) == nullptr) {
		return false;
	}
	return true;
}
