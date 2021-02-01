#include "Prvek.h"

Prvek::Prvek(std::string klic)
{
	this->klic = klic;
}

Prvek::~Prvek()
{
}

SpojovySeznam* Prvek::getSeznam() const
{
	return data;
}

std::string Prvek::getKlic() const
{
	return klic;
}

Prvek* Prvek::getDalsi() const
{
	return dalsi;
}

void Prvek::setSeznam(SpojovySeznam* data)
{
	this->data = data;
}

void Prvek::setKlic(std::string klic)
{
	this->klic = klic;
}

void Prvek::setDalsi(Prvek* dalsi)
{
	this->dalsi = dalsi;
}
