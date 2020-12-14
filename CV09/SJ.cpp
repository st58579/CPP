#include "SJ.h"

SJ::SJ(int x, int y)
{
	this->x = x;
	this->y = y;
}

SJ::~SJ()
{
}

bool SJ::jeKorektneZapojen(const IPotrubi* potrubi) const
{
	if (y == 0 || y == potrubi->getSize() - 1 || potrubi->DejPrvek(x, y+1) == nullptr || (potrubi->DejPrvek(x, y-1)) == nullptr) {
		return false;
	}
	return true;
}
