#pragma once
#include "rochie.h"
//#include "repofile.h"
//#include "validator.h"
//#include "exceptii.h"
//#include "service.h"
#include <assert.h>

class Teste {
private:
	void testdomain();
	void testrepo();
	void testservice();
	void testvalidator();
public:
	void run_all();
};
