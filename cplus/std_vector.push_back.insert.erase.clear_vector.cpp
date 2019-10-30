#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> primeNumbers = {2, 5, 7};
    primeNumbers.push_back(11);
    //primeNumbers is {2, 5, 7, 11}
    for(const int& i: primeNumbers) cout << i << " "; cout << endl;

    primeNumbers.insert(primeNumbers.begin() + 1, 3);
    //primeNumbers is {2, 3, 5, 7, 11}
    for(const int& i: primeNumbers) cout << i << " "; cout << endl;

    primeNumbers.erase(primeNumbers.begin() + 2);
    //primeNumbers is {2, 3, 7, 11}

    primeNumbers.insert(primeNumbers.end(), {13, 17});
    //primeNumbers is {2, 3, 7, 11, 13, 17}

    primeNumbers.erase(primeNumbers.begin(), primeNumbers.begin() + 1);
    primeNumbers.insert(primeNumbers.begin(), {2, 3, 5});
    //primeNumbers is {2, 3, 5, 7, 11, 13, 17}

    for(const int& i: primeNumbers) cout << i << " ";

    primeNumbers.clear();
    //primeNumbers is {}

}
