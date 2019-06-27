#include <iostream>
#include <string>

class Entity {
private:
    int m_x, m_y;
    int* m_a,*m_b;
    mutable int var;     //mutable can be changed in const fuctions
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

void PrintEntity1(const Entity& e){ //a const to prevent change,  ref to save from copy
    std::cout << e.getx() <<std::endl; //define 'in getx() const' is a must
    //e = nullptr;   //wrong, cannot change const Entity object
}

void PrintEntity2(const Entity* e){ //a const to prevent change Entity
    std::cout << e->getx() <<std::endl;
    e = nullptr;   //OK, change the pointer variable itself
}

int main() {
    const int MAX_AGE = 90;
    int* a = new int;
   *a = 2;
  //a = &MAX_AGE;     //error: invalid conversion from ‘const int*’ to ‘int*’
    a = (int*)&MAX_AGE; //here we break the const promise

    const int* b = new int; //'* b' store 'const int', cannot be changed
    int const* c = new int; //same as above
    int* const d = new int; // 'd' store const value, cannot be changed
    const int* const e = new int; //cannot change both
 //*b = 2;               //error: assignment of read-only location ‘* b’
    b = (int*)&MAX_AGE;     //OK
    c = nullptr;            //OK, same as above
   *d = 2;                 //OK
  //d = nullptr;           //error: assignment of read-only variable ‘d’ 
    std::cout << "no output, theck the code please\n";

    const int i = 9;
    //i = 6;
    const_cast<int&>(i) = 6; //cast out the constness
    int j;
    //static_cast<const int&>(j) = 7; //error: assignment of read-only location ‘j’



}
