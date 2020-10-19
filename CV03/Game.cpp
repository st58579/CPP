#include "Game.h"
#include "Object.h"
#include "Monstrum.h"
#include "MoveObject.h"
#include "StaticObject.h"

Game::Game(int maxAmountOfObjects)
{
	objects = new Object * [maxAmountOfObjects];
}

Game::~Game()
{
}

void Game::putObject(Object* o)
{
	objects[objectsCount++] = o;
}

int* Game::getStaticObjectsId(double xmin, double xmax, double ymin, double ymax) const
{
	int* poleId = new int[objectsCount+1];
	poleId[0] = 0; //pocet objectu
	int count = 0;
	for (size_t i = 0; i < objectsCount; i++)
	{
		Object* object = objects[i];
		StaticObject* so = dynamic_cast<StaticObject*>(object);
		if (so != nullptr) {
			if (objects[i]->GetX() >= xmin && objects[i]->GetX() <= xmax
				&& objects[i]->GetY() > ymin && objects[i]->GetY() <= ymax) {
				poleId[0]++;
				poleId[poleId[0]] = objects[i]->GetID();
			}
		}
	}
	return poleId;
}

MoveObject** Game::getMoveObjectsInArea(double x, double y, double r) const
{		
	MoveObject** pole = new MoveObject*[20];
	int count = 0;
	for (size_t i = 0; i < objectsCount; i++)
	{
		Object* object = objects[i];
		MoveObject* mo = dynamic_cast<MoveObject*>(object);
		if (mo != nullptr) {
			int x = objects[i]->GetX();
			int y = objects[i]->GetY();
			if (x*x + y*y <= r*r) {
				pole[count] = dynamic_cast<MoveObject*>(objects[i]);
				count++;
				}
		}
	}
	return pole;
}

MoveObject** Game::getMoveObjectsInArea(double x, double y, double r, double umin, double umax) const
{
	MoveObject** pole = new MoveObject * [20];
	int count = 0;
	for (size_t i = 0; i < objectsCount; i++)
	{
		Object* object = objects[i];
		MoveObject* mo = dynamic_cast<MoveObject*>(object);
		if (mo != nullptr) {
			int x = objects[i]->GetX();
			int y = objects[i]->GetY();
			double angle = mo->GetAngle();
			if (x * x + y * y <= r * r) {
				if (angle >= umin && angle <= umax) {
					pole[count] = dynamic_cast<MoveObject*>(objects[i]);
					count++;
				}
			}
		}
	}
	return pole;
}
