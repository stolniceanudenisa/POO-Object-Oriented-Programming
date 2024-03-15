//
// Created by user on 11-May-23.
//

#ifndef SEMINAR5_313_FRUIT_H
#define SEMINAR5_313_FRUIT_H

#include <string>
using namespace std;

class Fruit {
protected:
    bool withSeeds;
public:
    Fruit(bool);
    virtual string getDescription()=0;
    bool isWithSeeds();
    virtual ~Fruit();
};


#endif //SEMINAR5_313_FRUIT_H
