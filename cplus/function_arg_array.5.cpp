#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for(int x=0; x<size; x++) cout <<arr[x] << " "; cout << endl; 
}

int main() {
    int myArr[3]= {42, 33, 88};
    printArray(myArr, 3);
}
