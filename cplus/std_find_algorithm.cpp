#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    vector<int> numbers {2, 3, 5, 7, 11, 13, 17};
    bool contain5 = find(numbers.begin(), numbers.end(), 5) != numbers.end();
    //contain5 is 1
    cout << contain5 <<endl;

    bool contain10 = find(numbers.begin(), numbers.end(), 10) != numbers.end();
    //contain10 is 0
    cout << contain10 <<endl;
}
