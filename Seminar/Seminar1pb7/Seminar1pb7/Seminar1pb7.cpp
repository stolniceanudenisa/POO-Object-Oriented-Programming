// Seminar1pb7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "testeSirStatic.h"
#include "subalgSirStatic.cpp"

int main()
{
    test();
    int v[100], n,poz,neg,nule;
    citireSirStatic(v,n);
    rezolvareSirStatic(v, n, poz, neg, nule);
    afisareSirStatic(poz, neg, nule);
}

