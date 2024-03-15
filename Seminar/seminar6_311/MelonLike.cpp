//
// Created by user on 18-May-23.
//

#include "MelonLike.h"

MelonLike::MelonLike(int kg, bool withSeeds) : Fruit(withSeeds) {
    if(kg < 0)
        throw MyException("Cantitatea este negativa!");
    this->kg = kg;
}

string MelonLike::getDescription() {
    if(withSeeds)
        return std::to_string(kg) + ' ' + "melon like with seeds" ;
    return std::to_string(kg) + ' ' + "melon like without seeds";
}

MelonLike::~MelonLike() {

}
