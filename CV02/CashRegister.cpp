#include "CashRegister.h"
#include <exception>

int CashRegister::counter = 1000;

CashRegister::CashRegister() {
    receipts = new Receipt[10];
}

CashRegister::~CashRegister() {
    delete[] receipts;
}

Receipt& CashRegister::CreateReceipt(double cost, double vat) {
    if (receiptsCount == 10) {
        throw new std::exception("Cash register is full");
    }
    /*if (receiptsCount == 0) {
        receipts[0].SetId(counter + receiptsCount);
        receipts[0].SetCost(cost);
        receipts[0].SetVat(vat);
    }*/
    //else {
        receipts[receiptsCount].SetId(counter + receiptsCount);
        receipts[receiptsCount].SetCost(cost);
        receipts[receiptsCount].SetVat(vat);
    //}
    receiptsCount++;
    return receipts[receiptsCount];
}

Receipt& CashRegister::GetReceipt(int id) {
    for (int i = 0; i < 10; ++i) {
        if (receipts[i].GetId() == id) {
            return receipts[i];
        }
    }
    return receipts[0];
}

double CashRegister::GetTotalCost() const {
    double totalCost = 0;
    for (int i = 0; i < receiptsCount; ++i) {
        totalCost += receipts[i].GetCost();
    }
    return totalCost;
}

double CashRegister::GetTotalCostWithVat() const {
    double totalCostWithVat = 0;
    for (int i = 0; i < receiptsCount; ++i) {
        double cost = receipts[i].GetCost();
        double vat = receipts[i].GetVat();
        totalCostWithVat += cost*(1+vat);
    }
    return totalCostWithVat;
}