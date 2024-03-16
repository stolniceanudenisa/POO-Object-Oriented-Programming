//#include <iostream>
//#include <map>
//#include <string>

//int main()
//{
//    std::map<int, std::string> mymap;
//    mymap.insert(std::make_pair(6, "mango"));
//    mymap.insert(std::make_pair(4, "apple"));
//    mymap.insert(std::make_pair(2, "orange"));
//    mymap.insert(std::make_pair(1, "banana"));
//    mymap.insert(std::make_pair(5, "peach"));
//    mymap.insert(std::make_pair(3, "grapes"));
//    std::pair<std::map<int, std::string>::iterator,bool> ret = mymap.insert(std::make_pair(1, "pineapple"));
//    if(!ret.second)
//        std::cout<<"pineapple not inserted; already exists element with key "<<1<<" with value "<<ret.first->second<<std::endl;
//    mymap[10] = "lychee";

//    auto it{ mymap.cbegin() }; // declare a const iterator and assign to start of map
//    while (it != mymap.cend()) // while it hasn't reach the end
//    {
//        std::cout << it->first << "=" << it->second << " "; // print the value of the element it points to
//        ++it; // and iterate to the next element
//    }

//    std::cout << '\n';
//    it = mymap.find(1);
//    if (it != mymap.end()){
//        std::cout<<"map contains element with key 1 and value "<<it->second<<std::endl;
//        mymap.erase(it);
//    }

//    it = mymap.cbegin(); // declare a const iterator and assign to start of map
//    while (it != mymap.cend()) // while it hasn't reach the end
//    {
//        std::cout << it->first << "=" << it->second << " "; // print the value of the element it points to
//        ++it; // and iterate to the next element
//    }

//    std::cout << '\n';
//}
