#include <iostream>
using namespace std;

int main()
{
	system("color f4");
	// empty statement, no effect
	;

	//    // if statement
	int a = 5;
	if (a == 5) {
		printf("The value of a is 5. We will modify it to 2\n");
		a = 2;
	}

	getchar();

	if (a == 5) {
		printf("The value of a is 5\n");
	}
	else if (a == 2)
	{
		printf("a has the value 2.\n");
	}
	else
	{
		printf("a is neither 2, nor 5.\n");
	}

	getchar();

	// switch statement


	switch (a) {
	case 1:
		cout << "A is 1";
		break;
	case 2:
		cout << "A is 2";
		break;
	case 3:
		cout << "A is 3";
		break;
	case 4:
		cout << "A is 4";
		break;
	case 5:
		cout << "A is 5";
		break;
	case 6:
		cout << "A is 6";
		//break;
	case 7:
		cout << "A is 7";
		break;
	default:
		cout << "A is not 1, 2, 3, 4, 5, 6 or 7";
	}
	cout << std::endl;
	getchar();

	// for statement
	// for loop increasing
	int idx = 0;
	int increment = 2;
	for (idx = 0; idx < 5; idx += increment) {
		printf("idx is increased by %d. Now idx is: %d.\n", increment, idx);
	}

	getchar();
	// for loop decreasing
	for (; idx > 0; idx -= increment) {
		printf("idx is decreased by %d. Now idx is: %d.\n", increment, idx);
	}


	a = 5;
	while (a < 5)
	{
		a++;
		printf("Increased a by 1. Now a is: %d.\n", a);
	}

	printf("\nInitialising a to 5.\n");
	a = 5;
	printf("Do-while loop: \n");
	// do-while loop
	do
	{
		a++;
		printf("Increased a by 1. Now a is: %d.\n", a);
	} while (a < 5);

	getchar();

	int nr = 1234;
	int val;
	for (val = 0; nr != 0; val += nr % 10, nr = nr / 10) {}

	cout << "Val is now ...?" << std::endl;
	getchar();

	cout << val << std::endl;
	getchar();

	return 0;
}
