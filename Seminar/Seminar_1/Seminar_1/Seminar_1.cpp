// Seminar_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int maxim(int x, int y)
{
    if (x > y)
        return x;
    return y;
}

int maxop(int x, int y)
{
    return x > y ? x : y;

}

int main()
{
    int x,y;
    cout << "x=";
    cin >> x;
    cout << "y=";
    cin >> y;
    cout << maxim(x, y);
    return 0;
   
}
