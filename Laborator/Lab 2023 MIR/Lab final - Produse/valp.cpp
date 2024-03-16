#include "valp.h"
#include "valpexc.h"

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

	if (p->getCod() < 0) {
		erori += "Codul trebuie sa fie un numar pozitiv!";
	}

	if (p->getNraparitii() < 0) {
		erori += "Numarul de aparitii trebuie sa fie un numar pozitiv!";
	}


	if (erori.size() > 0)
	{
		throw ValidationException(erori);
	}
}









//for (char c : to_string(p->getCod())) {
//	if (!isdigit(c)) {
//		throw ValidationException("Codul trebuie să fie un număr întreg pozitiv!");
//	}
//}