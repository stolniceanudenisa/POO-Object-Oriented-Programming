#include "validatorprodus.h"
#include "validationexception.h"
 
ValidatorProdus::ValidatorProdus()
{
}

ValidatorProdus::~ValidatorProdus()
{
}

void ValidatorProdus::validate(Produs* p) throw(ValidationException)
{
    string errorMessage = "";

    if (p->getNume().empty())
    {
        errorMessage += "Numele produsului nu poate fi gol!\n";
    }
    for (char c : p->getNume())
    {
        if (!isalpha(c))
        {
            errorMessage += "Numele produsului poate sa contina doar litere! \n";
            break;
        }
    }

    if (p->getPret() <= 0)
    {
        errorMessage += "Pretul produsului trebuie sa fie strict pozitiv! \n";
    }

    if (errorMessage.length() > 0)
    {
        throw ValidationException(errorMessage);
    }
}
