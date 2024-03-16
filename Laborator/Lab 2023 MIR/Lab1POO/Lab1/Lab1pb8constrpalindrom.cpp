//#include <iostream>
//using namespace std;
//
//int reverse(int num) {
//    int rev = 0;
//    while (num > 0) {
//        rev = rev * 10 + num % 10;
//        num /= 10;
//    }
//    return rev;
//}
//
//int constructPalindrome(int num) {
//    int rev = reverse(num);
//    int palindrome = num;
//    while (rev > 0) {
//        palindrome = palindrome * 10 + rev % 10;
//        rev /= 10;
//    }
//    return palindrome;
//}
//
//int main() {
//    int num;
//    cout << "Enter a natural number: ";
//    cin >> num;
//    int palindrome = constructPalindrome(num);
//    cout << "The palindrome of " << num << " is " << palindrome << endl;
//    return 0;
//}
