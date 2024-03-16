///*
//Fiind dat un număr natural n, să se determine primele două numere prime gemene mai
//mari decât n. Două numere prime p și q sunt gemene dacă q - p = 2.
//*/
//
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
//
//void gemene(int n, int &p, int &q)
//{
//    // 4 5 7      6 7 8        6 11 13
//    p = n + 1;
//
//    while(!prim(p) || !prim(p + 2))
//    {
//        p++;
//    }
//    q = p + 2;
//    if (!prim(q))
//        q++;    
//}
//
//
//void test()
//{
//    int p, q;
//  
//    gemene(10, p, q);
//    assert(p == 11);
//    assert(q == 13);
//
//    gemene(100, p, q);
//    assert(p == 101);
//    assert(q == 103);
//
//    gemene(6, p, q);
//    assert(p == 11);
//    assert(q == 13);
//
//}
//
//
//int main()
//{
//    test();
//    int n, p, q;
//    cout << "n=";
//    cin >> n;
//    gemene(n, p, q);
//    cout << p << " " << q;
//    return 0;
//}
