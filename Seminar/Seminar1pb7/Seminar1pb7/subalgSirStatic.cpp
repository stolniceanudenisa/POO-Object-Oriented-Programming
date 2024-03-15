#include "subalgSirStatic.h"
#include <iostream>

using namespace std;

void citireSirStatic(int v[100], int& n)
{
	cout << "n=";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "v[" << i << "]=";
		cin >> v[i];
	}

}

void rezolvareSirStatic(int v[100], int n, int& pozi, int& neg, int& nule)
{
	pozi = neg = nule = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] > 0)
		{
			pozi++;
			continue;
		}
		if (v[i] < 0)
		{
			neg++;
			continue;
		}
		nule++;	
	}
}

void afisareSirStatic(int poz, int neg, int nule)
{
	cout << "avem" << poz << " numere pozitive"<<"\n";
	cout << "avem" << neg << " numere negative"<<"\n";
	cout << "avem" << nule << " numere nule";
}
