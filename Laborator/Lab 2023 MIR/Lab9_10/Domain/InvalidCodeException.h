//
// Created by fabia on 5/18/2022.
//

#ifndef LAB9_10_INVALIDCODEEXCEPTION_H
#define LAB9_10_INVALIDCODEEXCEPTION_H
#include <stdexcept>

class InvalidCodeException :
        public std::invalid_argument{
private:
    char* message;
public:
    InvalidCodeException(char* msg):
            std::invalid_argument(msg), message(msg){
    }
    char* what(){
        return message;
    }

};

#endif //LAB9_10_INVALIDCODEEXCEPTION_H
