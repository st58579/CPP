#include "Object.h"

Object::Object(int id, int x, int y) : id(id), x(x), y(y)
{
}

double Object::GetX()const
{
	return x;
}

double Object::GetY()const
{
	return y;
}

int Object::GetID()const
{
	return id;
}

void Object::SetX(double x)
{
	this->x = x;
}

void Object::SetY(double y)
{
	this->y = y;
}

void Object::SetID(int id)
{
	this->id = id;
}


