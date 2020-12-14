#pragma once
#ifndef CVICENI_09_JVZ_H
#define CVICENI_09_JVZ_H

#include "APotrubniPrvek.h"

struct JVZ : APotrubniPrvek {
public:
    JVZ(int x, int y);
    ~JVZ() override;
    virtual bool jeKorektneZapojen(const IPotrubi* potrubi) const override;
private:

};

#endif //CVICENI_09_JVZ_H