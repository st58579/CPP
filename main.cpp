#include <iostream>

struct Trojuhelnik {
    int a, b, c;
};

bool lzeSestrojit(Trojuhelnik *t) {
    if (t->a + t->b > t->c & t->a + t->c > t->b & t->b + t->c > t->a) return true;
    else return false;
}

int main() {
    int pocetTrojuhelniku;
    bool pocetNacten = false;
    while (!pocetNacten) {
        std::
        cout << "Kolik chcete načíst trojúhelníků?" << std::endl;
        std::cin >> pocetTrojuhelniku;
        if (pocetTrojuhelniku > 0) {
            pocetNacten = true;
        } else {
            std::cout << "pocet nemuze byt < 1, zkuste znova";
        }
    }
    auto *poleTrojuhelniku = new Trojuhelnik[pocetTrojuhelniku];
    for (int i = 0; i < pocetTrojuhelniku; i++) {
        std::
        cout << "Zadejte hodnoty stran a, b, c pro " << i+1 << ". trojuhelnik : ";
        std::
        cin >> poleTrojuhelniku[i].a >> poleTrojuhelniku[i].b >> poleTrojuhelniku[i].c;
        if(lzeSestrojit(&poleTrojuhelniku[i])) {
            std::
            cout << "obvod " << i + 1 << ". trojuhelniku = "
                 << poleTrojuhelniku[i].a + poleTrojuhelniku[i].b + poleTrojuhelniku[i].c << std::endl;
        } else {
            std::cout << i+1 << ". trojuhelnik sestrojit nelze" << std::endl;
        }
    }
    delete[] poleTrojuhelniku;
    return 0;
}
