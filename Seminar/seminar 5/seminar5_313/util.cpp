//
// Created by user on 11-May-23.
//

#include "util.h"

int getPosition(vector<Fruit*> fruits,Fruit *fruit)
{
    int i=0;
    if(fruits.size()==0)
        return 0;
    if(fruit->getDescription()>fruits[fruits.size()-1]->getDescription())
        return fruits.size();
    if (fruit->getDescription()<fruits[0]->getDescription())
        return 0;
    while(i<fruits.size()&&fruits[i]->getDescription()<fruit->getDescription())
        i++;
    return i;
}

void insertFruit(vector<Fruit*> &fruits,Fruit *fruit)
{
    vector<Fruit*> ::iterator it=fruits.begin();
    int pos= getPosition(fruits,fruit);
    if (fruits.size()==0)
        fruits.push_back(fruit);
    else
    {
        it=it+pos;
        fruits.insert(it,fruit);
    }
}

void seedsBasedPrint(bool withSeeds,vector<Fruit*> fruits)
{
    for(auto f : fruits)
    {
        if(f->isWithSeeds()==withSeeds)
            cout<<f->getDescription()<<endl;
    }

}
