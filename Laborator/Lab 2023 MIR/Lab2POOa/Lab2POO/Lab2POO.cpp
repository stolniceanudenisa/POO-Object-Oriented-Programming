// Lab2POO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


/*
Să se implementeze o aplicație bazată pe un meniu consolă (1p) care să permită următoarele
funcționalități:
 citirea unei liste de numere întregi de la tastatură (1p) - LIVE
 afișarea unei liste de numere întregi. (1p) - LIVE
 afișarea pe consolă a celei mai lungi secvențe care respectă o anumită proprietate
(fiecare student va primi 2 astfel de proprietăți) - TEMĂ (4p + 2p pt teste)
 Închiderea aplicației (1p) - LIVE.

*/

#include <iostream>
#include "console.h"
#include "teste.h"
using namespace std;

int main()
{
  
    int cont = 0;
    test_secv_nr_distincte();
    Console();
    return 0;
} 



// 4,8


// 2 3 4 6 1 2 3
// 
// 
// 
// 
// 1 2 3 4 1 2 2
// 1 2 3 3 4 5 6 7
//1 1 - 2 3 - 4 2 1 9
