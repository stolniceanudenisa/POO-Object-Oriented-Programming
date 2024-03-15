//
// Created by user on 11-May-23.
//

#include "Melon.h"

Melon::Melon(float newKg, bool seeds) : MelonLike(newKg,seeds){}

string Melon::getDescription() {
    return MelonLike::getDescription()+" Melon";
}

Melon::~Melon() {

}

