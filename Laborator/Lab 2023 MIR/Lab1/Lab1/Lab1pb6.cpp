/////*
////Fiind dat un număr natural n, să se determine cel mai mic număr m din șirul Fibonacci
////(definiti prin f[0]=f[1]=1, f[n]=f[n1]+f[n-2], pentru n>2) mai mare decât n.
////*/
////
////// 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144,
////
////
//#include <iostream>
//#include <assert.h>
//using namespace std;
//
//
//#include <iostream>
//using namespace std;
//
//int fibo(int n) 
//{
//    int fib1 = 1, fib2 = 1, fib3;
//    do {
//        fib3 = fib1 + fib2;
//        fib1 = fib2;
//        fib2 = fib3;
//    } while (fib3 <= n);
//    return fib3;
//}
//
//void test_fibo() {
//    assert(fibo(1) == 2);
//    assert(fibo(5) == 8);
//    assert(fibo(13) == 21);
//    assert(fibo(50) == 55);
//}
//
//
//
//int main() 
//{
//
//    test_fibo;
//    int n;
//    cout << "n=";
//    cin >> n;
//
//    cout << fibo(n) << endl;
//
//    return 0;
//}
