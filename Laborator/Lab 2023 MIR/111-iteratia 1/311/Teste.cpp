#include "Teste.h"
#include "Student.h"
#include "Operations.h"
#include <assert.h>

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

void testFiltreazaStudenti()
{
	Student s1("ana", 20);
	Student s2("radu", 25);
	Student s3("narcis", 30);

	// se apaleaza constructorul implicit de 3 ori
	Student studenti[3], rezultat[3];
	int lenRezultat;
	// se apeleaza operatorul de asignare
	studenti[0] = s1;
	studenti[1] = s2;
	studenti[2] = s3;

	filtreazaStudenti(studenti, 3, "na", 18, rezultat, lenRezultat);
	assert(lenRezultat == 2);
	assert(rezultat[0] == s1);
	assert(rezultat[1] == s3);

	filtreazaStudenti(studenti, 3, "na", 22, rezultat, lenRezultat);
	assert(lenRezultat == 1);
	assert(rezultat[0] == s3);
}
