#ifndef MYSORT_H_
#define MYSORT_H_

#include "electronice.h"
#include "electroniceService.h"
#include "Lista.h"
/*
   Tipul functie de comparare pentru 2 elemente
   returneaza 0 daca sunt egale, 1 daca o1>o2, -1 altfel
*/
typedef int(*FunctieComparare)(Tranzactie* e1, Tranzactie* e2);

/**
* Sorteaza in place
* cmpf - relatia dupa care se sorteaza
*/
void sort(Lista* l, FunctieComparare cmpF);

int cmpPret(Tranzactie* e1, Tranzactie* e2);

Lista* sortByPret(Lista* v);

void testSort();
#endif

