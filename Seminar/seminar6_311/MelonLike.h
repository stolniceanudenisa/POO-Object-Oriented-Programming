//
// Created by user on 18-May-23.
//

#ifndef SEMINAR6_311_MELONLIKE_H
#define SEMINAR6_311_MELONLIKE_H
#include "Fruit.h"
#include "MyException.h"

class MelonLike : public Fruit {
protected:
    int kg;
public:
    MelonLike(int kg, bool withSeeds);
    string getDescription();
    ~MelonLike();
};


#endif //SEMINAR6_311_MELONLIKE_H
