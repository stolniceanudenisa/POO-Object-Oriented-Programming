#include "algoritmh.h"
#include <assert.h>

void test()
{
	int n = 20, p1 = 0, p2 = 0;
	factoriprimi(n, p1, p2);
	assert(p1 == 3);
	assert(p2 == 17);

	n = 25;
	factoriprimi(n, p1, p2);
	assert(p1 == 2);
	assert(p2 == 23);

	n = 2;
	factoriprimi(n, p1, p2);
	assert(p1 == 0);
	assert(p2 == 0);

}