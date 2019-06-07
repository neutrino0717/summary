//
// Created by Evan on 2019/02/03.
//


// C++ code to demonstrate forward list
// and assign()
#include<iostream>
#include<forward_list>
#include "pp.h"
using namespace std;

int main()
{
    pp("1. assign()");
    forward_list<int> flist1; // Declaring forward list
    flist1.assign({1, 2, 3}); // Assigning values using assign()
    for (int&a : flist1) cout << a << " "; cout << endl;         //1 2 3

    forward_list<int> flist2; // Declaring another forward list  
    flist2.assign(5, 10);     // Assigning repeating values using assign(), 5 elements with value 10
    for (int&b : flist2) cout << b << " "; cout << endl;         //10 10 10 10 10


    pp("2. push_front(), 3.emplace_front(), 4. pop_front()");
    forward_list<int> flist = {10, 20, 30, 40, 50}; // Initializing forward list
    flist.push_front(60);                           // Inserting value using push_front() Inserts 60 at front
    for (int&c : flist) cout << c << " "; cout << endl;       //60 10 20 30 40 50

    flist.emplace_front(70); // Inserting value using emplace_front() Inserts 70 at front
    for (int&c : flist) cout << c << " "; cout << endl;       //70 60 10 20 30 40 50

    flist.pop_front(); // Deleting first value using pop_front(),  pops 70
    for (int&c : flist) cout << c << " "; cout << endl;       //60 10 20 30 40 50

    pp("4. insert_after(),5. emplace_after(),6. erase_after()");
    forward_list<int> flist3 = {10, 20, 30} ; // Initializing forward list 
    forward_list<int>::iterator ptr; // Declaring a forward list iterator
    ptr =  flist3.insert_after(flist3.begin(), {1, 2, 3});
    for (int&c : flist3) cout << c << " "; cout << endl;      //10 1 2 3 20 30

    ptr = flist3.emplace_after(ptr,2);
    for (int&c : flist3) cout << c << " "; cout << endl;      //10 1 2 3 2 20 30

    ptr = flist3.erase_after(ptr);
    for (int&c : flist3) cout << c << " "; cout << endl;      //10 1 2 3 2 30


    pp("5. remove_if()");
    forward_list<int> flist5 = {10, 20, 30, 25, 40, 40};
    flist5.remove(40);// Removes all occurrences of 40
    for (int&c : flist5) cout << c << " "; cout << endl;      //10 20 30 25 

    flist5.remove_if([](int x){ return x>20;}); // Removes elements greater than 20
    for (int&c : flist5) cout << c << " "; cout << endl;      //10 20 


    pp("splice_after()");
    forward_list<int> flist11 = {10, 20, 30};
    forward_list<int> flist12 = {40, 50, 60};
    // Shifting elements from first to second
    // forward list after 1st position
    flist12.splice_after(flist12.begin(),flist11);

    // Displaying the forward list
    for (int&c : flist12) cout << c << " "; cout << endl;    //40 10 20 30 50 60


    return 0;

}
