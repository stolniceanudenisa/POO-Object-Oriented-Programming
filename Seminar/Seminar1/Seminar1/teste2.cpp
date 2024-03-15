#include "teste2.h"
#include "subalg2.h"
#include "assert.h"

void testPrim()
{
	assert(prim(1) == 0);
	assert(prim(2) == 1);
	assert(prim(7) == 1);
	assert(prim(12) == 0);
}

void testPrimulPrim()
{
	assert(primulPrim(2) == 3);
	assert(primulPrim(11) == 13);
	assert(primulPrim(9) == 11);

}

void testAll()
{
	testPrim();
	testPrimulPrim();
}
