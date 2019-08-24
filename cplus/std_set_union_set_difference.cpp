#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    set<int> first { 1, 2, 3 };
    set<int> second { 3, 4, 5 }; 

    set<int> third;
    vector <int> vthird;
    insert_iterator<set<int>> iterator(third, third.begin());

    set_union( first.begin(), first.end(), second.begin(), second.end(),iterator);
    //third is { 1, 2, 3, 4, 5 }
    for(const int &i: third) cout << i << ";"; cout <<endl;
    third.clear();

    set_intersection( first.begin(), first.end(), second.begin(), second.end(),iterator);
    //third is { 3 }
    for(const int &i: third) cout << i << ";"; cout <<endl;
    third.clear();

    //or
    set_intersection( first.begin(), first.end(), second.begin(), second.end(),back_inserter(vthird));
    for(const int &i: vthird) cout << i << ";"; cout <<endl;

    set_difference( first.begin(), first.end(), second.begin(), second.end(),iterator);
    for(const int &i: third) cout << i << ";"; cout <<endl;
    //third is { 1, 2 }
}
