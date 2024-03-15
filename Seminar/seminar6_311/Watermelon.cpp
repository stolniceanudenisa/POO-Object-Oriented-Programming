//
// Created by user on 18-May-23.
//

#include "Watermelon.h"

Watermelon::Watermelon(int kg, bool withSeeds) : MelonLike(kg, withSeeds) {

}

string Watermelon::getDescription() {
    return MelonLike::getDescription() + " watermelon";
}

Watermelon::~Watermelon() {

}
