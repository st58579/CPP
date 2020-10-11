#pragma once
#ifndef RECEIPT_H
#define RECEIPT_H

class Receipt {
    int id;
    double cost;
    double vat;
public:
    //    Receipt(double cost, double vat, int id);
    void SetId(int id);

    int GetId();

    void SetVat(double vat);

    double GetVat();

    void SetCost(double cost);

    double GetCost();
};

#endif //RECEIPT_H