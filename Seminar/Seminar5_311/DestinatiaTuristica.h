//
// Created by user on 04-May-23.
//

#ifndef SEMINAR5_311_DESTINATIATURISTICA_H
#define SEMINAR5_311_DESTINATIATURISTICA_H
#include "Tara.h"
#include <vector>


class DestinatiaTuristica: public Tara{
protected:
    vector<string> obiective;
public:
    DestinatiaTuristica();
    DestinatiaTuristica(string, int, vector<string>);
    DestinatiaTuristica(const DestinatiaTuristica&);
    vector<string> getObiective();
    void setObiective(vector<string>);
    void addObiective(string);
    DestinatiaTuristica& operator=(const DestinatiaTuristica&);
    bool operator==(const DestinatiaTuristica&);
    string toString();
    ~DestinatiaTuristica();
};


#endif //SEMINAR5_311_DESTINATIATURISTICA_H
