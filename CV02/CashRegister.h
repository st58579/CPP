#pragma once
#ifndef CASHREGISTER_H
#define CASHREGISTER_H
#include "Receipt.h"
class CashRegister {
    Receipt* receipts;
    int receiptsCount = 0;
    static int counter;
public:
    CashRegister();
    ~CashRegister();
    Receipt& CreateReceipt(double cost, double vat);
    Receipt& GetReceipt(int id);
    double GetTotalCost() const;
    double GetTotalCostWithVat() const;
};
#endif //CASHREGISTER_H
