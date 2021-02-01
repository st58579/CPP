#include "SpojovySeznam.h"
#include <exception>
#include <iostream>

using namespace std;

SpojovySeznam::SpojovySeznam()
{
	prvni = nullptr;
	aktualni = nullptr;
}

SpojovySeznam::SpojovySeznam(Prvek* klic)
{
	prvni = klic;
	aktualni = prvni;
}

SpojovySeznam::~SpojovySeznam()
{
	while (prvni != nullptr) {
		Prvek* tmp = prvni;
		prvni = prvni->getDalsi();
		delete tmp;
	}
}

Prvek* SpojovySeznam::vloz(std::string klic)
{
	if (prvni == nullptr) prvni = new Prvek(klic);
	else {
		aktualni = prvni;
		while (aktualni->getDalsi() != nullptr) aktualni = aktualni->getDalsi();
		aktualni->setDalsi(new Prvek(klic));
	}
	return nullptr;
}

Prvek* SpojovySeznam::najdi(std::string klic)
{
	aktualni = prvni;
	while (aktualni->getDalsi() != nullptr) {
		if (aktualni->getKlic() == klic) break;
		else aktualni = aktualni->getDalsi();
	}
	return aktualni;
}

Prvek* SpojovySeznam::najdiNeboVloz(std::string klic)
{
	if(prvni == nullptr){
		prvni = new Prvek(klic);
		return nullptr;
	}
	else {
		aktualni = prvni;
		while (aktualni != nullptr) {
			if (aktualni->getKlic() == klic) {
				return aktualni;
			}
			else {
				aktualni = aktualni->getDalsi();
			}
		}
		vloz(klic);
		return nullptr;
	}
}

Prvek* SpojovySeznam::najdiExtrem(TypExtremu te)
{
	aktualni = prvni;
	if (aktualni == nullptr) return aktualni;
	if (te == Maximum) {
		std::string max = aktualni->getKlic();
		while (aktualni->getDalsi() != nullptr) {
			aktualni = aktualni->getDalsi();
			if (aktualni->getKlic().compare(max) > 0) max = aktualni->getKlic();
		}
		return najdi(max);
	}
	else {
		std::string min = aktualni->getKlic();
		while (aktualni->getDalsi() != nullptr) {
			aktualni = aktualni->getDalsi();
			if (aktualni->getKlic().compare(min) < 0) min = aktualni->getKlic();
		}
		return najdi(min);
	}
}

bool SpojovySeznam::jePrazdny()
{
	return prvni == nullptr;
}

void odsad(int odsazeni) {
	for (size_t i = 0; i < odsazeni; i++)
	{
		cout << " ";
	}
}

void SpojovySeznam::vypis(int odsazeni)
{
	if (prvni != nullptr) {
		aktualni = prvni;
		while (aktualni != nullptr) {
			odsad(odsazeni);
			cout << aktualni->getKlic() << endl;
			if (aktualni->getSeznam() != nullptr) {
				aktualni->getSeznam()->vypis(odsazeni + 2);
			}
			aktualni = aktualni->getDalsi();
		}
	}
	
}


