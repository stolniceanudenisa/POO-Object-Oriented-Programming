

#include "Service.h"
#include "InvalidMoneyValueException.h"
#include "InvalidCodeException.h"
#include "NotFoundElementException.h"
#include "MoneyValidator.h"
#include "ProductValidator.h"
#include "Money.h"
#include <vector>
Service::Service(RepoFile<Product> &productRepo, RepoFile<Money> &moneyRepo) :
productRepo(productRepo), moneyRepo(moneyRepo) {

}


Service::~Service() = default;

void Service::addMoney(const int money, int noMoney) {
    MoneyValidator val(1, 5, 10);
    val.validate(money);
    Money mon(money);
    this->moneyRepo.addElement(mon, noMoney);
}

void Service::addProduct(const Product& product, int noProducts) {
    ProductValidator val(0);
    val.validate(product.getCode());
    this->productRepo.addElement(product, noProducts);
}

void Service::addAmountOfProduct(const Product& product, int amount) {
    if (this->productRepo.getRepo().find(product) == productRepo.getRepo().end())
        throw ElementNotFoundException("The product wasn't found");
    this->productRepo.modifyAmountElement(product, amount);
}

void Service::addAmountOfMoney(const Money & money, int amount) {
    if(this->moneyRepo.getRepo().find(money) == moneyRepo.getRepo().end())
        throw ElementNotFoundException("The money doesn't exit");
    this->moneyRepo.modifyAmountElement(money, amount);

}

void Service::deleteProduct(const Product &product) {
    if (this->productRepo.getRepo().find(product) == productRepo.getRepo().end())
        throw ElementNotFoundException("The product wasn't found");
    this->productRepo.deleteElement(product);
}

void Service::deleteMoney(const Money &money) {
    if(this->moneyRepo.getRepo().find(money) == moneyRepo.getRepo().end())
        throw ElementNotFoundException("The money doesn't exit");
    this->moneyRepo.deleteElement(money);
}

void Service::deleteOneAmountProduct(const Product &product) {
    if (this->productRepo.getRepo().find(product) == productRepo.getRepo().end())
        throw ElementNotFoundException("The product wasn't found");
    this->productRepo.modifyAmountElement(product, -1);
}

void Service::deleteAmountOfMoney(const Money &money, int amount) {
    if(this->moneyRepo.getRepo().find(money) == moneyRepo.getRepo().end())
        throw ElementNotFoundException("The money doesn't exit");
    this->moneyRepo.modifyAmountElement(money, -amount);
}

Product Service::getProductByCode(int code){
    map<Product, int> products = this->productRepo.getRepo();
    for(auto it = products.begin(); it != products.end(); it++)
        if(it->first.getCode() == code)
            return it -> first;
}

void Service::getAllProducts(vector<Product>& allProducts){
    map<Product, int> pRepo = this->productRepo.getRepo();
    for(auto it = pRepo.begin(); it != pRepo.end(); it++)
        allProducts.push_back(it->first);
}








