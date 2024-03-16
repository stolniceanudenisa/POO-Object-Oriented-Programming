// bonus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <assert.h>
using namespace std;

int inmultire(int a, int b)
{
    int rez = 0;
    while (b > 0)
    {
        if (b % 2 == 1) // daca b impar
        {
            rez = rez + a;
        }
        a = a * 2; 
        b = b / 2;

    }
    return rez;
}


void test()
{
    assert(inmultire(0, 5) == 0); // inmultirea cu 0 a unui numar este 0
    assert(inmultire(14, 0) == 0);
    assert(inmultire(3, 4) == 12);
}


int main()
{
    test();
    int a, b;
    cout << "Dati valoarea a=";
    cin >> a;
    cout << "Dati valoarea b=";
    cin >> b;
    cout << inmultire(a, b);
    return 0;
}
