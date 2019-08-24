#include <iostream>
using namespace std;

// C++ program to demonstrate use of decltype
int fun1() { return 10; }
char fun2() { return 'g'; }

int main()
{
    // Data type of x is same as return type of fun1()
    // and type of y is same as return type of fun2()
    decltype(fun1()) x;
    decltype(fun2()) y;

    cout << typeid(x).name() << endl;   //i   int
    cout << typeid(y).name() << endl;   //c   char

    return 0;
}
