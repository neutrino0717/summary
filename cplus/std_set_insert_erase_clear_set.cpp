#include <iostream>
#include <set>
using namespace std;

int main(){
    set<char> set { 'A', 'B', 'C' };
    set.insert('D'); //{ 'A', 'B', 'C', 'D' }
    set.erase('A'); // { 'B', 'C', 'D' }
    for(const char &c: set) cout << c << ";";
    set.clear(); //{ }
}
