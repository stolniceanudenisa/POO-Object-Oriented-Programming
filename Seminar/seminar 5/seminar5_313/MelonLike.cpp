//
// Created by user on 11-May-23.
//

#include "MelonLike.h"

MelonLike::MelonLike(float newKg, bool seeds): Fruit(seeds) {
    kg=newKg;
}

string MelonLike::getDescription()
{
    return withSeeds? to_string(kg)+" Melon like with seeds": to_string(kg)+"  Melon like without seeds";
}

MelonLike::~MelonLike() {

}
