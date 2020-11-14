#include <iostream>
#include "GrowingContainer.h"
#include <string>

using namespace std;

int main() {
    GrowingContainer<string, 5> gc{};
    gc.add("Zero str");
    gc.add("First str");
    gc.add("Second str");
    gc.add("Third str");
    gc.add("Fourth str");
    gc.add("Fifth str");
    gc.add("Sixth str");
    gc.add("Seventh str");
    gc.add("Eights str");

    cout << gc[3] << endl;
    cout << gc[7] << endl;
    gc.addOnIndex(7, "Added str");
    cout << gc[7] << endl;
    cout << gc[8] << endl;
    gc.remove(7);
    cout << gc[7] << endl;
    return 0;
}
