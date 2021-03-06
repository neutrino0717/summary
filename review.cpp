
//rvalue reference have two usages:
//1. moving semantics
//2. perfect forwarding
class boVector {   //1.
    int size;
    double* arr_;
  public:
    boVector(const boVector& rhs){ //copy constructor
      size = rhs.size;
      arr_ = new double[size];
      for (int i=0; i<size; i++) { arr_[i] = rhs.arr_[i];}
    }
    ~boVector() { delete arr_; }
};
boVector reusable = createBovector();
foo(reusable);        //copy constructor, OK if reusable need to be untouched
                                       //bad if reusable not needed any more
foo(std::move(reusable));//move           OK if reusable not needed any more
foo(createBoVecotr()) //copy constructor, bad, why copy?
class boVector::boVector(boVector&& rhs){ //now, add move constructor
  size = rhs.size;
  arr_ = rhs.arr_;
  rhs.arr_ = nullptr;

}
foo(createBoVecotr()) //move constructor called now, OK

//rvalue reference is used for two things
//1. Moving Semantics
//2. Perfect Forwarding


              
//direct and copy initialization
//basically the two are the same, however if "explicit" is used in constr, the  2nd is not ok
C c1(7)       //direct-initialization 
C c2 = 7     // called copy-initialization
 30 35 40 45 50



//Prefix ++ operator overloading with return type    | //postfix ++ operator overloading: int inside barcket(int)
class Check{                                           class Check{
  private:                                               private:
    int i;                                                 int i;
  public:                                                public:
    Check(): i(0) {  }                                     Check(): i(0) {  }
    Check operator ++() {                            |     Check operator ++ (int){
      Check temp;                                            Check temp;
      temp.i = ++i;                                  |       temp.i = i++;
      return temp;                                           return temp;
    }                                                      }
    void Display()  { cout << "i=" << i << endl; }         void Display()  { cout << "i=" << i << endl; }
};                                                     };
int main(){                                            int main(){
  Check obj, obj2;                                       Check obj, obj2;
  obj.Display();                                         obj.Display();   //0 0
  obj2 = ++obj;                                      |   obj2 = obj++;
  obj.Display();                                         obj.Display();   //1 1
  obj2.Display();                                        obj2.Display();  //1 0
  return 0;                                              return 0;
}                                                      }


//Prefix ++ operator overloading with return type    | //Prefix ++ operator overloading without return type
#include <iostream>                                    #include <iostream>
using namespace std;                                   using namespace std;

class Check{                                           class Check{
  private:                                               private:
    int i;                                                 int i;
  public:                                                public:
    Check(): i(0) {  }                                     Check(): i(0) {  }
    Check operator ++() {                            |     void operator ++() {
      Check temp;                                    |       ++i;
      temp.i = ++i;                                  <
      return temp;                                   <
    }                                                      }
    void Display()  { cout << "i=" << i << endl; }         void Display()  { cout << "i=" << i << endl; }
};                                                     };
int main(){                                            int main(){
  Check obj, obj2;                                   |   Check obj;
  obj.Display();                                         obj.Display();  //0 0
  obj2 = ++obj;                                      |   ++obj;
  obj.Display();                                         obj.Display();  //1 1
  obj2.Display();                                    <                   //1
  return 0;                                              return 0;
}                                                      }





///////////constructions /////////////////////////
class Dog{};
/* C++ 03:
 * 1. default constructor      (generated only if no constructor is declared by user)
 * 2. copy constructor         (generated only if no (5|6) declared by user)
 * 3. copy assignment operator (generated only if no (5|6) declared by user)
 * 4. destructor
 *
 * c++ 11:
 * 5. move constructor         (generated only if no (2|3|4|6) declared by user)
 * 6. move assinment operator  (generated only if no (2|3|5|6) declared by user)
 */
class Cat{ //3, 4
  Cat(const Cat&){} //copy constructor
};
class Duck{ //4
  Duck(Duck&&){}    //move constructor
};
class Frog{ //4
  Frog(Frog&&, int = 0) {} //move constructor
  Frog(int = 0){}          //default constructor
  Frog(const Frog&,int=0) {} //copy constructor
};
class Fish{ //1, 2, 3
  ~Fish(){}
};
class Cow{ //1, 2, 4
  Cow& operator=(const Cow&) = delete;
};


//unique_ptr
{ 
    std::unique_ptr<Entity> e2(new Entity());
    std::unique_ptr<Entity> e2 = std::make_unique<Entity>(); //preferred way
}
//shared_ptr 1: after exit block, no more reference to sharedEntity, sharedEntity destroyed
std::shared_ptr<Entity> e1;
{
    std::shared_ptr<Entity> e2 = std::make_shared<Entity>();
}
//shared_ptr 2: after exit block, still has one reference to sharedEntity, sharedEntity not destoryed
std::shared_ptr<Entity> e1;
{
    std::shared_ptr<Entity> e2 = std::make_shared<Entity>();
    e1 = e2;
}
//weak_ptr: one weak reference to sharedEntity, which is destroyed
std::weak_ptr<Entity> e1;
{//https://www.geeksforgeeks.org/auto_ptr-unique_ptr-shared_ptr-weak_ptr-2/
    std::shared_ptr<Entity> e2 = std::make_shared<Entity>();
    e1 = sharedEntity;
}


//const used with functions
class Dog {
	int age;
	string name;
	//what is const parameter
	void setAge(const int& a){age = a}    //prevent setAge from changing reference a
    void setAge(const int  a){age = a}    //this const is useless
    //what is const return value
	const string& getName(){return name;} //prevent caller from changing reference name
    const string  getName(){return name;} //this const is useless
    //what is const function
    void printDog() const { ... }         //prevent printDog from changing Dog member variables and can only call another const function
    void printDog()       { ... }         //will be invoked when Dog is not a const.
}
Dog d1;
const string &n = d1.getName(); //the caller 
d1.printDog();   //will invoke void printDog() {}
const Dog d2;
d2.printDog();   //will invoke void printDog() const{}
//mutable
class BigArray {
	vector<int> v;
	mutable int accessCounter; //logically it should should be able to be changed
public:
    int getItem(int index) const {//only v should not be changed by this function
		accessCounter++;
		//const_cast<BigArray*>(this)->accessCounter++ //use this instead in case accessCounter is not mutable
		return v[index];
	}		
};
