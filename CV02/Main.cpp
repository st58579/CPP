#include <iostream>
#include "CashRegister.h"
int main() {
    CashRegister* cr = new CashRegister();
    cr->CreateReceipt(1000, 0.20);
    cr->CreateReceipt(2000, 0.30);
    cr->CreateReceipt(3000, 0.15);
    std::cout << cr->GetTotalCost() << std::endl;
    std::cout << cr->GetTotalCostWithVat() << std::endl;
    cr->GetReceipt(1001).SetCost(5000);
    std::cout << cr->GetTotalCost() << std::endl;
    std::cout << cr->GetTotalCostWithVat() << std::endl;
    return 0;
}
