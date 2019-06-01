#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main()
{
	set < int >chars{'B', 'A', 'C', 'D'};
	string str = "";
    for (int c:chars) cout << c << ",";
    for (int c:chars) cout << string(1,c) << ";";
    unordered_set<int> chars2 {'B', 'A', 'C', 'D'};
    for (int c:chars2) cout << c << ":";
} 