#include <iostream>
#include "StudentBursier.h"
#include <vector>
using namespace std;

int main()
{
    cout<<"Hello world!"<<endl;
    Student s(1,"Ana");
    StudentBursier sb(2,"George","merit");
    cout<<s.tostring()<<endl;
    cout<<sb.toString()<<endl;
    vector <Student> v;
    v.push_back(s);
    v.push_back(sb);
    for (Student s:v)
        cout<<s.tostring()<<endl;
    return 0;
}
