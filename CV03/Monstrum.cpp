#include "Monstrum.h"

Monstrum::Monstrum(int id, int x, int y, int rotationAngle, int hp, int maxHp):
	MoveObject(id, x, y, rotationAngle), hp(hp), maxHp(maxHp)
{
}

Monstrum::~Monstrum()
{
}



int Monstrum::GetHp() const
{
	return hp;
}

int Monstrum::GetMaxHp() const
{
	return maxHp;
}

void Monstrum::setHp(int hp)
{
	this->hp = hp;
}

void Monstrum::setMaxHp(int maxHp)
{
	this->maxHp = maxHp;
}

