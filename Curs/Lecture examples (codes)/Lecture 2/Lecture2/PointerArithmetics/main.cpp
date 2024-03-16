#include<stdio.h>
#include <Windows.h>

int main()
{
	system("color f4");
	int i = 12, *ip = &i;
	double d = 2.3, *dp = &d;
	char ch = 'a', *cp = &ch;

	printf("Size of ip %d \n", sizeof(ip));
	printf("Size of dp %d \n", sizeof(dp));
	printf("Size of cp %d \n", sizeof(cp));

	printf("Value of ip = %p\n", ip);
	printf("Value of dp = %p\n", dp);
	printf("Value of cp = %p\n\n", cp);

	printf("Value of ip + 1 = %p\n", ip + 1);
	printf("Value of dp + 1 = %p\n", dp + 1);
	printf("Value of cp + 1 = %p\n\n", cp + 1);

	printf("Value of ip + 2 = %p\n", ip + 2);
	printf("Value of dp + 2 = %p\n", dp + 2);
	printf("Value of cp + 2 = %p\n", cp + 2);

	char sir[] = "Hello world!";
	char *p1, *p2;
	p1 = sir;
	p2 = sir + 2;
	printf("Value stored at p1 %c , value stored at p2 %c \n", *p1, *p2);
	p2++;
	printf("Value stored at p1 %c , value stored at p2 %c \n", *p1, *p2);
	printf("p2 - p1 = %d, p1 - p2 = %d ", p2 - p1, p1 - p2);

	return 0;
}
