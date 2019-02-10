#include <iostream>
#include <string>
#include <pp.h>
class Entity {
private:
    int m_x, m_y;
    int* m_a,*m_b;
    mutable int var;     //mutable can be changed in const functions
public:
    int getx() const  // getx() cannot change the class member
    {                 // always mark method as const if it's a get
        //m_x = 2;    //wrong
        var = 2;      //mutable can be changed in 'getx() const'
        return m_x;
    }
    void setx(int x)// const should not be const
    {
        m_x = 2;
    }
};

//5. const to prevent change,  ref to save from copy
void PrintEntity1(const Entity& e){
    std::cout << e.getx() <<std::endl; //define 'in getx() const' is a must
    //e = nullptr;   //wrong, cannot change const Entity object
}
//6. const to prevent change Entity, but OK to change the pointer variable itself
void PrintEntity2(const Entity* e){
    std::cout << e->getx() <<std::endl;
    e = nullptr;   //OK,  change the pointer variable itself
}

int main() {
    const int MAX_AGE = 90;
    int* a = new int;
   *a = 2;
   //1. error: invalid conversion from ‘const int*’ to ‘int*’
   //a = &MAX_AGE;
    a = (int*)&MAX_AGE; //here we break the const promise

    //2. '* b' store 'const int', cannot be changed
    const int* b = new int;
    int const* c = new int; //same as above

    //3. 'd' store const value, cannot be changed
    int* const d = new int;

    //4. cannot change both
    const int* const e = new int;
 //*b = 2;               //error: assignment of read-only location ‘* b’
    b = (int*)&MAX_AGE;     //OK
    c = nullptr;            //OK, same as above
   *d = 2;                 //OK
  //d = nullptr;           //error: assignment of read-only variable ‘d’ 
    std::cout << "no output, check the code please\n";
}
