///*
//Fiind dat un număr natural n, să se determine palindromul lui n.
//*/
//#include <iostream>
//using namespace std;
//
//int invers(int n)
//{
//	int inv = 0;
//	while (n!=0)
//	{
//		inv = inv * 10 + n % 10;
//		n = n / 10;
//	}
//	return inv;
//}
//
//int palindrom(int num) {
//	int rev = invers(num);
//	return (num == rev);
//}
//
//int main()
//{
//	int n;
//	cout << "n=";
//	cin >> n;
//	if (palindrom(n))
//		cout << n << " is a palindrome";
//	else
//		cout << n << " is not a palindrome";
//}