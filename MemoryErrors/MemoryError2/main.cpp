#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <windows.h>
#include <iostream>
//#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

int main() {
	int sz = 10;
	long long* arr = (long long*)malloc(sizeof(arr) * sz);
	int count_event = 0;
	int count_odd = 0;
	for (int i = 0; i < sz; i++) {
		arr[i] = rand();
		if (!(arr[i] % 2))
			count_event += 1;
		else
			count_odd += 1;
	}

	printf("Randomly generated %d even number and %d odd numbers \n", count_event, count_odd);
	long long* arr_half = arr + sz / 2;
	
	printf("The second half of the array is: %d \n");
	for (int i = 0; i < sz / 2; i++) {
		printf("%llu ", arr_half[i]);
	}
	printf("\n");

	free(arr_half);
	free(arr);

	std::cout << _CrtDumpMemoryLeaks() << std::endl;

	return 0;
}