#include <iostream> 
using namespace std; 
  
// C++ program to demonstrate working of auto and type inference 
int main() 
{ 
    auto x = 4; 
    auto y = 3.37; 
    auto ptr = &x; 
    cout << typeid(x).name() << endl 
         << typeid(y).name() << endl 
         << typeid(ptr).name() << endl; 
  
    return 0; 
} 
