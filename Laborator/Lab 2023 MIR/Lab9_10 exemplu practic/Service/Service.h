//
// Created by fabia on 5/3/2022.
//

#ifndef LAB9_10_SERVICE_H
#define LAB9_10_SERVICE_H
#include "Product.h"
#include "Repo.h"
#include "Repo.cpp"
#include "Money.h"
#include <vector>
#include "RepoFile.h"

class Service {
private:
    RepoFile<Product>& productRepo;
    RepoFile<Money>& moneyRepo;
public:
    Service(RepoFile<Product> &productRepo, RepoFile<Money> &moneyRepo);
//    Service(Repo<Product>& testRepo);
    ~Service();

    void addProduct(const Product&, int);
    void addMoney(const int , int);

    void addAmountOfProduct(const Product&, int);
    void addAmountOfMoney(const Money&, int);

    void deleteProduct(const Product&);
    void deleteMoney(const Money&);

    void deleteOneAmountProduct(const Product&);
    void deleteAmountOfMoney(const Money&, int);

//    int existingAmountOfProduct(const Product&);
//    int existingAmountOfMoney(const Money&);
    Product getProductByCode(int code);
    void getAllProducts(vector<Product>&);
//    void handleMoneyExchange(int );
};


#endif //LAB9_10_SERVICE_H
