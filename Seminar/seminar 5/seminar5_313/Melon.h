//
// Created by user on 11-May-23.
//

#ifndef SEMINAR5_313_MELON_H
#define SEMINAR5_313_MELON_H

#include "MelonLike.h"

class Melon :public MelonLike{
public:
    Melon(float,bool);
    string getDescription();
    ~Melon();
};


#endif //SEMINAR5_313_MELON_H
