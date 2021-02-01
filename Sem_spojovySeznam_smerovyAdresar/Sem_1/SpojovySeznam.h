#pragma once
#include "Prvek.h"

class Prvek;

enum TypExtremu{Maximum, Minimum};

class SpojovySeznam {
public:
	SpojovySeznam();
	SpojovySeznam(Prvek* klic);
	~SpojovySeznam();
	Prvek* vloz(std::string klic);
	Prvek* najdi(std::string klic);
	Prvek* najdiNeboVloz(std::string klic);
	Prvek* najdiExtrem(TypExtremu te); 
	bool jePrazdny();
	void vypis(int odsazeni = 0);
private:
	Prvek* prvni;
	Prvek* aktualni;
};