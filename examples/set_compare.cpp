#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
set<int> first  { 1, 2 };
set<int> second = { 1, 2 };
set<int> third = { 1, 2, 3 };

bool isEqual =
first.size() == second.size() &&
equal(first.begin(), first.end(), second.begin());
//isEqual is 1
cout << isEqual;

//or
cout << equal(first.begin(), first.end(), third.begin(),third.end());

//or
vector<int> intersect;
set_intersection(
    first.begin(), first.end(),
    third.begin(), third.end(),
    back_inserter(intersect));
bool isIntersects = intersect.size() > 0;
//isIntersects is 1
cout << isIntersects;

bool isThirdSubsetOfFirst = includes(
    first.begin(), first.end(),
    third.begin(), third.end());
    cout << isThirdSubsetOfFirst;
//isThirdSubsetOfFirst is 0

}