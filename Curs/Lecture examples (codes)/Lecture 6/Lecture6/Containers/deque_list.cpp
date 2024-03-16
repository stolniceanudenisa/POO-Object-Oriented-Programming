//#include <iostream>
//#include <list>
//#include <deque>


//int main()
//{

//    std::list<int> li;
//    for (int count=0; count < 6; ++count)
//        li.push_back(count);


//    std::list<int>::const_iterator it; // declare an iterator
//    it = li.cbegin(); // assign it to the start of the list
//    while (it != li.cend()) // while it hasn't reach the end
//    {
//        std::cout << *it << " "; // print the value of the element it points to
//        ++it; // and iterate to the next element
//    }


//    li.push_front(11);
//    li.push_front(12);
//    getchar();
//    it = li.cbegin(); // assign it to the start of the list
//    while (it != li.cend()) // while it hasn't reach the end
//    {
//        std::cout << *it << " "; // print the value of the element it points to
//        ++it; // and iterate to the next element
//    }
//    std::cout << '\n';

//    it = li.begin();
//    ++it;

//    std::cout<<"it pointing at: "<<*it<<std::endl;
//    getchar();
//    li.insert (it,10);
//    it = li.cbegin(); // assign it to the start of the list

//    while (it != li.cend()) // while it hasn't reach the end
//    {
//        std::cout << *it << " "; // print the value of the element it points to
//        ++it; // and iterate to the next element
//    }

//    std::cout << '\n';

//    getchar();
//    std::cout<<"deque example:\n";
//    std::deque<int> deq;
//    for (int idx=0; idx < 3; ++idx)
//    {
//        deq.push_back(idx); // insert at end of array
//        deq.push_front(10 - idx); // insert at front of array
//    }

//    for (size_t index=0; index < deq.size(); ++index)
//        std::cout << deq[index] << ' ';


//}
