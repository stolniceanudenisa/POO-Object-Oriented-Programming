//#include <iostream>
//#include <set>

//int main ()
//{
//    std::set<int> myset;
//    std::set<int>::iterator it;
//    std::pair<std::set<int>::iterator,bool> ret;

//    // set some initial values:
//    for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50

//    ret = myset.insert(20);               // no new element inserted

//    if (ret.second == false) {
//        it=ret.first;  // "it" now points to element 20
//        std::cout<<"it val "<<*it<<'\n';
//    }

//    myset.insert (25);
//    myset.insert (1);
//    myset.insert (13);

//    int myints[]= {5, 10, 15};
//    myset.insert (myints, myints+3); // 10 not inserted

//    std::cout << "myset contains:";
//    for (it=myset.begin(); it!=myset.end(); ++it)
//        std::cout << ' ' << *it;
//    std::cout << '\n';

//    it = myset.begin();
//    ++it;                                         // "it" points now to 5 (the second element)

//    myset.erase (it);
//    std::cout << "myset contains:";
//    for (it=myset.begin(); it!=myset.end(); ++it)
//        std::cout << ' ' << *it;
//    std::cout << '\n';

//    myset.erase (40);

//    std::cout << "myset contains:";
//    for (it=myset.begin(); it!=myset.end(); ++it)
//        std::cout << ' ' << *it;
//    std::cout << '\n';

//    return 0;
//}
