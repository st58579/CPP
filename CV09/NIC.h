#pragma once
#ifndef CVICENI_09_NIC_H
#define CVICENI_09_NIC_H

#include "APotrubniPrvek.h"

struct NIC : APotrubniPrvek {
public:
    NIC(int x, int y);
    ~NIC() override;
    virtual bool jeKorektneZapojen(const IPotrubi* potrubi) const override;
private:

};

#endif //CVICENI_09_NIC_H