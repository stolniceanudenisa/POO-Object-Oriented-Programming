//
// Created by user on 11-May-23.
//

#include "Fruit.h"

Fruit::Fruit(bool seeds)
{
    withSeeds=seeds;
}

bool Fruit::isWithSeeds() {
    return withSeeds;
}

Fruit::~Fruit() {

}
