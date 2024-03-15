//
// Created by user on 18-May-23.
//

#include "Fruit.h"

Fruit::Fruit(bool withSeeds) {
    this->withSeeds = withSeeds;
}

bool Fruit::isWithSeeds() {
    return this->withSeeds;
}

Fruit::~Fruit() {

}
