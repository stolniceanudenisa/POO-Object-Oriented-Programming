//
// Created by user on 18-May-23.
//

#ifndef SEMINAR6_311_WATERMELON_H
#define SEMINAR6_311_WATERMELON_H
#include "MelonLike.h"

class Watermelon : public MelonLike {
public:
    Watermelon(int kg, bool withSeeds);
    string getDescription();
    ~Watermelon();
};


#endif //SEMINAR6_311_WATERMELON_H
