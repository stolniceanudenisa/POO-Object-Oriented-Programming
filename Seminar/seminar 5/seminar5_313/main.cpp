#include <iostream>
#include "util.h"
#include "MelonLike.h"

int main() {
    vector<Fruit*> fruits;
    WaterMelon WM1(6,0);
    WaterMelon WM2(13,1);
    Melon M1(10,1);
    MelonLike ML(11,0);
    insertFruit(fruits,&WM1);
    insertFruit(fruits,&WM2);
    insertFruit(fruits,&M1);
    insertFruit(fruits,&ML);
//    fruits.push_back(&WM1);
//    fruits.push_back(&WM2);
//    fruits.push_back(&M1);
//    fruits.push_back(&ML);
    seedsBasedPrint(false,fruits);
    cout<<"*"<<endl;
    seedsBasedPrint(true,fruits);
    return 0;
}
