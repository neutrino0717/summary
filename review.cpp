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


int container[] = {5,10,15,20,25,30,35,40,45,50};
std::sort (container,container+10);   //5 10 15 20 25 30 35 40 45 50

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

	
//std::sort:  
//1. using default comparison (operator <):
std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33
std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)
//2. using object as comp
std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)
for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it) std::cout << ' ' << *it;

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

//typeid
auto x = 4;
auto y = 3.37;
auto ptr = &x;
cout << typeid(x).name() << endl       //i  int
     << typeid(y).name() << endl       //d  double
     << typeid(ptr).name() << endl;    //Pi point_to_int

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

std::map<std::string,std::string> mymap;
// populating container:
mymap["U.S."] = "Washington";
mymap["U.K."] = "London";
mymap["France"] = "Paris";
mymap["Russia"] = "Moscow";
mymap["China"] = "Beijing";
mymap["Germany"] = "Berlin";
mymap["Japan"] = "Tokyo";
mymap.erase ( mymap.begin() );      // erasing by iterator, china removed
mymap.erase ("Germany");            // erasing by key, germany removed
mymap.erase ( mymap.find("China"), mymap.end() ); // erasing by range, all removed

//thread
#include <thread>
static bool s_finished = false;
using namespace std::literals::chrono_literals;
void DoWork() {
    while(!s_finished){
        std::cout << "Started thread id=" << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(1s);
    }
}
int main(){
    std::thread worker(DoWork);
    std::this_thread::sleep_for(2s);
    s_finished = true;
    worker.join();
    std::cout << "Main    thread id=" << std::this_thread::get_id() << std::endl;
    std::cout << "finished!\n";
}
//Started thread id=0x60005aa20
//Started thread id=0x60005aa20
//Started thread id=0x60005aa20
//Main    thread id=0x600000010
//finished!


//Initializer list for struct
//1. need constructor
Size size(10, 11);
Point point(5, 6);
Rectangle rect(size, point);
//2. Initializer_list
Size size{10, 11};
Point point{5, 6};
Rectangle rect{size, point};
Rectangle rect = {{10, 10}, {5, 5}};

//Initializer list for array
//1. Array of Employee class by constructor
Employee employees[] {
    Employee("Anton", "Pavlov"),
    Employee("Elena", "Kirienko")
};
//2. Array of Employee class by initializer list
Employee employees2[] {
    {"Anton", "Pavlov"},
    {"Elena", "Kirienko"}
};
//3. Array of integer
int primeNumbers[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
//4. Array of string
string gameList[] { "soccer", "hockey", "basketball" };

//Initializer for map
map<int, Employee> employees {
    {1, Employee{"Anton", "Pavlov"}},
    {2, Employee{"Elena", "Kirienko"}}
};

//iostream
std::cout << "Penguin!\n";
std::cout.put('P');         //low-level I/O

//std::{regex,smatch,regex_match}
string data1 = "aaab";
string data2 = "aaaba";
regex regex("a+b");
smatch match;
bool b1 = regex_match(data1, match, regex);  //1, match the whole string
bool b2 = regex_match(data2, match, regex);  //0.
//std::{regex,smatch,regex_replace}
string data = "Pi = 3.14, exponent = 2.718, done.";
regex regex(R"(\d+\.\d+)", regex::icase);
data = regex_replace(data, regex, "<f>$0</f>"); //Pi = <f>3.14</f>, exponent = <f>2.718</f>, done.

//rand
#include <cstdlib>
#include <ctime>
srand(time(0)); //time(0) will return the current second count
for (int x = 1; x <= 7; x++) cout << 1 + (rand() % 6) << " ";  //4 5 3 6 5 1 2



//time -> time_t --localtime/gmtime----> tm -> string
time_t now = time(0);//time(0) will return the current second count
//1
tm tm = *localtime(&now);
tm *gmtm = gmtime(&now); // convert now to tm struct for UTC
//2
tm={2, 30, 22, 17, 7-1, 1975-1900};
int year = tm.tm_year + 1900;
int month = tm.tm_mon + 1;
int day = tm.tm_mday;
int hour = tm.tm_hour;
int minute = tm.tm_min;
int second = tm.tm_sec;
int dayOfWeek = tm.tm_wday;
cout << year << ":" << month  << ":" << day << ":" << hour << ":" << minute << ":" << second << endl;
//2019:8:25:22:21:26
//1975:7:17:22:30:2

//time -> time_t --ctime--------> string 
#include <ctime>
time_t now = time(0);  //1566743108
cout << now << endl;
char* dt = ctime(&now); // convert now to string form
cout << "The local date and time is: " << dt << endl;//Sun Aug 25 22:25:08 2019
tm *gmtm = gmtime(&now); // convert now to tm struct for UTC
dt = asctime(gmtm);
cout << "The UTC date and time is:"<< dt << endl; //Sun Aug 25 14:25:08 2019

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

/*
#include <fstream>
fstream library contains three classes:
  ofstream: Output file stream that creates and writes information to files.
  ifstream: Input file stream that reads information from files.
   fstream:  General file stream, with both ofstream and ifstream capabilities that allow it to create, read, and write information to files.
*/
ofstream outfile;
outfile.open("file.dat", ios::out | ios::trunc );
ofstream MyFile1("/tmp/test.txt");

MyFile1 << "This is awesome! \n";
MyFile1.close();

ifstream MyFile("/tmp/test.txt");
string line; 
while ( getline (MyFile, line) ) cout << line << '\n';   //This is awesome!
MyFile.close();

{
    std::ofstream ostrm("/tmp/Test.b", std::ios::binary);
    double d = 3.14;
    ostrm.write(reinterpret_cast<char*>(&d), sizeof d); // binary output
    ostrm << 123 << "abc" << '\n';                      // text output
}
// read back
std::ifstream istrm("/tmp/Test.b", std::ios::binary);
double d;
istrm.read(reinterpret_cast<char*>(&d), sizeof d);
int n;
std::string s;
istrm >> n >> s;
std::cout << " read back: " << d << " " << n << " " << s << '\n'; //read back: 3.14 123 abc


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

