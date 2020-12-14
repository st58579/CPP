#include "SJVZ.h"

SJVZ::SJVZ(int x, int y)
{
	this->x = x;
	this->y = y;
}

SJVZ::~SJVZ()
{
}

bool SJVZ::jeKorektneZapojen(const IPotrubi* potrubi) const
{
	if (x == 0 || x == potrubi->getSize() - 1 || potrubi->DejPrvek(x + 1, y) == nullptr || (potrubi->DejPrvek(x - 1, y)) == nullptr
		|| y == 0 || y == potrubi->getSize() - 1 || potrubi->DejPrvek(x, y + 1) == nullptr || (potrubi->DejPrvek(x, y - 1)) == nullptr) {
		return false;
	}
	return true;
}
