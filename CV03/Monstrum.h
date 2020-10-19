#pragma once
#ifndef MONSTRUM_H
#define MONSTRUM_H
#include "MoveObject.h"
class Monstrum : public MoveObject {
public:
	Monstrum(int id, int x, int y, int rotationAngle, int hp, int maxHp);
	~Monstrum();
	int GetHp() const;
	int GetMaxHp() const;
	void setHp(int hp);
	void setMaxHp(int maxHp);
private:
	int hp;
	int maxHp;
};


#endif //MONSTRUM_H