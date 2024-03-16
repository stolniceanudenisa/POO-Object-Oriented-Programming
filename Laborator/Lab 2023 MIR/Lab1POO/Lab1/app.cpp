#include <iostream>
#include <assert.h>
#include "teste.h"
#include "algoritmh.h"
using namespace std;


int main()
{
	test();
	int n, p1, p2;
	cout << "n=";
	cin >> n;
	factoriprimi(n, p1, p2);
	cout << p1 << "+" << p2 << endl;
	cout << p2 << "+" << p1 << endl;
	
	return 0;
}