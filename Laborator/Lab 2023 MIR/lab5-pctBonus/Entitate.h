//
// Created by alex t. on 22/03/2023.
//

#ifndef LAB4_Entitate_H
#define LAB4_Entitate_H
#include <iostream>

class Entitate {
private:
    int raza;
    int cX;
    int cY;
public:
    Entitate();
    Entitate(int raza, int cX, int cY);
    Entitate(const Entitate &c);
    int getRaza();
    int getCX();
    int getCY();
    void setRaza(int raza);
    void setCX(int cX);
    void setCY(int cY);
    double aria() const;
    int perimetru();
    bool operator==(const Entitate &e);
    Entitate& operator=(const Entitate &e);
    bool operator>(const Entitate &e);
    friend std::istream& operator>>(std::istream& is, Entitate& e);
    friend std::ostream& operator<<(std::ostream& os, Entitate& e);
};


#endif //LAB4_Entitate_H
