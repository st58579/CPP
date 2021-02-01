#pragma once
#include "SpojovySeznam.h"

class SmerovyAdresar {
public:
	SmerovyAdresar();
	~SmerovyAdresar();
	void vloz(std::string mesto, std::string psc, std::string ulice);
	bool najdiRozsahPsc(std::string mesto, std::string& pscmin, std::string& pscmax);
	void vypis();
private:
	SpojovySeznam mesta;
};