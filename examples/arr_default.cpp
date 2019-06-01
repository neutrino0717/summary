#include <iostream>
using namespace std;

int main() {
int value = 5;
const int count = 3;
//if your compiler is GCC
int array[3] =  {[0 ... count-1] = value};
//array is [5, 5, 5]
	
for (const int &u: array) cout << u << ";";
}

