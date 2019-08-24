#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main()
{
    set<int> chars{'B', 'A', 'C', 'D'};
    string str = "";
    for (int c:chars) cout << c << ","; cout << endl;
    for (int c:chars) cout << string(1,c) << ";"; cout << endl;

    unordered_set<int> chars2 {'B', 'A', 'C', 'D'};
    for (int c:chars2) cout << c << ":"; cout << endl;
} 
