///*
//Fiind dat un număr natural n, să se determinecel mai mare număr natural m format din
//aceleași cifre cu n.De ex.pentru n = 3658, m = 8653*/
//
//
//#include <iostream>
//#include <assert.h>
//using namespace std;
//
//
//int ap[100];
//
//int aparitie(int n)
//{
//    int nr = 0, c = 0;
//    while (n != 0)
//    {
//        c = n % 10;
//        ap[c]++;
//        n /= 10;
//    }
//    for (int i = 9; i>=0; i--)
//    {// 1832323  1223338
//        while (ap[i] != 0)
//        {
//
//            nr = nr * 10 + i;
//            ap[i]--;
//        }
//        /*      nr = nr + i * p;
//              p = p * 10;
//              ap[i]--;*/
//              ///cout << i;
//    }
//    return nr;
//}
//
//void test()
//{
//    assert(aparitie(1234) == 4321);
//    assert(aparitie(128831912) == 111223889);
//   
//}
//
//
//
//int main()
//{
//    test();
//
//    int n;
//    cout << "n=";
//    cin >> n;
//    cout << aparitie(n);
//
//    return 0;
//}
//
//
