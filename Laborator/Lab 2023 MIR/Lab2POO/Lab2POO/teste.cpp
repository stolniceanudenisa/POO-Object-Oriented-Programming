#include "teste.h"
#include "functii.h"
#include <assert.h>

void test_secv_nr_distincte()
{
	int sir1[6] = { 1, 2, 3, 4, 2, 5 };
	int sir2[8] = { 1, 2, 3, 4, 5, 6, 2, 3 };
	int sir3[6] = { 1, 2, 2, 2, 1, 3 };
	int aux[100];
	assert(secv_nr_distincte(sir1, 6, aux) == 4);
	assert(secv_nr_distincte(sir2, 8, aux) == 6);
	assert(secv_nr_distincte(sir3, 6, aux) == 3);
}

void test_secv_semne_ctr()
{
	int sir1[6] = { 1, -2, 3, -4, 2, 5 };
	int sir2[8] = { -1, -2, -3, 4, 5, 6, 2, 3 };
	int sir3[6] = { 1, 2, 2, 2, 1, 3 };
	int aux[100];
	assert(secv_semne_ctr(sir1, 6, aux) == 5);
	assert(secv_semne_ctr(sir2, 8, aux) == 2);
	assert(secv_semne_ctr(sir3, 6, aux) == 1);
}

void test_secv_3_val_dist()
{
	int n = 5;
	int* v = new int[50] {1, 1, 2, 2, 3, 5, 6, 7, 8};
	int sir1[9] = { 1, 1, 2, 2, 3, 5, 6, 7, 8 };
	int aux[100];
	assert(secv_3_val_dist(v, 9, aux) == 5);
	delete[] v;

}

void test_secv_cif_comune()  
{
	int* v = new int[50] {11234, 345, 777};
	int sir1[3] = { 11234, 345, 777 };
	int aux[100];
	assert(secv_cif_comune(v, 3, aux) == 2);
	delete[] v;
	v = NULL;
}





