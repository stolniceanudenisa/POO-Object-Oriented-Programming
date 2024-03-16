//#include<iostream>
//#include <stack>
//#include <queue>
//using std::queue;
//using std::stack;
//using std::cout;
//#include <iomanip>

//void printStack(stack<int> stk)
//{
//    while (!stk.empty())
//    {
//        cout << '\t' << stk.top();
//        stk.pop();
//    }
//    cout << '\n';
//}

//void printQueue(queue<int> myqueue)
//{
//   queue <int> secqueue = myqueue;
//   while (!secqueue.empty())
//   {
//      cout << '\t' << secqueue.front();
//      secqueue.pop();
//   }
//   cout << '\n';
//}

//int main(){

//    /// stack example
//    stack <int> stk;
//    stk.push(1);
//    stk.push(3);
//    stk.push(5);
//    stk.push(7);
//    stk.push(9);

//    cout << "The stack is : ";
//    printStack(stk);

//    cout <<"\nSize of stack: " << stk.size();
//    cout <<"\nTop of stack: " << stk.top();
//    cout <<"\nstk.pop() : \n";
//    stk.pop();
//    cout << "The stack is : ";
//    printStack(stk);
//    cout<<"\nAnother pop() \n";
//    stk.pop();
//    cout << "The stack is : ";
//    printStack(stk);

//    cout<<'\n'<<'\n';
//    /// queue example
//    queue <int> myqueue;
//    myqueue.push(1);
//    myqueue.push(3);
//    myqueue.push(5);
//    myqueue.push(7);
//    cout << "The queue  is : ";
//    printQueue(myqueue);
//    cout << "\nqueue.size() : " << myqueue.size();
//    cout << "\nqueue.front() : " << myqueue.front();
//    cout << "\nqueue.back() : " << myqueue.back();
//    cout << "\nqueue.pop()  \n";

//    myqueue.pop();
//    cout << "The queue  is : ";
//    printQueue(myqueue);

//    return 0;
//}
