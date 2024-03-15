//
// Created by user on 18-May-23.
//

#include "Melon.h"

Melon::Melon(int kg, bool withSeeds) : MelonLike(kg, withSeeds) {

}

string Melon::getDescription() {
    return MelonLike::getDescription() + " melon";
}

Melon::~Melon() {

}
