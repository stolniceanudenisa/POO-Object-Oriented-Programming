#include <iostream>
#include "RepoFile.h"

int main() {
    RepoFile repository("Studenti.txt");
    vector<Student> v = repository.getAll();
    Student s1("Alex",20);
    //repository.add(s1);
    cout<<repository.find(s1)<<endl;
    Student s2("George", 40);
    repository.update(s1,s2);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
