//
// Created by user on 11-May-23.
//

#ifndef SEMINAR5_313_MELONLIKE_H
#define SEMINAR5_313_MELONLIKE_H
#include "Fruit.h"

class MelonLike :public Fruit{
protected:
    float kg;
public:
    MelonLike(float,bool);
    string getDescription();
    ~MelonLike();
};


#endif //SEMINAR5_313_MELONLIKE_H
