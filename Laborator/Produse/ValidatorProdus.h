#pragma once
#include "Produs.h"
class ValidatorProdus {
public:
	ValidatorProdus();
	~ValidatorProdus();

	void validate(Produs* p);
};
