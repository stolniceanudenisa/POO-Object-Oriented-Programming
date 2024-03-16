///*
//Fiind dat un număr natural n, să se determine produsul factorilor proprii ai lui n
//*/
//
//// 6   1 2 3 6 
//// 8   1 2 4 8 
//
//#include <iostream>
//#include <assert.h>
//#include <cmath>
//using namespace std;
//
//int produs(int n) {
//    int produs = 1;
//
//    for (int i = 2; i <= n-1; i++) {
//        if (n % i == 0) {
//            produs *= i;
//        }
//    }
//
//    if (sqrt(n) == floor(sqrt(n))) {
//        produs /= sqrt(n);
//    }
//
//    return produs;
//}
//
//void test() {
//    assert(produs(1) == 1);
//    assert(produs(2) == 1);
//    assert(produs(12) == 144);
//}
//
//int main() {
//    int n;
//    cout << "n=";
//    cin >> n;
//
//
//    cout << "produsul factorilor proprii ai lui n " << n << " este " << produs(n) << endl;
//
//    return 0;
//}
