#include "validator.h"
#include "exceptii.h"

/// <summary>
/// Valideaza o rochie
/// </summary>
/// <param name="m"></param> rochia de validat
void Validator::validate(Rochie m)
{
	string erori = "";

	if (m.get_denumire() == "")
		erori += "Cantaretul nu poate fi vid!\n";
	for (char c : m.get_denumire())
	{
		if (!isalpha(c))
		{
			erori = erori + "Numele nu poate contine decat literele alfabetului;";
			break;
		}
	}

	if (m.get_culoare() == "")
		erori += "Denumirea nu poate fi vida!\n";
	for (char c : m.get_culoare())
	{
		if (!isalpha(c))
		{
			erori = erori + "Culoarea rochiei nu poate contine decat literele alfabetului;";
			break;
		}
	}

	if (m.get_marime () != "M" && m.get_marime() != "S" && m.get_marime() != "XS" && m.get_marime() != "L" && m.get_marime() != "XL")
		erori += "Marimea poate fi doar XS,S,M,L,XL!\n";
	 
	if (m.get_personalizare() != "True" && m.get_personalizare() != "False")
		erori += "Personalizarea poate fi doar True sau False!\n";

	if (m.get_nr_disponibile() <= 0)
		erori += "Numarul nu poate fi negativ!\n";

	if (m.get_pret() <= 0)
		erori += "Pretul nu poate fi negativ!\n";

	if (erori != "") // erori.size() > 0
		throw ValidationException(erori);
}
