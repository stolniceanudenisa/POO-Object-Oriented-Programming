//
// Created by fabia on 5/3/2022.
//

#ifndef LAB9_10_PRODUCT_H
#define LAB9_10_PRODUCT_H
#include <string>
#include <ostream>
#include <istream>
using namespace std;
class Product {
private:
    int code;
    int price;
    std::string name;
public:
    Product();
    Product(std::string, int, int);
    ~Product() = default;

    int getCode() const;
    int getPrice() const ;
    std::string getName() const ;
    void setCode(int);
    void setPrice(int);
    void setName(std::string);

    bool operator <(const Product& product) const;

    friend ostream& operator<<(ostream& os, const Product& product);
    friend istream& operator>>(istream& is, Product& product){
        is >> product.code >> product.name >> product.price;
        return is;
    }

};


#endif //LAB9_10_PRODUCT_H
