#pragma once
class TestService {
private:
    void testGetAll();
    void testAddProdusDulce();
    void testAddProdusSarat();
    void testUpdateProdusDulce();
    void testUpdateProdusSarat();
    void testDeleteProdus();

    void testFilterByPrice();
    void testSortByName();
public:
    TestService();
    ~TestService();
    void testAll();
};  
