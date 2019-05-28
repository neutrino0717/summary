#include <iostream>
#include <vector>
using namespace std;
int main(){
vector<int> vNumbers = {11, 2, 5, 7, 3};
sort(vNumbers.begin(), vNumbers.end());
//vNumbers is { 2, 3, 5, 7, 11 }
for (const int &u:vNumbers) cout << u << ";";

sort(vNumbers.begin(), vNumbers.end(),
    [&](int a, int b) { return a > b; });
//vNumbers is { 11, 7, 5, 3, 2 }
for (const int &u:vNumbers) cout << u << ";";

int aNumbers[] = {11, 2, 5, 7, 3};
sort(aNumbers, aNumbers + 5);
//aNumbers is { 2, 3, 5, 7, 11 }
for (const int &u:aNumbers) cout << u << ";";
}