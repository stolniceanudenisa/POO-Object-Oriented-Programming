#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <iostream>

typedef double (*operation)(double, double);

typedef struct
{
	double arr[10];
	int length;

} vector;



double operationOnVector(vector v, double(*o)(double, double))
{
	if (v.length == 0)
		return 0;
	double result = v.arr[0];
	for (int i = 1; i < v.length; i++)
		result = o(result, v.arr[i]);		// call the function through a pointer
	return result;
}

double sum(double a, double b)
{
	return a + b;
}

double product(double a, double b)
{
	return a * b;
}

vector readNumbers()
{
	vector res;
	res.length = 0;

	printf("Enter several numbers. When entering '0', the reading will stop.\n");

	double n = -1;
	while (n != 0)
	{
		printf("Enter number: ");
		scanf("%lf", &n);
		if (n != 0)
			res.arr[res.length++] = n;
	}
	return res;
}

int double_compare(const void* first, const void* second) {
	double first_elem = *(static_cast<const double*>(first));
	double second_elem = *(const double*)second;
	/*if (first_elem < second_elem)
		return -1;
	if (first_elem == second_elem)
		return 0;
	return 1;*/
	return second_elem > first_elem;

}

int main()
{
	system("color f4");

	//  read vector
	vector v = readNumbers();

	// read operation
	char op = '+'; // by default, we compute the sum
	printf("Input '+' for addition, or '*' for multiplication: ");
	scanf(" %c", &op);

	double (*o)(double, double) = NULL;
	if (op == '+')
		o = &sum;
	else if (op == '*')
		o = &product;
	else {
		printf("Unknown operation %c ", op);
		exit(-2);
	}
	//operation o = (op == '+') ? &sum : &product;

	double p = operationOnVector(v, o);
	printf("The result is: %.2lf.\n", p);

	qsort(v.arr, v.length, sizeof(v.arr[0]), double_compare);
	for (int i = 0; i < v.length; i++) {
		printf("%f ", v.arr[i]);
	}
	system("pause");

	return 0;
}

