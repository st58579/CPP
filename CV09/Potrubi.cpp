#include "Potrubi.h"
#include "VZ.h"
#include "SJ.h"
#include "JVZ.h"
#include "SJVZ.h"
#include "NIC.h"

Potrubi::Potrubi(int size, char* data)
{
	int counter = 0;
	seznam = new APotrubniPrvek*[size];
	for (size_t i = 0; i < size; i++)
	{
		seznam[i] = new APotrubniPrvek[size]; //abstraktni trida
	}
	for (size_t x = 0; x < size; x++)
	{
		for (size_t y = 0; y < size; y++)
		{
			seznam[x][y] = getData(data, counter, x, y); //abstraktni trida
		}
	}
}

APotrubniPrvek* getData(char* data, int counter, int x, int y) {
	switch (data[counter]) {
	case '-':
		return new VZ(x, y);
		break;
	case 'I':
		return new SJ(x, y);
		break;
	case '+':
		return new SJVZ(x, y);
		break;
	case 'O':
		return new NIC(x, y);
		break;
	case 'T':
		return new JVZ(x, y);
		break;
	default :
		return nullptr;
	}
}

Potrubi::~Potrubi()
{
	for (size_t i = 0; i < size; i++)
	{
		delete[] seznam[i];
	}
	delete seznam;
}

const APotrubniPrvek* Potrubi::DejPrvek(int x, int y) const
{
	return nullptr;
}

bool Potrubi::jePotrubiOk() const
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (seznam[i][j] != nullptr) {
				if (seznam[i][j].jeKorektneZapojen(this) == false) return false; //this?
			}
		}
	}
	return true;
}

int Potrubi::getSize() const
{
	return size;
}
