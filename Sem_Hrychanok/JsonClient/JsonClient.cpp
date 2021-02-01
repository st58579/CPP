
#include <iostream>
#include <api.h>
#include "EvidenceStudentu.h"
#include <crtdbg.h>

#define _CRTDBG_MAP_ALLOC
using namespace std;
int main()
{
    string s = "[{\"name:\":\"Prvni\", \"surname\":\"prvnisur\", \"datum narozeni\":\"12.12.1999\", \"id\":1, \"rocnik\":1,\"je prvni studium\":true, \"pole predmetu\":[\"matika\", \"algebra\", \"hujalgebra\"]},{\"name:\":\"Druhy\", \"surname\":\"Druhysur\", \"datum narozeni\":\"22.22.2222\", \"id\":2, \"rocnik\":2,\"je prvni studium\":false, \"pole predmetu\":[\"dagestan\", \"cipacany\"]}, {\"name:\":\"treti\", \"surname\":\"tretisur\", \"datum narozeni\":\"22.22.2222\", \"id\":2, \"rocnik\":2,\"je prvni studium\":false, \"pole predmetu\":[\"dagestan\", \"cipacany\"]}]";
    ArrayValue* av = dynamic_cast<ArrayValue*>(JSON::deserialize(s));
    /*EvidenceStudentu ev = EvidenceStudentu();
    ev.process(av);
    ev.print();*/
   // cout << "serializace : " << endl << endl << ev.serialize() << endl << endl << endl;
    delete av;



    ////////////////////////////////////////////////////////////
 /*   EvidenceStudentu ev = EvidenceStudentu();
    string str;
    bool cycle = true;
    ArrayValue* av;
    cout << "Vitam v programu. Tato aplikace umi spravovat seznamu studentu." << endl;
    while (cycle) {
        cout << "Pro zadani JSONu zadejte 1, pro vypis skupiny studentu zadejte 2, pro editace studentu zadejte 3, pro vytvoreni JSONu z dat studentu zadejte 4, pro ukonceni programu zadejte cokoliv jineho." << endl;
        char choice;
        cin >> choice;
        switch (choice)
        {
        case '1':
            cout << "Zadejte JSON:" << endl;
            std::getline(std::cin >> std::ws, str);
            av = dynamic_cast<ArrayValue*>(JSON::deserialize(str));
            ev.process(av);
            cout << "Uspech." << endl;
            break;
        case '2':
            ev.print();
            break;
        case '3': 
            break;
        case '4':
            cout << ev.serialize() << endl;
        default:
            cycle = false;
            break;
        }
        
    }*/
    
    if (_CrtDumpMemoryLeaks() == 0) {
        std::cout << "No memory leaks" << std::endl;
    }
    else {
        std::cout << "Yes memory leaks" << std::endl;
    }
    return 0;
}

