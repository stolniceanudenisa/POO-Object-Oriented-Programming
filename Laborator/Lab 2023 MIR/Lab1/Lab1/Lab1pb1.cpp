//// lab1.cpp : this file contains the 'main' function. program execution begins and ends there.
//
//
//#include <iostream>
//#include <assert.h>
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
////n=5
////p1=3, p2=2
//
//int factoriprimi(int n, int& p1, int& p2)
//{
//    p1 = p2 = 0;
//    for (int i = 2; i <= n / 2; i++)
//    {
//        if (prim(i) && prim(n - i))
//        {
//            p1 = i;
//            p2 = n - i;
//            return 1; // return 1 daca sunt gasiti 2 factori primi
//        }
//    }
//    return 0; // return 0 daca nu sunt gasiti 2 factori primi
//}
//
////void factoriprimivoid(int n, int &p1, int &p2)
////{
////    p1 = p2 = 0;
////    for (int i = 2; i <= n / 2; i++)
////    {
////        if (prim(i) && prim(n - i))
////        {
////            p1 = i;
////            p2 = n - i;
////            return; 
////        }
////    }
////}
//
//void test()
//{
//    int n = 20, p1 = 0, p2 = 0;
//    assert(factoriprimi(n, p1, p2) == 1);
//    assert(p1 == 3);
//    assert(p2 == 17);
//
//    n = 25;
//    assert(factoriprimi(n, p1, p2) == 1);
//    assert(p1 == 2);
//    assert(p2 == 23);
//
//    n = 30;
//    assert(factoriprimi(n, p1, p2) == 1);
//    assert(p1 == 7);
//    assert(p2 == 23);
//
//    n = 2;
//    assert(factoriprimi(n, p1, p2) == 0);
//    assert(p1 == 0);
//    assert(p2 == 0);
//
//}
//
//
//int main()
//{
//    test();
//    int n,p1,p2;
//    cout << "n=";
//    cin >> n;
//    factoriprimi(n,p1,p2);
//    if (p1 == 0 && p2 == 0)
//        cout << "nu se poate descompune!";
//    else
//    {
//        cout << p1 << "+" << p2 << endl;
//        cout << p2 << "+" << p1 << endl;
//    }
//    return 0;
//}
//
//
//// ctrl alt l
///*
//fiind dat un număr natural n, 
//să se determine numerele naturale prime p1 și p2 astfel încât n = p1 + p2.
//*/