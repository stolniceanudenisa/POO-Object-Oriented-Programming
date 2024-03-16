#include <iostream>

using namespace std;

int main()
{
    system("color f4");
    int x = 10;
    int* p1 = &x;
    int* p2;
    p2 = &x;

    printf("The pointer p1 is stored at the memory address %p; size of p1 %zu \n", &p1, sizeof(p1));
    printf("The pointer p2 is stored at the memory address %p; size of p2 %zu \n", &p2, sizeof(p2));

    printf("The pointer p1 points to the memory address %p \n", p1);
    printf("The pointer p2 points to the memory address %p \n", p2);

    printf("The value of x is %d \n", x);
    printf("The value of x accessed throught pointer p1 is %d\n", *p1);
    printf("The value of x accessed throught pointer p2 is %d\n", *p2);

    printf("Now we set x to 20\n");
    x = 20;
    getchar();
    printf("The value of x accessed throught pointer p1 is %d\n", *p1);
    printf("The value of x accessed throught pointer p2 is %d\n", *p2);

    printf("Now we increment the value of x through the pointer p1\n");
    *p1 = *p1 + 1;
    printf("The value of x accessed throught pointer p1 is %d\n", *p1);
    printf("The value of x accessed throught pointer p2 is %d\n", *p2);

    getchar();
    printf("Now we increment the pointer p1\n");
    printf("Before the increment operation, the pointer p1 points to the memory address %p \n", p1);
    p1 = p1 + 1;
    printf("The pointer p1 points to the memory address %p \n", p1);
    printf("The value stored at memory location p1 is %d \n", *p1);

    getchar();
    printf("Let's try with a pointer to double \n");
    double dVal = 3.14;
    double* dp = &dVal;
    printf("Before the increment operation, the pointer p1 points to the memory address %p \n", dp);
    printf("The value stored at memory location dp is %f \n", *dp);
    dp = dp + 1;
    printf("The pointer p1 points to the memory address %p \n", dp);

    return 0;
}
