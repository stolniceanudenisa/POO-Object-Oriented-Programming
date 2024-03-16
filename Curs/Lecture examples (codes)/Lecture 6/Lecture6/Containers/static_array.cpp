//#include <iostream>
//#include <array>
//int main(){

//    std::array<int, 5> arr1 = { 9, 3, 5, 3, 1}; // initializer list
//    std::array<int, 5> arr2 { 9, 3, 5, 3, 1 }; // uniform initialization

//    // only since c++17 , type and size can be omitted SIMULTANEOUSLY only
//    //    std::array myArray1 { 9, 7, 5, 3, 1 }; // The type is deduced to std::array<int, 5>
//    //    std::array myArray2 { 9.7, 7.31 }; // The type is deduced to std::array<double, 2>

//    std::cout << arr1[1] << '\n';
//    arr1[1] = 6;
//    std::cout << arr1.at(1) << '\n'; // arr.at(i) === arr[i]
//    // arr.at(1) -> 6
//    arr1.at(1)++;
//    std::cout << arr1.at(1) << '\n';
//    std::cout<<"array size: "<<arr1.size()<<'\n';

//    /// std::array<int, 5>::iterator var_name
//    for(std::array<int, 5>::iterator it = arr2.begin(); it != arr2.end(); it++){
//        std::cout << *it << " ";
//    }
//    return 0;
//}
