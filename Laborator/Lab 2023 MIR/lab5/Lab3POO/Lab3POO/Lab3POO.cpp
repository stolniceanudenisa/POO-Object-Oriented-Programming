// Lab3POO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "patrat.h"
#include "teste.h"
using namespace std;

int main()
{
    teste();
    Patrat my_square(5);
    cout << "Latura este: " << my_square.getLatura() << endl;
    cout << "Aria este: " << my_square.getArie() << endl;
    
    my_square.setLatura(7);
    cout << "Latura noua este: " << my_square.getLatura() << endl;
    cout << "Aria noua este: " << my_square.getArie() << endl;

    return 0;
}
