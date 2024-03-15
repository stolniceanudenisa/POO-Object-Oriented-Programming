#include <iostream>
#include "repository/ListaDeAngajati.h"
#include "service/Service.h"
#include "util/MyException.h"

int main() {
    ListaDeAngajati l;
    Service s;
    s.functie_c(l);
    s.functie_d(l);
    std::cout<<Service::return_x();
    try{
        std::cout<<l.element_at(-1).toString();
//        std::cout<<123191991;
    }
    catch (MyException &e)
    {
//        std::cout<<e.what()<<std::endl;
//            throw;
    }
    for(int i = 0;i<l.getNrAngajati();i++)
    {
        std::cout<<l.element_at(i).toString()<<std::endl;
    }
    return 0;
}
