#include "testvalidator.h"
#include "valp.h"
#include "valpexc.h"
#include "produss.h"
#include <cassert>

 

void TestValidatorProdus::testValidatorProdus()
{
	ValidatorProdus val;
	Produs* p1 = new Produs(1,"ciocolata",2, 5);
	try
	{
		val.validate(p1);
	}
	catch (...)
	{
		assert(false);
	}
	Produs* p2 = new Produs(1,"",2, 5);
	try
	{
		val.validate(p2);
		assert(false);
	}
	catch (ValidationException& e) {}
	catch (...) {
		assert(false);
	}
	Produs* p3 = new Produs(1,"abc_",2, 5);
	try
	{
		val.validate(p3);
		assert(false);
	}
	catch (ValidationException& e) {}
	catch (...) {
		assert(false);
	}
	Produs* p4 = new Produs(1,"abc", -1,2);
	try
	{
		val.validate(p4);
		assert(false);
	}
	catch (ValidationException& e) {}
	catch (...) {
		assert(false);
	}

	delete p1;
	delete p2;
	delete p3;
	delete p4;

}


void TestValidatorProdus::testAll()
{
	this->testValidatorProdus();
	
}
