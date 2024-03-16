//
// Created by fabia on 5/3/2022.
//

#include "Money.h"

Money::Money() {
    this->value = -1;
}

Money::Money(int mValue) {
    this->value = mValue;
}

Money::~Money() = default;

int Money::getValue() const {
    return this->value;
}

void Money::setValue(int mValue) {
    this->value = mValue;
}

bool Money::operator<(const Money &money) const {
    return this->value < money.value;
}

ostream& operator<<(ostream& os, const Money& money) {
    os << money.getValue();
    return os;
}