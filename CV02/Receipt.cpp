#include "Receipt.h"

void Receipt::SetId(int id) {
    this->id = id;
}
int Receipt::GetId() {
    return id;
}

void Receipt::SetVat(double vat) {
    this->vat = vat;
}
double Receipt::GetVat() {
    return vat;
}
void Receipt::SetCost(double cost) {
    this->cost = cost;
}
double Receipt::GetCost() {
    return cost;
}