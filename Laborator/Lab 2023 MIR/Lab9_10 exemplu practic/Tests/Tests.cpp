//
// Created by fabia on 5/3/2022.
//

#include "Tests.h"
#include "Repo.h"
#include "Product.h"
#include "Money.h"
#include "Service.h"
#include <cassert>

RepoFile<struct Product> productTestRepo;
RepoFile<struct Money> moneyTestRepo;
Service service(productTestRepo, moneyTestRepo);
Product cola("Cola", 1, 5);
Money unLeu(1);

void testAddElement(){
    Repo<Product> theRepository;
    theRepository.addElement(cola, 4);
    map<Product, int> repo = theRepository.getRepo();

    assert(repo.count(cola) != 0);
}

void testDeleteElement(){
    Repo<Product> theRepository;
    theRepository.deleteElement(cola);
    map<Product, int> repo = theRepository.getRepo();
    assert(repo.count(cola) == 0);
}

void testModifyAmountElement(){
    Repo<Product> theRepository;
    theRepository.addElement(cola, 5);
    theRepository.modifyAmountElement(cola, 4);
    map<Product, int> repo = theRepository.getRepo();
    auto it = repo.find(cola);
    assert(it->second == 9);
}

void testAmountOfElement(){
    Repo<Product> theRepository;
    theRepository.addElement(cola, 4);
//    map<Product, int> repo = theRepository.getRepo();
    assert(theRepository.amountOfElement(cola) == 4);
}


void testAddMoneyOrProduct(){

    service.addMoney(unLeu, 5);
    service.addProduct(cola, 5);
    map<Product, int> pTestRepo = productTestRepo.getRepo();
    map<Money, int> mTestRepo = moneyTestRepo.getRepo();
    assert(pTestRepo.empty() == false);
    assert(mTestRepo.empty() == false);
}

void testDeleteMoneyOrProduct(){
    service.deleteMoney(unLeu);
    service.deleteProduct(cola);
    map<Product, int> pTestRepo = productTestRepo.getRepo();
    map<Money, int> mTestRepo = moneyTestRepo.getRepo();
    assert(pTestRepo.empty() == true);
    assert(mTestRepo.empty() == true);
}

void testAddAmountOfProductOrMoney(){
    service.addProduct(cola, 5);
    service.addMoney(unLeu, 5);
    service.addAmountOfProduct(cola, 5);
    service.addAmountOfMoney(unLeu, 5);
    assert(productTestRepo.amountOfElement(cola) == 10);
    assert(moneyTestRepo.amountOfElement(unLeu) == 10);
}

void testDeleteAmountOfProductOrMoney(){
    service.deleteOneAmountProduct(cola);
    assert(productTestRepo.amountOfElement(cola) == 9);
    service.deleteAmountOfMoney(unLeu, 5);
    assert(moneyTestRepo.amountOfElement(unLeu) == 5);
}

void testAll(){
    testAddElement();
    testDeleteElement();
    testModifyAmountElement();
    testAmountOfElement();
    testAddMoneyOrProduct();
    testDeleteMoneyOrProduct();
    testAddAmountOfProductOrMoney();
    testDeleteAmountOfProductOrMoney();
}