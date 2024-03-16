#pragma once
#include "triunghi.h"
#include "utils.h"
#include<algorithm>

void addTriangle(Triunghi arr[], int& n) {
    int latura1, latura2, latura3;
    cout << "Introduceti laturile triunghiului (separate prin spatiu): ";
    cin >> latura1 >> latura2 >> latura3;
    Triunghi t(latura1, latura2, latura3);
    arr[n] = t;
    n++;
}

void afisareTriunghiuri(Triunghi* triunghiuri, int nrTriunghiuri) {
    for (int i = 0; i < nrTriunghiuri; i++) {
        cout << "Triunghi " << i + 1 << ": ";
        cout << triunghiuri[i] <<" "<< endl;
    }
    
   // delete[] triunghiuri;
}


int ceamaimareentitate(Triunghi* triunghiuri, int nrTriunghiuri)
{
    /*if (nrTriunghiuri == 0) {
        cout << "Nu exista triunghiuri in lista!" << endl;
        return 0;
    }*/

    int ceamaimarearie = triunghiuri[0].getArie();
    for (int i = 1; i < nrTriunghiuri; i++) {
        if (triunghiuri[i].getArie() > ceamaimarearie) {
            ceamaimarearie = triunghiuri[i].getArie();
        }
    }
    cout << "Cel mai mare triunghi are aria:" << ceamaimarearie << endl;
    return ceamaimarearie;
}



int celmaimailungsecventa(Triunghi* triunghiuri, int nrTriunghiuri, Triunghi aux[])
{
    //if (nrTriunghiuri == 0) {
    //    cout << "Nu exista triunghiuri in lista!" << endl;
    //    return;
    //}

    int lungimeSecventa = 1;
    int inceputSecventa = 0;
    int lungimeMaxima = 1;
    int inceputMaxim = 0;

    for (int i = 1; i < nrTriunghiuri; i++) {
        if (triunghiuri[i].getArie() == triunghiuri[i - 1].getArie()) {
            lungimeSecventa++;
        }
        else {
            if (lungimeSecventa > lungimeMaxima) {
                lungimeMaxima = lungimeSecventa;
                inceputMaxim = inceputSecventa;
            }
            lungimeSecventa = 1;
            inceputSecventa = i;
        }
    }

    if (lungimeSecventa > lungimeMaxima) {
        lungimeMaxima = lungimeSecventa;
        inceputMaxim = inceputSecventa;
    }

    //if (lungimeMaxima == 1) {
    //    cout << "Nu exista o secventa de triunghiuri egale in lista!" << endl;
    //    return;
    //}

    //cout << "Cea mai lunga secvente de triunghiuri egale este:" << endl;

    //for (int i = inceputMaxim; i < inceputMaxim + lungimeMaxima; i++) {
    //    cout << triunghiuri[i] << endl;
    //}
    int j;
    j = 0;
    for (int i = inceputMaxim; i <= inceputMaxim + lungimeMaxima; i++)
    {
        aux[j] = triunghiuri[i];
        j++;
    }
    return lungimeMaxima;
}




//void entitatiCadran1(Triunghi* triunghiuri, int nrTriunghiuri)
//{
//
//    for (int i = 0; i < nrTriunghiuri; i++) {
//        int x1 = triunghiuri[i].getLatura1().getX();
//        int y1 = triunghiuri[i].getLatura2().getY();
//        int x2 = triunghiuri[i].getLatura3().getX();
//        int y2 = triunghiuri[i].getLatura1().getY();
//        int x3 = triunghiuri[i].getLatura2().getX();
//        int y3 = triunghiuri[i].getLatura3().getY();
//
//        if (x1 > 0 && x2 > 0 && x3 > 0 && y1 > 0 && y2 > 0 && y3 > 0) {
//            cout << "Triunghiul " << i + 1 << " este situat complet in cadranul 1." << endl;
//        }
//    }
//}





//
//void  ceamaimareentitate(Triunghi* triunghiuri, int nrTriunghiuri)
//{
//    if (nrTriunghiuri == 0) {
//        cout << "Nu exista triunghiuri in lista!" << endl;
//        //break;
//    }
//
//    Triunghi ceamaimareentitate = triunghiuri[0];
//    for (int i = 1; i < nrTriunghiuri; i++) {
//        if (triunghiuri[i].getArie() > ceamaimareentitate.getArie()) {
//            ceamaimareentitate = triunghiuri[i];
//        }
//    }
//    cout << "Cel mai mare triunghi este: " << ceamaimareentitate <<"iar aria sa este:"<< ceamaimareentitate.getArie() <<endl;
//    //break;
//}

//





//int celmaimailungsecventa(Triunghi* triunghiuri, int nrTriunghiuri) {
//    if (nrTriunghiuri == 0) {
//        cout << "Nu exista triunghiuri in lista!" << endl;
//        return 0;
//    }
//
//    // sortam lista de entitati bazata pe arie
//    sort(triunghiuri, triunghiuri + nrTriunghiuri, [](Triunghi& a, Triunghi& b) {
//        return a.getArie() < b.getArie();
//        });
//
//    int lungimeMaxima = 1;
//    int lungimeCurenta = 1;
//
//    for (int i = 1; i < nrTriunghiuri; i++) {
//        if (triunghiuri[i].getArie() == triunghiuri[i - 1].getArie()) {
//            lungimeCurenta++;
//            if (lungimeCurenta > lungimeMaxima) {
//                lungimeMaxima = lungimeCurenta;
//            }
//        }
//        else {
//            lungimeCurenta = 1;
//        }
//    }
//
//    cout << "Lungimea celei mai lungi secvente de triunghiuri egale ca arie este: " << lungimeMaxima << endl;
//    return lungimeMaxima;
//}
//
//
