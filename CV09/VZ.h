#pragma once
#ifndef CVICENI_09_VZ_H
#define CVICENI_09_VZ_H

#include "APotrubniPrvek.h"

struct VZ : APotrubniPrvek {
public:
    VZ(int x, int y);
    ~VZ() override;
    virtual bool jeKorektneZapojen(const IPotrubi* potrubi) const override;
private:

};

#endif //CVICENI_09_VZ_H