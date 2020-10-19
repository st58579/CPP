#pragma once
#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H
#include "Object.h"

class StaticObject : public Object {
public:
	enum TypeOfObstacle {rock, smallPlant, bigPlant};
	StaticObject(int id, int x, int y, TypeOfObstacle type);
	~StaticObject();
	TypeOfObstacle GetTypeOfObstacle() const;
private:
	TypeOfObstacle type;
};


#endif //STATIC_OBJECT_H
