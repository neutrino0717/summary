#include <iostream>
using namespace std; 

int main(){
    string str = "one way ticket";
    cout << str.substr(4, 3) << endl; //"way"
    cout << str <<endl;  //unchanged 
}
