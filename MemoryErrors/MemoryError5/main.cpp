
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void func1() {
	int* a = (int*)malloc(sizeof(int) * 4);
	int* b = (int*)malloc(sizeof(int) * 4);

	for (int i = 0; i < 4; i++)
		a[i] = i;

	for (int i = 0; i < 4; i++)
		b[i] = i + 2;

	for (int i = 0; i < 4; i++)
		if (a[i] % 2)
			*(a + i) = *(b + i);
	a = b;

	for (int i = 0; i < 4; i++)
		printf("\ta[%d]=%d, b[%d]=%d\n", i, a[i], i, b[i]);

	if (a != NULL)
		free(a);
	if (b != NULL)
		free(b);
}

void func2() {
	int* p = new int;
	*p = 10;
	int* q = new int[1];
	*q = 2;

	int max = -1;
	if (p > q)
		max = *p;
	else
		max = *q;

	printf("The max between %d and %d is %d \n", *p, q[0], max);
	delete p;
	delete q;
}

void func3() {
	char* greeting = new char[50];
	strcpy(greeting, "hello");

	char aux[100];
	
	printf("Enter your name: ");
	scanf("%s", aux);

	char* name = aux;
	printf("Enter your city: ");
	scanf("%s", &aux);
	char* city = aux;

	printf("%s, %s from %s! ", greeting, aux, city);

	delete[] greeting;
	delete[] name;
	delete[] city;
}

int main() {
	func1();
	func2();
	func3();
	return 0;
}