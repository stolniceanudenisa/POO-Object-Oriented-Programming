#include <math.h>
#include <stdio.h>
#include <Windows.h>

struct VectorI {
	int x;
	int y;
};


void recursion(unsigned int a) {
	printf("A is % u, decrementing a", a);
	a--;
	recursion(a);
	
	if (a == 0)
		return;
}

void largeArrayStack() {
	const int sz = 1000000;
	double a[sz];
}

void largeArrayHeap() {
	const int sz = 1000000;
	double *a = new double[sz];
	printf("Allocated a");
	delete[] a;
}


int main() {
	system("color f4");
	int si = 10; 
	int sa[] = { 1, 2, 3, 4 }; 
	VectorI sStruct = { 7, 8 }; 
	char sc = '1'; 

	int *p = &si;
	int* hi = new int; 
	*hi = 10;
	int* ha = new int[5]; 
	ha[0] = 1;
	ha[1] = 2;
	ha[3] = 3;
	ha[4] = 4;


	VectorI* hStruct = new VectorI;
	hStruct->x = 7;
	hStruct->y = 8;

	delete hi;
	delete[] ha;
	delete hStruct;

	int *pi = &si;
	int *pa = sa + 2;

	int a = 10000;
	recursion(a);
	largeArrayStack();
	largeArrayHeap();
	return 0;
}