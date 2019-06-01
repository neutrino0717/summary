#include <iostream>
#include <array>
using namespace std;

int main(){
int n1[] { 1, 2, 3 };
int n2[] { 1, 2, 3 };
int n3[] { 3, 2, 1 };

bool equal1 = equal(begin(n1), end(n1), begin(n2));
//equal1 is 1

bool equal2 = equal(begin(n1), end(n1), begin(n3));
//equal2 is 0

array<int, 3> a1 = { 1, 2, 3 };
array<int, 3> a2 = { 1, 2, 3 };
array<int, 3> a3 = { 3, 2, 1 };

equal1 = a1 == a2;
//equal1 is 1
cout << equal1 << endl;

equal2 = a1 == a3;
//equal2 is 0
cout << equal2 << endl;

}