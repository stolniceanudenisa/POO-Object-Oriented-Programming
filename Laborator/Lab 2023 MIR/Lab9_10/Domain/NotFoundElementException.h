//
// Created by fabia on 5/17/2022.
//

#ifndef LAB9_10_NOTFOUNDELEMENTEXCEPTION_H
#define LAB9_10_NOTFOUNDELEMENTEXCEPTION_H
#include <stdexcept>


class ElementNotFoundException :
        public std::runtime_error{
private:
    char* message;
public:
    ElementNotFoundException(char* msg):
            std::runtime_error(msg), message(msg){
    }
    char* what(){
        return message;
    }

};
#endif //LAB9_10_NOTFOUNDELEMENTEXCEPTION_H
