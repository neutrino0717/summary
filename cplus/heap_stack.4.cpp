#include <iostream>
using namespace std;

int main()
{
    int *p = new int; // request memory
    *p = 5; // store value

    cout << *p << endl; 
    cout << "heap: " << p << endl; 
    cout << "stack: " << &p << endl; 

    delete p; // free up the memory

    int *pp = NULL; // Pointer initialized with null
    pp = new int[20]; // Request memory
    cout << "heap: " << pp << endl; 
    cout << "stack: " << &pp << endl; 

    delete [] pp; // Delete array pointed to by p

    return 0;
}

