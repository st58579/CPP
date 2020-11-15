#include <iostream>
#include "GrowingContainer.h"
#include <string>

using namespace std;

int main() {
    GrowingContainer<string, 5> gc{};
    gc.add("0 str");
    gc.add("1 str");
    gc.add("2 str");
    gc.add("3 str");
    gc.add("4 str");
    gc.add("5 str");
    gc.add("6 str");
    gc.add("7 str");
    gc.add("8 str");

    cout << gc[3] << endl;
    cout << gc[7] << endl;
    gc.addOnIndex(7, "Added str");
    cout << gc[7] << endl;
    cout << gc[8] << endl;
    gc.remove(7);
    cout << gc[7] << endl;
    return 0;
}
