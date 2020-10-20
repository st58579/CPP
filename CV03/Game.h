#pragma once
#ifndef GAME_H
#define GAME_H
#include "Object.h"
#include "StaticObject.h"
#include "MoveObject.h"
class Game {
public:
	Game();
	Game(int maxAmountOfObjects);
	~Game();
	void putObject(Object* o);
	int* getStaticObjectsId(double xmin, double xmax, double ymin, double ymax) const;
	MoveObject** getMoveObjectsInArea(double x, double y, double r) const;
	MoveObject** getMoveObjectsInArea(double x, double y, double r, double umin, double umax) const;
private: 
	Object** objects;
	int objectsCount = 0;
	int maxSize;
};

#endif //GAME_H
