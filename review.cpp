#include <algorithm>
#include <array>        // std::array
#include <bitset>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <thread>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;


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



/*
 * unique smart pointer
 */
//bad way
Dog* dg = new Dog("KeJi");
delete dg;
//use unique pointer
{
unique_ptr<Dog> dg2(new Dog("ErHa"));
}
//return the raw point, and dg3 release the ownereship. dog will not be deleted
unique_ptr<Dog> dg3(new Dog());
Dog* p = dg3.release();
if(!dg3){cout << "dg3 is empty\n";} //dg->bark();
//reset to another dog
{
unique_ptr<Dog> dg4(new Dog("LaPuLaDuo"));
dg4.reset(new Dog("JinMao"));//dog is destroyed: LaPuLaDuo
if(!dg4){cout << "dg4 is empty\n";}else{cout << "dg4 is not empty\n";}  //dg4 is not empty
}                                                                       //dog is destroyed: JinMao
//reset without any parameters\n";
{
unique_ptr<Dog> dg5(new Dog("Fadou"));
//dg5 = nullptr; //or
dg5.reset(); //dog is destroyed: Fadou
if(!dg5){cout << "dg5 is empty\n";}else{cout << "dg5 is not empty\n";}  //dg5 is empty
}
//transfer ownership to another unique ptr with move
{
unique_ptr<Dog> dg6(new Dog("SaMoYe"));
unique_ptr<Dog> dg7(new Dog("ZangAo"));
dg7 = move(dg6);//1. ZangAo destoryed
                //2. dg6 becomes empty
                //3. dg7 owns SaMoYe 
}
void f(unique_ptr<Dog> p){ p->bark(); }
cout << "\n:function parametor\n";
unique_ptr<Dog> dg8(new Dog("Tianyuan"));
f(move(dg8)); //Dog Tianyuan rules!
              //dog is destroyed: Tianyuan
              
//direct and copy initialization
//basically the two are the same, however if "explicit" is used in constr, the  2nd is not ok
C c1(7)       //direct-initialization 
C c2 = 7     // called copy-initialization
 30 35 40 45 50

//vector initialization
//1
std::vector<int> myvector = {32,71,12,45,26,80,53,33};
//2
int myints[] = {32,71,12,45,26,80,53,33};
std::vector<int> myvector (myints, myints+8);
//vector initialization
std::vector<std::string> words1 {"the", "frogurt", "is", "also", "cursed"};
std::vector<std::string> words2(words1.begin(), words1.end());     // words2 == words1 
std::vector<std::string> words3(words1);      //words3 == words1
std::vector<std::string> words4(5, "Mo");     //{"Mo", "Mo", "Mo", "Mo", "Mo"}
std::string mystrs[] = {"the", "frogurt", "is", "also", "cursed"};
std::vector<std::string> words5(mystrs, mystrs+5);
//vector move and copy
std::vector<int> nums1 {3, 1, 4, 6, 5, 9};
std::vector<int> nums2; 
std::vector<int> nums3;
nums2 = nums1;    // copy assignment copies data from nums1 to nums2
nums3 = std::move(nums1); //move assignment moves data from nums1 to nums3,
//now nums1 empty; nums2=nums3


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

//decltype
int fun1() { return 10; }
char fun2() { return 'g'; }
decltype(fun1()) x;//Data type of x is same as return type of fun1()
decltype(fun2()) y;
cout << typeid(x).name() << endl;   //i   int
cout << typeid(y).name() << endl;   //c   char

    return 0;


//Micro
#define MIN(a,b) (a<b ? a : b)
cout <<"The Minimum number is " << MIN(x, y) << endl;



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


#include <sstream>
// istringstream is for input, 
// ostringstream for output. 
//  stringstream is input and output. You can use stringstream pretty much everywhere.
std::string str = "true";
bool boolValue;
std::istringstream(str) >> std::boolalpha >> boolValue;
std::cout << boolValue << std::endl;   //1

stringstream ss;
ss << "hex of 89 is: " << hex << 89 << ". oct of 89 is: " << oct << 89;
    cout << ss.str() << endl; //hex of 89 is: 59. oct of 89 is: 131

string str = "1 2 3 4 5";
stringstream stream(str);
int numbers[5];
copy(istream_iterator<int, char>(stream),
     istream_iterator<int, char>(),
     numbers); //numbers in {1, 2, 3, 4, 5}

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

//////////const ////////////////////////////
//if const is on the left of *, data is const
int const *p = &i;
const int *p = &i;
//if const is on the right of *, pointer is const
int* const p;

//cast is bad, avoid them as much as possible
const int i = 9; 
i = 6; //compile error
const_cast<int&>(i) = 6  //const_cast cast away the constness of i 
int j;
static_cast<const int&>(j) = 7 //cast data into a const, throw error

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
