//
// Created by 40766 on 05.05.2023.
//
#include "UI.h"
#include <iostream>


using namespace std;

UI::UI(Service& ctrl) : ctrl(ctrl)
{
}

UI::~UI()
{
}

void UI::runMenu()
{
    string optiune;
    bool optiuneCorecta;
    while (true)
    {
        this->displayMenu();
        optiuneCorecta = false;
        getline(cin, optiune);
        if (optiune == "1")
        {
            optiuneCorecta = true;
            this->addProdus();
        }
        if (optiune == "a")
        {
            optiuneCorecta = true;
            this->showAll(this->ctrl.getAll());
        }
        if (optiune == "x")
        {
            break;
        }
        if (!optiuneCorecta)
        {
            cout << "Optiune gresita! Reincercati\n";
        }
    }
}

void UI::displayMenu()
{
    cout << "1. Adauga Produs\n";
    //cout << "2. Adauga PS\n";
//    cout << "3. Updateaza PD\n";
//    cout << "4. Updateaza PS\n";
    //cout << "5. Sterge produs\n";
//    cout << "6. Filtrare dupa pret min/max\n";
//    cout << "7. Sorteaza dupa nume\n";
    cout << "a. Afiseaza toate produsele\n";
    cout << "x. Iesire\n";
}

void UI::showAll(vector<Produs*> produse)
{

//    for (const auto& produs : produse) {
//        cout << produs->toString() << endl;
//    }
}
//    for (int i = 0; i < produse.size(); i++)
//    {
//       // cout << produse[i]->write() << '\n';
//    }
//}

void UI::addProdus()
{
//    string buffer, nume, glazura;
//    int pret,cod;
//    cout << "Dati codul: ";
//    getline(cin, buffer);
//    cod = stoi(buffer);
//
//    cout << "Dati numele: ";
//    getline(cin, nume);
//
//    cout << "Dati pretul: ";
//    getline(cin, buffer);
//    pret = stoi(buffer);
//
//
//    int cod;
//    string denumire;
//    double pret;
//
//    cout << "Introduceti codul produsului: ";
//    cin >> cod;
//    cin.ignore(); // ignore newline character left in the input stream
//
//    cout << "Introduceti denumirea produsului: ";
//    getline(cin, denumire);
//
//    cout << "Introduceti pretul produsului: ";
//    cin >> pret;
//    this->ctrl.addProdus(cod, denumire, pret);

}

//void UI::addProdusSarat()
//{
//
//    string buffer, nume, glazura;
//    int pret,cod;
//    cout << "Dati codul: ";
//    getline(cin, buffer);
//    cod = stoi(buffer);
//
//    cout << "Dati numele: ";
//    getline(cin, nume);
//
//    cout << "Dati pretul: ";
//    getline(cin, buffer);
//    pret = stoi(buffer);
//
//
//    this->ctrl.addProdusSarat(cod, nume, pret);

    //----------
//    try {
//        this->ctrl.addProdusSarat(cod, nume, pret);
//    }
//    catch (ValidationException& ve)
//    {
//        cout << ve.what() << endl;
//    }
//    string buffer, nume;
//    int pret, cantitateSare;
//    cout << "Dati numele: ";
//    getline(cin, nume);
//    cout << "Dati pretul: ";
//    getline(cin, buffer);
//    pret = stoi(buffer);
//    cout << "Dati cantitatea de sare: ";
//    getline(cin, buffer);
//    cantitateSare = stoi(buffer);
//
//    try {
//        this->ctrl.addProdusSarat(nume, pret, cantitateSare);
//    }
//    catch (ValidationException& ve)
//    {
//        cout << ve.what() << endl;
//    }
//}


