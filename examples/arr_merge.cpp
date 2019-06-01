#include <iostream>
#include <vector>
#include <list>
using namespace std; 

int main(){
vector<int> firstNumbers { 2, 3, 5 };
vector<int> secondNumbers { 7, 11, 13 };
vector<int> allNumbers;
allNumbers.insert(allNumbers.end(),
    firstNumbers.begin(), firstNumbers.end());
allNumbers.insert(allNumbers.end(),
    secondNumbers.begin(), secondNumbers.end());
//allNumbers is { 2, 3, 5, 7, 11, 13 }
for(int &i: allNumbers) cout << i << endl;
list<string> list1 {"one"};
list<string> list2 {"two", "three"};
list1.merge(list2);
//list1 is {"one", "two", "three"}
//list2 is {}
for(string &i: list1) cout << i <<" "; cout << endl;
for(string &i: list2) cout << i <<" "; cout << endl;
}