#include "StaticObject.h"


StaticObject::StaticObject(int id, int x, int y, StaticObject::TypeOfObstacle type) : Object(id,x,y)
{
	this->type = type;
}

StaticObject::~StaticObject()
{
}

StaticObject::TypeOfObstacle StaticObject::GetTypeOfObstacle() const
{
	return type;
}


