//#include <iostream>
//#include <assert.h>
//using namespace std;
//
//
//// subalgoritm pentru verificarea numarului prim
//int prim(int x)
//{
//	if (x < 2 || x>2 && x % 2 == 0)
//		return 0;
//	for (int d = 2; d * d <= x; d++)
//		if (x % d == 0)
//			return 0;
//	return 1;
//}
//
//// n=p1+p2;
//// p2= n-p1;
//
//
//void factoriprimi(int n, int &p1, int &p2)
//{
//    p1 = p2 = 0;
//    for (int i = 2; i <= n / 2; i++)
//    {
//        if (prim(i) && prim(n - i))
//        {
//            p1 = i;
//            p2 = n - i;
//            return; 
//        }
//    }
//}
//
//void test()
//{
//	int n = 20, p1 = 0, p2 = 0;
//	factoriprimi(n, p1, p2);
//	assert(p1 == 3);
//	assert(p2 == 17);
//
//	n = 25;
//	factoriprimi(n, p1, p2);
//	assert(p1 == 2);
//	assert(p2 == 23);
//
//	n = 2;
//	factoriprimi(n, p1, p2);
//	assert(p1 == 0);
//	assert(p2 == 0);
//
//}
//
//int main()
//{
//	test();
//	int n, p1, p2;
//	cout << "n=";
//	cin >> n;
//	factoriprimi(n, p1, p2);
//	if (p1 == 0 && p2 == 0)
//		cout << "nu se poate descompune!";
//	else
//	{
//		cout << p1 << "+" << p2 << endl;
//		cout << p2 << "+" << p1 << endl;
//	}
//	return 0;
//}