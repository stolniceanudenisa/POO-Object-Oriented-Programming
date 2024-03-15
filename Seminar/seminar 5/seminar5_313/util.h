//
// Created by user on 11-May-23.
//

#ifndef SEMINAR5_313_UTIL_H
#define SEMINAR5_313_UTIL_H

#include <iostream>
#include "WaterMelon.h"
#include "Melon.h"
#include <vector>
#include "MelonLike.h"

int getPosition(vector<Fruit*> fruits,Fruit *fruit);

void insertFruit(vector<Fruit*> &fruits,Fruit *fruit);


void seedsBasedPrint(bool withSeeds,vector<Fruit*> fruits);

#endif //SEMINAR5_313_UTIL_H
