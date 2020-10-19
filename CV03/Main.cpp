#include "Game.h"
#include "Monstrum.h"
#include <iostream>
using namespace std;

int main(){
	Game* game = new Game(20);
	game->putObject(new StaticObject(1, 2, 3, StaticObject::rock));
	game->putObject(new StaticObject(2, 2, 3, StaticObject::rock));
	game->putObject(new StaticObject(3, 2, 3, StaticObject::rock));
	int* poleId = game->getStaticObjectsId(-5,5,-5,5);
	for (size_t i = 1; i <= poleId[0]; i++)
	{
		cout << poleId[i] << " ,";
	}
	cout << endl;
	game->putObject(new MoveObject(4, 4, 4, 20.0));
	game->putObject(new MoveObject(5, 5, 5, 30.0));
	game->putObject(new MoveObject(6, 15, 15, 30.0));
	game->putObject(new Monstrum(7,7,7,15,5,15));
	game->putObject(new MoveObject(8, 8, 8, 20.0));
	game->putObject(new MoveObject(9, 9, 9, 40.0));
	size_t j = 0;
	MoveObject** poleMo = game->getMoveObjectsInArea(0,0,15);
	for (size_t i = 0; i < 5; i++)
	{
		cout << poleMo[j]->GetID() << " ,";
		j++;
	}
	cout << endl;
	j = 0;
	poleMo = game->getMoveObjectsInArea(0, 0, 15, 10, 35);
	for (size_t i = 0; i < 4; i++)
	{
		cout << poleMo[j]->GetID() << " ,";
		j++;
	}
	
	return 0;
}