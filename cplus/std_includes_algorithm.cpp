#include <iostream>
#include <set>
#include <algorithm>
using namespace std; 

int main(){
    set<char> chars { 'A', 'B', 'C', 'D' }; 
    cout << (chars.find('A') != chars.end()) << endl;  //1
    cout << (chars.find('E') != chars.end()) << endl;  //1

    set<char> chars2 { 'A', 'C' };
    bool containAll = includes( chars.begin(), chars.end(), chars2.begin(), chars2.end()); 
    cout << containAll << endl; //1
}