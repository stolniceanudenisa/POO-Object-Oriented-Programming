//
// Created by 40766 on 15.04.2023.
//
#include <iostream>
#include <cstring>
#include "UI.h"
#include "tranzactie.h"
#include "repo.h"
#include <ctime>


using namespace std;

UI::UI(Service &service) : service(service) {

    char *in = new char[30];
    strcpy(in, "in");
    char *out = new char[30];
    strcpy(out, "out");
    char *mancare = new char[30];
    strcpy(mancare, "mancare");
    char *haine = new char[30];
    strcpy(haine, "haine");
    char *utilitati = new char[30];
    strcpy(utilitati, "utilitati");
    char *salariu = new char[30];
    strcpy(salariu, "salariu");
    service.add_elem_service(1,500,in, mancare);
    service.add_elem_service(2,200,out, haine);
    service.add_elem_service(3,60,out, mancare);
    service.add_elem_service(4,300,out, utilitati);
    service.add_elem_service(5,1000,in, salariu);
    service.add_elem_service(5,300,out, mancare);

}

UI::~UI() {

}

void UI::run_menu() {
    bool stop = true;
    int opt;
    //Repo repo;
    //Tranzactie tranzactie;

    time_t now = time(0);
    tm *ltm = localtime(&now);

    int current_day = ltm->tm_mday;


    while(stop)
    {
        cout<<endl;
        menu();
        cout<<endl;
        ui_afisare_elems();
        cout<<endl;
        cout<<"Alegeti o optiune: ";
        cin>>opt;

        if (opt == 1)
        {
            this->ui_add_tranz1();
        }
//        else if (opt == 11)
//        {
//            this->ui_add_tranz2();
//        }
        else if (opt == 21)
        {
            this->ui_modificare_tranzactie();
        }

        else if (opt == 2)
        {
            this->ui_modificare_tranzactie2();
        }


        else if (opt == 22)
        {
            this->ui_inlocuire_suma();
        }

        else if (opt == 3)
        {
            this->ui_stergere_tranz_zi();
        }

        else if (opt == 31)
        {
            this->ui_stergere_tranz_interval_zi();
        }

        else if (opt == 32)
        {
            this->ui_stergere_tranz_tip();
        }

        else if (opt == 4)
        {
            this->ui_afisare_elems();
        }

        else if (opt == 41)
        {
            this->ui_afisare_elems_tip();
        }

        else if (opt == 42)
        {
            this->ui_afisare_elems_maimare_suma();
        }

        else if (opt == 42)
        {
            this->ui_afisare_elems_suma_egala();
        }

        else if (opt == 43)
        {
            this->ui_afisare_elems_sold_zi();
        }

        else if (opt == 44)
        {
            this->ui_suma_totala_tip();
        }

        else if (opt == 45)
        {
            this->ui_max_out();
        }

        else if (opt == 5)
        {
            this->ui_filtru_in();
        }

        else if (opt == 51)
        {
            this->ui_filtru_in_suta();
        }

        else if (opt == 6)
        {
            this->ui_undo();
        }

        else if(opt == 0)
            stop = false;
        else
            cout<<"Optiune invalida. Reincercati. ";
    }

}



void UI::menu() {
    cout<<'\n';
    cout<<"1. Adaugare tranzactie / Insereaza tranzactie "<<'\n';
  //  cout<<"11. Insereaza tranzactie"<<'\n';

//    cout<<"21. Modificare tranzactie"<<'\n';
    cout<<"2. Modificare tranzactie"<<'\n';
//    cout<<"22. Modificare tranzactie (inlocuire suma)"<<'\n';
//
    cout<<"3. Stergere tranzactie zi"<<'\n';
    cout<<"31. Stergere tranzactie interval zi"<<'\n';
    cout<<"32. Stergere tranzactie tip"<<'\n';
//    cout<<"33. Stergere tranzactie"<<'\n';

    cout<<"4. Afisare toate tranzactiile"<<'\n';
    cout<<"41. Afisare toate tranzactiile pentru un tip"<<'\n';
    cout<<"42. Afisare toate tranzactiile cu o suma > 100"<<'\n';
    cout<<"43. Afisare sold zi"<<'\n';
    cout<<"44. Afisare suma in"<<'\n';
    cout<<"45. Afisare max out"<<'\n';

    cout<<"5. Filtru in"<<'\n';
    cout<<"51. Filtru in < 100"<<'\n';

    cout<<"6. Undo"<<'\n';
    cout<<"0. Exit"<<'\n';

}

void UI::ui_add_tranz1() {

    time_t now = time(0);
    tm *ltm = localtime(&now);

    int current_day = ltm->tm_mday;

    int ziua, suma;
    char* tip = new char[20];
    char* descriere = new char[20];
    cout<<"Ziua(0 = azi): ";
    cin>>ziua;
    cout<<"Suma: ";
    cin>>suma;
    cout<<"Tipul: ";
    cin.ignore();
    cin.getline(tip, 20);

    cout<<"Descrierea: ";
    cin.ignore();
    cin.getline(descriere, 20);

    if (ziua == 0) {
        ziua = current_day;
    }

    service.add_elem_service(ziua,suma,tip,descriere);
    cout<<"Tranzactie adaugata cu succes."<<endl;
}

//void UI::ui_add_tranz2() {
//
//    int ziua, suma;
//    char* tip = new char[20];
//    char* descriere = new char[20];
//    cout<<"Ziua: ";
//    cin>>ziua;
//    cout<<"Suma: ";
//    cin>>suma;
//    cout<<"Tipul: ";
//    cin.ignore();
//    cin.getline(tip, 20);
//    cout<<"Descrierea: ";
//    cin.ignore();
//    cin.getline(descriere, 20);
//
//    Tranzactie tr(ziua, suma, tip, descriere);
//    service.add_elem_service(ziua,suma,tip,descriere);
//    cout<<"Tranzactie adaugata cu succes."<<endl;
//}
//


void UI::ui_afisare_elems() {
    service.afisare_elemente_toate();

}

void UI::ui_stergere_tranz_zi() {

    int ziua;
    cout<<"Dati ziua tranzactiilor ce vor fi sterse: ";
    cin>>ziua;

    service.delete_elem_zi_service(ziua);
    cout<<"Tranzactii sterse cu succes."<<endl;
}

void UI::ui_stergere_tranz_interval_zi() {
    int ziua1, ziua2;
    cout<<"Dati intervalul de zile pentru care se vor sterge cheltuielile: "<<endl;

    cout<<"Ziua inceput: ";
    cin>>ziua1;
    cout<<"Ziua sfarsit: ";
    cin>>ziua2;

    service.delete_elem_interval_service(ziua1, ziua2);
    cout<<"Tranzactii sterse cu succes."<<endl;
}

void UI::ui_stergere_tranz_tip() {
    char* tip = new char[20];
    cout<<"Dati tipul tranzactiei care va fi stearsa: ";
    cin.ignore();
    cin.getline(tip, 20);
    service.delete_elem_tip_service(tip);
    cout<<"Tranzactii sterse cu succes."<<endl;
}

void UI::ui_modificare_tranzactie() {
    int ziua,suma;
    char* tip = new char[20];
    char* descriere = new char[20];
    cout<<"Dati ziua tranzactiei ce va fi modificate: ";
    cin>>ziua;

    cout<<"Dati suma tranzactiei ce va fi modificate: ";
    cin>>suma;

    cout<<"Dati tipul tranzactiei ce va fi modificate: ";
    cin.ignore();
    cin.getline(tip, 20);

    cout<<"Dati descrierea tranzactiei ce va fi modificate: ";
    cin.ignore();
    cin.getline(descriere, 20);

    Tranzactie t1(ziua, suma, tip,descriere);


    int ziua2,suma2;
    char* tip2 = new char[20];
    char* descriere2 = new char[20];
    cout<<"Dati noua zi: ";
    cin>>ziua2;

    cout<<"Dati noua suma: ";
    cin>>suma2;

    cout<<"Dati noul tip: ";
    cin.ignore();
    cin.getline(tip2, 20);

    cout<<"Dati noua descriere: ";
    cin.ignore();
    cin.getline(descriere2, 20);


    Tranzactie t2(ziua2, suma2, tip2,descriere2);

    service.update_elem_service(t1, t2);
    cout<<"Tranzactie modificata cu succes."<<endl;
}

//
//ex. înlocuire 12 in salar cu 2000 - se înlocuiește suma vechea tranzacției de tip
//        in din ziua 12 cu descrierea ”salar” cu suma 2000
//
//
//ziua tip descriere
//        inlocuire suma

void UI::ui_inlocuire_suma() {
    int ziua,suma;
    char* tip = new char[20];
    char* descriere = new char[20];
    cout<<"Dati ziua tranzactiei ce va fi modificate: ";
    cin>>ziua;

    cout<<"Dati tipul tranzactiei ce va fi modificate: ";
    cin.ignore();
    cin.getline(tip, 20);

    cout<<"Dati descrierea tranzactiei ce va fi modificate: ";
    cin.ignore();
    cin.getline(descriere, 20);

    cout<<"Dati noua suma: ";
    cin>>suma;

    service.pt_inloc_suma(ziua,suma,tip,descriere);

}



void UI::ui_modificare_tranzactie2() {
    int pos;
    cout << "Nr. de ordine a tranzactiei pentru actualizare:\n";
    cin >> pos;
    Tranzactie c;
    cin >> c;
    this->service.update_elem_service2(pos, c.get_ziua(), c.get_suma(), c.get_tip(), c.get_descriere());
}


//    Tranzactie* oldTr = service.get_repo().find_elem(t1);
//    if (oldTr == nullptr) {
//        cout<<"Nu exista o tranzactie cu ziua, tipul si descrierea specificate!"<<endl;
//        return;
//    }
//
//    Tranzactie newTr(ziua, suma, tip, descriere);
//    service.update_elem_service(*oldTr, newTr);
//    cout<<"Tranzactie actualizata cu succes!"<<endl;

void UI::ui_afisare_elems_tip() {
    char* tip = new char[20];
    cout<<"Dati tipul tranzactiei: ";
    cin.ignore();
    cin.getline(tip, 20);
    service.afisare_elems_tip_service(tip);
}

void UI::ui_afisare_elems_maimare_suma() {
    int suma;
    cout<<"Dati suma: ";
    cin>>suma;
    service.afisare_elems_maimare_suma_service(suma);
}

void UI::ui_afisare_elems_suma_egala() {
    int suma;
    cout<<"Dati suma: ";
    cin>>suma;
    service.afisare_elems_suma_egala_service(suma);
}

void UI::ui_afisare_elems_sold_zi() {
    int ziua;
    cout<<"Dati ziua: ";
    cin>>ziua;
    service.afisare_elems_sold_zi_service(ziua);
}

void UI::ui_suma_totala_tip() {
    char* tip = new char[20];
    cout<<"Dati tipul tranzactiei: ";
    cin.ignore();
    cin.getline(tip, 20);
    service.suma_totala_tip_service(tip);
}

void UI::ui_max_out() {
    int ziua;
    cout<<"Dati ziua: ";
    cin>>ziua;
    char* tip = new char[20];
    cout<<"Dati tipul tranzactiei: ";
    cin.ignore();
    cin.getline(tip, 20);
    service.afisare_max_out_service(ziua,tip);

}

void UI::ui_filtru_in() {
    char* tip = new char[20];
    cout<<"Dati tipul tranzactiei: ";
    cin.ignore();
    cin.getline(tip, 20);
    service.filtru_in_service(tip);
}

void UI::ui_filtru_in_suta() {
    char* tip = new char[20];
    int suma;
    cout<<"Dati tipul tranzactiei: ";
    cin.ignore();
    cin.getline(tip, 20);
    cout<<"Dati suma: ";
    cin>>suma;
    service.filtru_in_suta_service(tip, suma);
}

void UI::ui_undo() {
    bool success = service.undo();
    if (success) {
        cout << "Ultima operatie a fost anulata cu succes.\n";
    } else {
        cout << "Nu exista operatii de anulat.\n";
    }

}



