#include "testeSirStatic.h"
#include "subalgSirStatic.h"
#include <assert.h>

void test()
{
	int v[] = {1, -4, 0, -5, 0, -8};
	int poz, neg, nule;

	rezolvareSirStatic(v, 6, poz, neg, nule);
	assert(poz == 1);
	assert(neg == 3);
	assert(nule == 2);

}
