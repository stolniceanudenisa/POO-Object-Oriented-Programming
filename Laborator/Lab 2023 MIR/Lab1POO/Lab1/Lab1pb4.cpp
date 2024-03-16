///*
//Fiind dat un număr natural n, să se determine cel mai mare număr prim mai mic decât
//n. Dacă nu există un astfel de număr, se va afișa un mesaj.
//*/
//
//// lab1.cpp : this file contains the 'main' function. program execution begins and ends there.
//
//
//#include <iostream>
//#include <assert.h>
//#include <string>
//#include <cstring>
//
//using namespace std;
//
//// functie care verifica daca un numar este prim
//int prim(int x)
//{
//    if (x < 2 || x>2 && x % 2 == 0)
//        return 0;
//    for (int d = 2; d * d <= x; d++)
//        if (x % d == 0)
//            return 0;
//    return 1;
//}
//
////int celmaimareprimmaimic(int x)
////{
////    int y = x - 1;
////    
////    while (prim(y) == 0)
////        y--;
////   
////     return y;
////}
//
//string celmaimareprimmaimic(int n)
//{
//    for (int i = n - 1; i >= 2; i--)
//    {
//        if (prim(i)) {
//            return to_string(i);
//        }
//    }
//    return "Nu s-a gasit numarul.";
//}
//
//void test()
//{
//    assert(strcmp(celmaimareprimmaimic(10).c_str(), "7") == 0);
//    assert(strcmp(celmaimareprimmaimic(20).c_str(), "19") == 0);
//    assert(strcmp(celmaimareprimmaimic(5).c_str(), "3") == 0);
//    assert(strcmp(celmaimareprimmaimic(40).c_str(), "37") == 0);
//    assert(strcmp(celmaimareprimmaimic(2).c_str(), "Nu s-a gasit numarul.") == 0);
//    assert(strcmp(celmaimareprimmaimic(999999).c_str(), "999983") == 0);
//
//}
//
//
//int main()
//{
//    test();
//    int n;
//    cout << "n=";
//    cin >> n;
//    cout << celmaimareprimmaimic(n);
//
//    return 0;
//}
//
//
//// ctrl alt l
///*
//fiind dat un număr natural n,
//să se determine numerele naturale prime p1 și p2 astfel încât n = p1 + p2.
//*/