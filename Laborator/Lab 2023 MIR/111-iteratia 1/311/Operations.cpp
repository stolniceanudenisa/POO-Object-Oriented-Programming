#include "Operations.h"

void filtreazaStudenti(Student studenti[], int len, const char* substr, int varsta, Student rezultat[], int& lenRezultat)
{
	lenRezultat = 0;
	for (int i = 0; i < len; i++)
	{
		if (strstr(studenti[i].getNume(), substr) != NULL && studenti[i].getVarsta() > varsta)
		{
			rezultat[lenRezultat] = studenti[i];
			lenRezultat++;
		}
	}
}
