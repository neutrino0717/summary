//
// Created by Evan on 2019/02/03.
//

#include <iostream>

using namespace std;

int global_Var = 42;

// function to change pointer value
void changePointerValue(int* pp){
    pp = &global_Var;
}

void changePointerValue(int** ptr_ptr){
    *ptr_ptr = &global_Var;
}

void changeReferenceValue(int*& pp)
{
    pp = &global_Var;
}
int main()
{
    int var = 23;
    int* ptr_to_var = &var;

    cout << "Before :" << *ptr_to_var << endl; // display 23

    changePointerValue(ptr_to_var);
    cout << "After :" << *ptr_to_var << endl; // display 23

    changePointerValue(&ptr_to_var);
    cout << "After :" << *ptr_to_var << endl; // display 42

    ptr_to_var = &var;
    changeReferenceValue(ptr_to_var);
    cout << "After :" << *ptr_to_var << endl; // display 42

    return 0;
}

