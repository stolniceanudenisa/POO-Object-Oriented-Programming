//
// Created by user on 25-May-23.
//

#include "Service.h"

void Service::functie_c(ListaDeAngajati &l) {
    Angajat a1("George",100,"Elementare");
    Angajat a2("Ana",100,"Medii");
    Angajat a3("Mara",100,"Superioare");
    l.add(a1);
    l.add(a2);
    l.add(a3);
}

void Service::functie_d(ListaDeAngajati &l) {
    for(int i=0;i<l.getNrAngajati();i++)
    {
        Angajat angajat = l.element_at(i);
        if(angajat.getStudii() == "Medii")
        {
            float salar = angajat.getSalar();
            l.element_at(i).setSalar(0.1*salar + salar);
        }
    }
}

int Service::return_x() {
    return x;
}
