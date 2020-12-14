#pragma once
#ifndef CVICENI_09_APOTRUBNIPRVEK_H
#define CVICENI_09_APOTRUBNIPRVEK_H

#include "IPotrubi.h"

struct APotrubniPrvek {
    virtual ~APotrubniPrvek();  
    virtual bool jeKorektneZapojen(const IPotrubi* potrubi) const = 0;
    int x;
    int y;
};

#endif //CVICENI_09_APOTRUBNIPRVEK_H
