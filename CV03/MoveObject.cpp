#include "MoveObject.h"
#include "Object.h"

MoveObject::MoveObject(int id, int x, int y, double rotationAngle) : Object(id, x, y), rotationAngle(rotationAngle)
{
}

MoveObject::~MoveObject()
{
}

double MoveObject::GetAngle()
{
	return rotationAngle;
}
