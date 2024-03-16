//
// Created by 40766 on 05.05.2023.
//
#include "util.h"
#include <sstream>

vector<string> tokenize(string linie, char delimitator) {
    vector<string> rezultat;
    stringstream ss(linie);
    string token;
    while (getline(ss, token, ','))
    {
        rezultat.push_back(token);
    }
    return rezultat;
}

