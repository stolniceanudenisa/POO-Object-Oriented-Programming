//
// Created by fabia on 5/18/2022.
//

#ifndef LAB9_10_INVALIDMONEYVALUEEXCEPTION_H
#define LAB9_10_INVALIDMONEYVALUEEXCEPTION_H

#include <stdexcept>

class InvalidMoneyValueException : public std::invalid_argument{
private:
    char* msg;
public:
    InvalidMoneyValueException(char* message) :
    std::invalid_argument(message), msg(message){

    }
    char* what(){
        return msg;
    }

};

#endif //LAB9_10_INVALIDMONEYVALUEEXCEPTION_H
