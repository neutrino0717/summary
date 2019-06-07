#include <iostream>
using namespace std;

int main()
{
    int *p = new int; // request memory
    *p = 5; // store value

    cout << *p << endl; // use value
    cout << "heap: " << p << endl; // use value
    cout << "stack: " << &p << endl; // use value

    delete p; // free up the memory

    int *pp = NULL; // Pointer initialized with null
    pp = new int[20]; // Request memory
    cout << "heap: " << pp << endl; // use value
    cout << "stack: " << &pp << endl; // use value

    delete [] pp; // Delete array pointed to by p

    return 0;
}

