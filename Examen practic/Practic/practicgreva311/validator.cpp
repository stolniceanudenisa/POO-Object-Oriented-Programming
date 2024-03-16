#include "validator.h"
#include "exceptii.h"

void Validator::validate(Profesor p)
{
	string erori = "";

	if (p.getNume() == "")
		erori += "Cantaretul nu poate fi vid!\n";
	for (char c : p.getNume())
	{
		if (!isalpha(c))
		{
			erori = erori + "Numele nu poate contine decat literele alfabetului;";
			break;
		}
	}

	if (p.getDisciplina() == "")
		erori += "Disciplina nu poate fi vida!\n";
	for (char c : p.getDisciplina())
	{
		if (!isalpha(c))
		{
			erori = erori + "Disciplina nu poate contine decat literele alfabetului;";
			break;
		}
	}
	if (p.getClase() == "")
		erori += "Genul nu poate fi vid!\n";


	if (p.getGreva() == "")
		erori += "Genul nu poate fi vid!\n";

	if (p.getGreva() != "da" && p.getGreva() != "nu")
		erori += "Greva poate fi doar da sau nu!\n";
	

	if (erori != "") // erori.size() > 0
		throw ValidationException(erori);

}
