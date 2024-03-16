#include "ValidatorProdus.h"
#include "ValidationException.h"
 
void ValidatorProdus::validate(Produs* p)
{
	string erori = "";
	if (p->getNume() == "")
	{
		erori = erori + "Numele nu poate fi gol;";
	}
	for (char c : p->getNume())
	{
		if (!isalpha(c))
		{
			erori = erori + "Numele nu poate contine decat literele alfabetului;";
			break;
		}
	}
	if (p->getPret() <= 0)
	{
		erori += "Pretul trebuie sa fie pozitiv!";
	}
	if (erori.size() > 0)
	{
		throw ValidationException(erori);
	}
}
