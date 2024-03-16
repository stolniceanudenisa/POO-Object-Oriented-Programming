//#include <vector>
//#include <iostream>

//void printVec(std::vector<int> vect){
//    for (size_t index=0; index < vect.size(); ++index)
//        if(index % 2)
//            std::cout << vect[index] << ' ';
//        else
//            std::cout << vect.at(index) << ' ';
//    std::cout << '\n';
//}

//int main()
//{

//    std::vector<int> vect;

//    for (int count=0; count < 6; ++count)
//        vect.push_back(10 - count); // insert at end of array

//    printVec(vect);

//    vect.pop_back();
//    vect.pop_back();
//    printVec(vect);

//    std::cout<<"vector size: "<<vect.size()<<" vector capacity: "<<vect.capacity()<<std::endl;

//    // iterate through vector using iterators
//    std::vector<int>::const_iterator it; // declare a read-only iterator
//    it = vect.cbegin(); // assign it to the start of the vector
//    while (it != vect.cend()) // while it hasn't reach the end
//    {
//        std::cout << *it << " "; // print the value of the element it points to
//        ++it; // and iterate to the next element
//    }
//    std::cout<<std::endl;
//    // iterate through vector using iterators v2
//    for( auto it = vect.begin(); it != vect.end(); it++){
//        std::cout << *it << " ";
//    }
//    return 0;

//}
