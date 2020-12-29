
#include <iostream>
#include <api.h>
#include "EvidenceStudentu.h"
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
    
int main()
{
    _CrtSetBreakAlloc(160);
    std::string str = "[{\"name:\":\"Prvni\", \"surname\":\"prvnisur\", \"datum narozeni\":\"12.12.1999\", \"id\":1, \"rocnik\":1,\"je prvni studium\":true, \"pole predmetu\":[\"matika\", \"algebra\", \"hujalgebra\"]},{\"name:\":\"Druhy\", \"surname\":\"Druhysur\", \"datum narozeni\":\"22.22.2222\", \"id\":2, \"rocnik\":2,\"je prvni studium\":false, \"pole predmetu\":[\"dagestan\", \"cipacany\"]}]";
    ArrayValue* av = dynamic_cast<ArrayValue*>(JSON::deserialize(str));
    EvidenceStudentu ev = EvidenceStudentu();

   ev.process(av);
   ev.print();
   delete av;
   if (_CrtDumpMemoryLeaks() == 0) {
       std::cout << "No memory leaks" << std::endl;
   }
   else {
       std::cout << "Yes memory leaks" << std::endl;
   }
   return 0;
}
    
