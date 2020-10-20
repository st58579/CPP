#include "Game.h"
#include "Object.h"
#include "Monstrum.h"
#include "MoveObject.h"
#include "StaticObject.h"
#include <iostream>
using namespace std;

Game::Game() : Game(10){
}

Game::Game(int maxAmountOfObjects)
{
	objects = new Object * [maxAmountOfObjects];
	for (size_t i = 0; i < maxAmountOfObjects; i++)
	{
		objects[i] = nullptr;
	}
	maxSize = maxAmountOfObjects;
}

Game::~Game()
{
	for (size_t i = 0; i < maxSize; i++)
	{
		delete objects[i];
	}
	delete[] objects;
}

void Game::putObject(Object* o)
{
	if (objectsCount < maxSize) {
		objects[objectsCount++] = o;
	}
	else {
		cout << "prekroceni max. velikosti!";
	}
}

int* Game::getStaticObjectsId(double xmin, double xmax, double ymin, double ymax) const
{
	int* arrayId = new int[objectsCount+1];
	arrayId[0] = 0; //pocet objectu
	int count = 0;
	for (size_t i = 0; i < objectsCount; i++)
	{
		StaticObject* so = dynamic_cast<StaticObject*>(objects[i]);
		if (so != nullptr) {
			if (objects[i]->GetX() >= xmin && objects[i]->GetX() <= xmax
				&& objects[i]->GetY() > ymin && objects[i]->GetY() <= ymax) {
				arrayId[0]++;
				arrayId[arrayId[0]] = objects[i]->GetID();
			}
		}
	}
	return arrayId;
}

MoveObject** Game::getMoveObjectsInArea(double x, double y, double r) const
{		
	MoveObject** arrayId = nullptr;
	int count = 0;
	for (size_t i = 0; i < objectsCount; i++)
	{
		MoveObject* mo = dynamic_cast<MoveObject*>(objects[i]);
		if (mo != nullptr) {
			int x = objects[i]->GetX();
			int y = objects[i]->GetY();
			if (x * x + y * y <= r * r) {
				count++;
			}
		}
	}
	if (count > 0) {
		arrayId = new MoveObject * [count];
		count = 0;
		for (size_t i = 0; i < objectsCount; i++)
		{
			MoveObject* mo = dynamic_cast<MoveObject*>(objects[i]);
			if (mo != nullptr) {
				int x = objects[i]->GetX();
				int y = objects[i]->GetY();
				if (x * x + y * y <= r * r) {
					arrayId[count] = mo;
					count++;
				}
			}
		}
	}
	return arrayId;
}

MoveObject** Game::getMoveObjectsInArea(double x, double y, double r, double umin, double umax) const
{
	MoveObject** arrayId = nullptr;
	int count = 0;
	for (size_t i = 0; i < objectsCount; i++)
	{
		MoveObject* mo = dynamic_cast<MoveObject*>(objects[i]);
		if (mo != nullptr) {
			int x = objects[i]->GetX();
			int y = objects[i]->GetY();
			double angle = mo->GetAngle();
			if (x * x + y * y <= r * r) {
				if (angle >= umin && angle <= umax) {
					count++;
				}
			}
		}
	}
	if (count > 0) {
		arrayId = new MoveObject * [count];
		count = 0;
		for (size_t i = 0; i < objectsCount; i++)
		{
			MoveObject* mo = dynamic_cast<MoveObject*>(objects[i]);
			if (mo != nullptr) {
				int x = objects[i]->GetX();
				int y = objects[i]->GetY();
				double angle = mo->GetAngle();
				if (x * x + y * y <= r * r) {
					if (angle >= umin && angle <= umax) {
						arrayId[count] = mo;
						count++;
					}
				}
			}
		}
	}
	return arrayId;
}
