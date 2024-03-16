#include "validator.h"
#include "exceptii.h"

void Validator::validate(Melodie m)
{
	string erori = "";

	if (m.getCantaret() == "")
		erori += "Cantaretul nu poate fi vid!\n";
	for (char c : m.getCantaret())
	{
		if (!isalpha(c))
		{
			erori = erori + "Numele nu poate contine decat literele alfabetului;";
			break;
		}
	}

	if (m.getDenumire() == "")
		erori += "Denumirea nu poate fi vida!\n";
	for (char c : m.getDenumire())
	{
		if (!isalpha(c))
		{
			erori = erori + "Denumirea melodiei nu poate contine decat literele alfabetului;";
			break;
		}
	}

	if (m.getGen() == "")
		erori += "Genul nu poate fi vid!\n";
	for (char c : m.getGen())
	{
		if (!isalpha(c))
		{
			erori = erori + "Genul nu poate contine decat literele alfabetului;";
			break;
		}
	}

	if (m.getDurata() <= 0)
		erori += "Durata nu poate fi negativa!\n";

	if (erori != "") // erori.size() > 0
		throw ValidationException(erori);

}
