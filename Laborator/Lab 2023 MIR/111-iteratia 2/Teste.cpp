#include "Student.h"
#include <assert.h>
#include "Teste.h"
#include "Repo.h"

void testStudent()
{
	Student s1;
	assert(strcmp(s1.getNume(), "") == 0);
	assert(s1.getVarsta() == 0);

	Student s2("ana", 20);
	assert(strcmp(s2.getNume(), "ana") == 0);
	assert(s2.getVarsta() == 20);

	Student s3(s2);
	assert(strcmp(s3.getNume(), "ana") == 0);
	assert(s3.getVarsta() == 20);

	s3.setNume("Radu");
	assert(strcmp(s3.getNume(), "Radu") == 0);
	s3.setVarsta(25);
	assert(s3.getVarsta() == 25);

	Student s4;
	s4 = s2;
	assert(strcmp(s4.getNume(), "ana") == 0);
	assert(s4.getVarsta() == 20);

	assert(s2 == s4);
	assert(!(s3 == s4));
}

void testRepo()
{
	Repo repo;
	assert(repo.getLength() == 0);

	Student s1("ana", 20);
	repo.addElem(s1);
	assert(repo.getLength() == 1);
	assert(repo.getAll()[0] == s1);

	Student s2("radu", 25);
	repo.addElem(s2);
	assert(repo.getLength() == 2);
	assert(repo.getAll()[0] == s1);
	assert(repo.getAll()[1] == s2);
}
