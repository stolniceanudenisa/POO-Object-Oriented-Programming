//
// Created by user on 11-May-23.
//

#ifndef SEMINAR5_313_WATERMELON_H
#define SEMINAR5_313_WATERMELON_H

#include "MelonLike.h"

class WaterMelon :public MelonLike{
public:
    WaterMelon(float,bool);
    string getDescription();
    ~WaterMelon();
};


#endif //SEMINAR5_313_WATERMELON_H
