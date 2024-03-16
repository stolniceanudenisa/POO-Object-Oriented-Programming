//#include <iostream>
//#include <assert.h>
//
//using namespace std;
//
//int inmultire(int a, int b) 
//{
//    int rez = 0;
//    while (b > 0) 
//    {
//        if (b % 2 == 1) {
//            rez += a;
//        }
//        a *= 2;
//        b /= 2;
//    }
//    return rez;
//}
//
//
//void test() {
//    // Test case 1: multiplication of 0 with any number should equal 0
//    assert(inmultire(0, 5) == 0);
//    assert(inmultire(5, 0) == 0);
//
//    // Test case 2: multiplication of two positive integers
//    assert(inmultire(3, 4) == 12);
//    assert(inmultire(7, 9) == 63);
//
//    // Test case 3: multiplication of two large positive integers
//    assert(inmultire(10000, 9999) == 99990000);
//
//    // Test case 4: multiplication of a positive integer with 1 should equal the integer itself
//    assert(inmultire(5, 1) == 5);
//    assert(inmultire(1, 8) == 8);
//}
//
//
//
//int main() 
//{
//    test();
//    int a, b;
//    cout << "a=";
//    cin >> a;
//    cout << "b=";
//    cin >> b;
//    cout << inmultire(a, b);
//    return 0;
//}
