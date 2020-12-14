#pragma once
#ifndef CVICENI_09_SJVZ_H
#define CVICENI_09_SJVZ_H

#include "APotrubniPrvek.h"

struct SJVZ : APotrubniPrvek {
public:
    SJVZ(int x, int y);
    ~SJVZ() override;
    virtual bool jeKorektneZapojen(const IPotrubi* potrubi) const override;
private:

};

#endif //CVICENI_09_SJVZ_H