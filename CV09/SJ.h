#pragma once
#ifndef CVICENI_09_SJ_H
#define CVICENI_09_SJ_H

#include "APotrubniPrvek.h"

struct SJ : APotrubniPrvek {
public:
    SJ(int x, int y);
    ~SJ() override;
    virtual bool jeKorektneZapojen(const IPotrubi* potrubi) const override;
private:

};

#endif //CVICENI_09_SJ_H