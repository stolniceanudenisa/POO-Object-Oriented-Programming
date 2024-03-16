#pragma once

 

#include <vector>
#include "produs.h"
using namespace std;

class TestRepo {
private:
	vector<Produs*> produse;
	void testGetAll();
	void testGetSize();
	void testGet();
	void testFind();
	void testAddProdus();
	void testUpdateProdus();
	void testDeleteProdus();
public:
	TestRepo();
	~TestRepo();
	void testAll();
};