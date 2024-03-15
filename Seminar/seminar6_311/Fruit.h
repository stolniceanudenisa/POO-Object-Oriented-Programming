//
// Created by user on 18-May-23.
//

#ifndef SEMINAR6_311_FRUIT_H
#define SEMINAR6_311_FRUIT_H
#include <string>

using namespace std;

class Fruit {
protected:
    bool withSeeds;
public:
    Fruit(bool withSeeds);
    bool isWithSeeds();
    virtual string getDescription() = 0;
    virtual ~Fruit();
};


#endif //SEMINAR6_311_FRUIT_H
