#pragma once
#ifndef MOVE_OBJECT_H
#define MOVE_OBJECT_H
#include "Object.h"

class MoveObject : public Object {
public:
	MoveObject(int id, int x, int y, double rotationAngle);
	virtual ~MoveObject();
	double GetAngle();
private:
	double rotationAngle;
};

#endif // MOVE_OBJECT_H