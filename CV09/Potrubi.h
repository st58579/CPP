#pragma once
#ifndef CVICENI_09_POTRUBI_H
#define CVICENI_09_POTRUBI_H

#include "IPotrubi.h"
#include "APotrubniPrvek.h"

struct Potrubi : IPotrubi {
public:
	Potrubi(int size, char* data);
	~Potrubi() override;
	const APotrubniPrvek* DejPrvek(int x, int y) const override;
	bool jePotrubiOk() const override;
	int getSize() const override;
private:
	int size;
	APotrubniPrvek** seznam;
};

#endif CVICENI_09_POTRUBI_H
