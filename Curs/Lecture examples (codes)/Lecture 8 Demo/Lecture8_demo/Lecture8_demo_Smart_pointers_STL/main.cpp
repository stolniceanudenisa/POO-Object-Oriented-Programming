//#include <Windows.h>
//#include <memory>
//#include <string>
//#include <iostream>
//#include "Student.h"
//#include <vector>
//using namespace std;
//
//void printSP(std::unique_ptr<std::string> &ptr) {
//	cout << *ptr << endl;
//}
//
//void exampleUniquePtr()
//{
//	
//	std::unique_ptr<std::string> ptr1 =  std::make_unique<std::string>("Hello, I am a string owned by a unique_ptr.");
//	//auto ptr3 = ptr1; // you are not allowed to copy a unique ptr
//	//cout << *ptr1 << endl;
//	printSP(ptr1);
//
//	auto ptr2 = std::move(ptr1); // ptr2 has taken ownership of the string and ptr1 is now nullptr
//
//	if (ptr1 == nullptr)
//	{
//		std::cout << "ptr1 is now nullptr." << std::endl;
//	}
//	cout << *ptr2 << endl;
//}
//
//// -------------------------------------------------------------------------------------------------------------------------------
//
//void exampleSharedPtr()
//{
//	
//	std::shared_ptr<Student> ptr1 = 
//		std::make_shared<Student>("George Alan", "210105463");
//	
//	{
//		std::shared_ptr<Student> ptr2 = ptr1; // 2 shared pointers point to the same student - in Debug [control block] -> [Raw View] -> [Uses]
//		auto ptr3 = ptr2; // 3 shared pointers point to the same student
//	}
//	// at the end of this scope, ptr2 and ptr3 are destroyed => reference count is now 1
//	// the student is not yet destroyed, since there still is one pointer which owns it (ptr1)
//	
//	auto ptr4 = std::move(ptr1); // ptr1 is nullptr, but there is still 1 reference count (ptr4)
//}
//
//
//int main()
//{
//	system("color f4");
//
//	// unique pointer
//	//exampleUniquePtr();
//
//	// shared pointer
//	exampleSharedPtr();
//
//	_CrtDumpMemoryLeaks();
//	system("pause");
//
//	return 0;
//}