//
// Created by fabia on 5/3/2022.
//

#ifndef LAB9_10_MONEY_H
#define LAB9_10_MONEY_H
#include <ostream>
#include <istream>
using namespace std;
class Money {
private:
    int value;
public:
    Money();
    Money(int);
    ~Money();

    int getValue() const;
    void setValue(int);

    bool operator <(const Money& money) const;
    friend ostream& operator<<(ostream& os, const Money& money);
    friend istream& operator>>(istream& is, Money& money){
        is >> money.value;
        return is;
    }

};


#endif //LAB9_10_MONEY_H
