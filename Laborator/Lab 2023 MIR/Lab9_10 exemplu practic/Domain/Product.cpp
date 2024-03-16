//
// Created by fabia on 5/3/2022.
//

#include "Product.h"

#include <utility>

Product::Product() {
    this->code = -1;
    this->price = -1;
    this->name = "";
}

Product::Product(std::string name,int pCode, int pPrice) {
    this->code = pCode;
    this->price = pPrice;
    this->name = name;
}

int Product::getCode() const {
    return this->code;
}

int Product::getPrice() const {
    return this->price;
}

std::string Product::getName() const {
    return this->name;
}

void Product::setName(std::string pName) {
    this->name = std::move(pName);
}

void Product::setCode(int pCode) {
    this->code = pCode;
}

void Product::setPrice(int pPrice) {
    this->price = pPrice;
}


bool Product::operator<(const Product &product) const {
    return this->code < product.code;
}

ostream& operator<<(ostream& os, const Product& product){
    os << product.getCode() << ' ' << product.getName() << ' ' << product.getPrice();
    return os;
}

