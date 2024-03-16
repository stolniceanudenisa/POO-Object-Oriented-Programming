#include "validator.h"
#include"exceptii.h"
void Validator::validate(Meci meci)
{
	string erori = "";
   
    if (meci.get_scor1() < 0)
        erori += "Scorul nu poate fi negativ!\n";
    if (meci.get_scor2() <0)
        erori += "Scorul nu poate fi negativ!\n";
    if (meci.get_echipa1() == "")
        erori += "Numele nu poate fi gol!\n";
    if (meci.get_echipa2() == "")
        erori += "Numele nu poate fi gol!\n";
	if (meci.get_echipa1() == meci.get_echipa2()) {
		erori += "Numele echipelor trebuie sa fie diferite!\n";
	}
    if (erori != "")
        throw ValidationException(erori);



	 
	/*if (p->getNume() == "")
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
	}*/
}

