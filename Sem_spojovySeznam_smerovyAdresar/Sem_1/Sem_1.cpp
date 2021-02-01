
#include <iostream>
#include "Prvek.h"
#include "SpojovySeznam.h"
#include "SmerovyAdresar.h"

int main()
{
	SmerovyAdresar sm = SmerovyAdresar();
	sm.vloz("mesto1", "psc1", "ulice1");
	sm.vloz("mesto1", "psc2", "ulice1");
	sm.vloz("mesto1", "psc2", "ulice2");
	sm.vloz("mesto1", "psc2", "ulice3");
	sm.vloz("mesto1", "psc3", "ulice1");
	sm.vloz("mesto1", "psc3", "ulice2");
	sm.vloz("mesto2", "psc1", "ulice1");
	sm.vloz("mesto2", "psc1", "ulice3");
	sm.vloz("mesto2", "psc2", "ulice2");
	sm.vloz("mesto2", "psc2", "ulice4");
	sm.vloz("mesto2", "psc1", "ulice1");
	sm.vloz("mesto3", "psc2", "ulice9");
	sm.vypis();
}
