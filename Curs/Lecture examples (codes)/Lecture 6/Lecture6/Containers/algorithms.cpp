//#include <algorithm>
//#include <iostream>
//#include <array>
//
//bool greater(int a, int b)
//{
//    // Order a before b if a is greater than b.
//    return (a > b);
//}
//
//void printArray(const std::array<int, 9> &arr){
//    for (int i : arr)
//    {
//        std::cout << i << ' ';
//    }
//
//    std::cout << '\n';
//}
//
//bool lastDigitIs3(int nr)
//{
//    return nr%10 == 3;
//}
//
//
//int main()
//{
//    std::array<int, 9> arr{ 13, 90, 99, 5, 40, 80, 72, 43, 72 };
//
//    std::sort(arr.begin(), arr.end(), greater);
//    std::cout<<"sorted:\n";
//    printArray(arr);
//    std::cout<<"reversed:\n";
//    std::reverse(arr.begin(), arr.end());
//    printArray(arr);
//    std::cout<<"reversed up until 3:\n";
//    std::reverse(arr.begin(), arr.begin() + 3);
//    printArray(arr);
//
//    int searchedVal = 13;
//    std::array<int, 9>::iterator i = std::find(arr.begin(), arr.end(), searchedVal);
//    if(i != arr.end())
//        std::cout<<"13 found at pos "<<i - arr.begin()<<std::endl;
//
//
//    std::cout<<"72 appears "<<std::count(arr.begin(), arr.end(), 72)<<" times \n";
//    std::cout<<"1001 appears "<<std::count(arr.begin(), arr.end(), 1001)<<" times \n";
//
//    std::array<int, 9>::iterator it = std::find_if (arr.begin(), arr.end(), lastDigitIs3);
//    std::cout << "The first number that has 2 as a last digit value is " << *it << '\n';
//    return 0;
//}
//
