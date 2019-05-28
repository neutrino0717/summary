#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
vector<int> numbers = {1, 2, 3, 4, 5};
vector<int> filterNumbers;
copy_if(numbers.begin(), numbers.end(),
    back_inserter(filterNumbers),
    [&](int i) { return i % 2 == 1; });
//filterNumbers is {1, 3, 5}

    for (const int& v: filterNumbers)    //best, no copy
        std::cout << v << std::endl;
}