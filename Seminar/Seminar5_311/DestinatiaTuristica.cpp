//
// Created by user on 04-May-23.
//

#include "DestinatiaTuristica.h"

DestinatiaTuristica::DestinatiaTuristica():Tara() {

}

DestinatiaTuristica::DestinatiaTuristica(string dem, int pop, vector<string> obi):Tara(dem, pop) {
    for (int i = 0; i < obi.size(); ++i) {
        obiective.push_back(obi[i]);
    }
}

DestinatiaTuristica::DestinatiaTuristica(const DestinatiaTuristica & desti):Tara(desti) {
    for (int i = 0; i < desti.obiective.size(); ++i) {
        obiective[i] = desti.obiective[i];
    }
}

vector<string> DestinatiaTuristica::getObiective() {
    return obiective;
}

void DestinatiaTuristica::setObiective(vector<string> obi) {
obiective = obi;
}

void DestinatiaTuristica::addObiective(string ob) {
obiective.push_back(ob);
}

DestinatiaTuristica &DestinatiaTuristica::operator=(const DestinatiaTuristica & desti) {
    if(this != &desti)
    {
        Tara::operator=(desti);
        for (int i = 0; i < desti.obiective.size(); ++i) {
            obiective[i] = desti.obiective[i];
        }
    }
    return *this;
}

bool DestinatiaTuristica::operator==(const DestinatiaTuristica & desti) {
    return Tara::operator==(desti) && obiective == desti.obiective;
}

string DestinatiaTuristica::toString() {
    string rez = Tara::toString();
    for (auto dest:obiective)
        rez = rez + ", " + dest;
    return rez;
}

DestinatiaTuristica::~DestinatiaTuristica() {

}
