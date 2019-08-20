#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    set<int> first  { 1, 2 };
    set<int> second = { 1, 2 };
    set<int> third = { 1, 2, 3 };

    bool isEqual = first.size() == second.size() && equal(first.begin(), first.end(), second.begin());
    cout << isEqual << endl; //isEqual is 1

    //or
    cout << equal(first.begin(), first.end(), third.begin(),third.end()) << endl;

    //or
    vector<int> intersect;
    set_intersection( first.begin(), first.end(), third.begin(), third.end(), back_inserter(intersect));
    bool isIntersects = intersect.size() > 0;
    cout << isIntersects << endl; //isIntersects is 1

    bool isThirdSubsetOfFirst = includes( first.begin(), first.end(), third.begin(), third.end());
    cout << isThirdSubsetOfFirst << endl; //isThirdSubsetOfFirst is 0

}
