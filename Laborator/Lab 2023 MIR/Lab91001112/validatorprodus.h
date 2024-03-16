#pragma once
#include "produs.h"
class ValidatorProdus {
public:
	ValidatorProdus();
	~ValidatorProdus();

	void validate(Produs* p);
};
