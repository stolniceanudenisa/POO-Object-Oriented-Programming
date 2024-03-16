//
// Created by fabia on 5/17/2022.
//

#ifndef LAB9_10_PRODUCTVALIDATOR_H
#define LAB9_10_PRODUCTVALIDATOR_H

#include "InvalidCodeException.h"

class ProductValidator{
private:
    int validCode;
public:
    ProductValidator(int code) : validCode(code){
    }

    void validate(int code){
        if (code < validCode)
            throw InvalidCodeException("The given code must be natural number");
    }
};

#endif //LAB9_10_PRODUCTVALIDATOR_H
