//
// Created by user on 11-May-23.
//

#include "WaterMelon.h"

WaterMelon::WaterMelon(float newKg, bool seeds) : MelonLike(newKg,seeds){}

string WaterMelon::getDescription() {
    return MelonLike::getDescription()+" Watermelon";
}

WaterMelon::~WaterMelon() {

}
