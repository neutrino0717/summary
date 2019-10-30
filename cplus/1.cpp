#include <iostream> 
#include <algorithm>
#include <string>
using namespace std; 

  
// C++ program to demonstrate working of auto and type inference 
int main() 
{ 
    string str = "Hello everyone bye bye";
    //str.erase(remove(str.begin(),   str.end(), ' '),    str.end());
    str.erase(find(str.begin(),   str.end(), ' '));
 
    cout << str <<'\n';
    return 0; 
} 
