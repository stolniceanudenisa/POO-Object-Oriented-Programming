//
// Created by user on 18-May-23.
//

#ifndef SEMINAR6_311_MELON_H
#define SEMINAR6_311_MELON_H
#include "MelonLike.h"

class Melon : public MelonLike {
public:
    Melon(int kg, bool withSeeds);
    string getDescription();
    ~Melon();
};


#endif //SEMINAR6_311_MELON_H
