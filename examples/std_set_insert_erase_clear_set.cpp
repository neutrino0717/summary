#include <iostream>
#include <set>
using namespace std;

int main(){
set<char> set { 'A', 'B', 'C' };
set.insert('D');
//set is { 'A', 'B', 'C', 'D' }

set.erase('A');
//set is { 'B', 'C', 'D' }
for(const char &c: set) cout << c << ";";
set.clear();
//set is { }
}