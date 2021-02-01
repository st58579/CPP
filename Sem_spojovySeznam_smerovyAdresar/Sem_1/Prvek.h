#pragma once
#include <string>
#include "SpojovySeznam.h"

class SpojovySeznam;

class Prvek {
public:
	Prvek(std::string klic);
	~Prvek();
	SpojovySeznam* getSeznam() const;
	std::string getKlic() const;
	Prvek* getDalsi() const;
	void setSeznam(SpojovySeznam* data);
	void setKlic(std::string klic);
	void setDalsi(Prvek* dalsi);
private:
	std::string klic;
	Prvek* dalsi;
	SpojovySeznam* data;
};