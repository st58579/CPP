#pragma once
#ifndef CVICENI_09_IPOTRUBI_H
#define CVICENI_09_IPOTRUBI_H

#include "APotrubniPrvek.h"
#include <string>

struct IPotrubi {
public:
    virtual ~IPotrubi();
    virtual const APotrubniPrvek* DejPrvek(int x, int y) const = 0;
    virtual bool jePotrubiOk() const = 0;
    virtual int getSize() const = 0;
};

#endif //CVICENI_09_IPOTRUBI_H
