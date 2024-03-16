#pragma once
 
#include "RepoFile.h"

class TestRepoFile {
private:
    const string fileName = "testProductsIn.txt";
    const string fileNameOut = "testProductsOut.txt";
    const string fileNameInvalid = "testInvalidProducts.txt";
    vector<Produs*> produse;

    void testAddProdus();
    void testUpdateProdus();
    void testDeleteProdus();

    void testLoadFromFile();
    void testSaveToFile();
public:
    TestRepoFile();
    ~TestRepoFile();
    void testAll();
};