#include <iostream>
#include <set>
using namespace std;

int main(){
    int numbers[]= { 1, 3, 2, 1, 3 };
    //int numbers[] { 1, 3, 2, 1, 3 };
    set<int> unique;
    unique.insert(numbers, numbers + 5);
//unique is {1, 2, 3}

    for (const int& u: unique)    //best, no copy
        std::cout << u << std::endl;
}
