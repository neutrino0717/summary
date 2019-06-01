#include <iostream>
#include <vector>
using namespace std;


int main(){
int n1[] {5, 7, 11};
int n2[] {2, 3};
int n3[] {13, 17};
vector<int> numbers(3);
copy(n1, n1 + 3, numbers.begin());
for (const int &u: numbers) cout << u << ";"; cout << endl;
//numbers: {5, 7, 11}

copy(n2, n2 + 2, insert_iterator<vector<int>>(
        numbers, numbers.begin()));
for (const int &u: numbers) cout << u << ";"; cout << endl;
//numbers: {2, 3, 5, 7, 11}

copy(n3, n3 + 2, back_insert_iterator<vector<int>>(numbers));
for (const int &u: numbers) cout << u << ";"; cout << endl;
//numbers: {2, 3, 5, 7, 11, 13, 17}
}