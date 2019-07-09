#include <iostream>
#include <set>
#include <algorithm>
using namespace std; 

int main(){
    set<char> chars { 'A', 'B', 'C', 'D' };
    cout << (chars.find('A') != chars.end()) << endl;
    cout << (chars.find('E') != chars.end()) << endl;

    set<char> chars2 { 'A', 'B' };
    bool containAll = includes( chars.begin(), chars.end(), chars2.begin(), chars2.end());
    cout << containAll << endl;
}
