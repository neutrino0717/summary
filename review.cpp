//bilatoral mapping
enum Season { Summer, Fall, Winter, Spring };
string arSeason[] = {"Summer", "Fall", "Winter", "Spring"};  //enum --> String  
map<string, Season> seasons = {                              //String --> enum
    {"Summer", Summer},
    {"Fall", Fall},
    {"Winter", Winter},
    {"Spring", Spring}
};
cout <<Winter << " " << arSeason[Winter] << endl;
cout <<"Winter" << " " << seasons["Winter"] << endl;
cout << (Winter==Season(2)) << endl;


//call constr 3 times
map<int, C> m;
m[7] = C(1);
	//m[7] call def constructor
	//C(1) call defined constructor
	//= call assign constructor

//this: three ways
class MyClass {
    public:
        MyClass(int a) : var(a){ }
        void printInfo() {
            cout <<         var <<endl;
            cout <<   this->var <<endl;
            cout << (*this).var <<endl;
        }
    private:
        int var;
};

//use reference to avouid new object
A a[2];              //call def constr
for (auto  x : a) { }//call copy constr
for (auto& x : a) { }//no new object

//c type array
int aaa[5];
int arr[] = {11, 35, 62, 555, 989};
int arr[5] = {11, 35, 62, 555, 989};
int x[2][3] = {{2, 3, 4}, {8, 9, 10}};
//c type array as function parameters
void printArray(int arr[], int size) {
    for(int x=0; x<size; x++) { cout <<arr[x]<< endl; }
}
int main() {
    int myArr[3]= {42, 33, 88};
    printArray(myArr, 3);  //42 33 88
}

//name space
namespace first { void func(){ cout << "Inside the first namespace" << endl; } }
namespace second{ void func(){ cout << "Inside the second namespace" << endl;} }
using namespace first;
int main () { func(); return 0; } //    // This calls function from first name space.


//rvalue ref
void prt(int   i){ std::cout << "value " << i << std::endl; }
void prt(int&  i){ std::cout << "lvalue ref " << i << std::endl; }
void prt(int&& i){ std::cout << "rvalue ref " << i << std::endl; }
int main() {
    int a = 5;  //a is lvalue
    int& b = a; //b is lvalue ref
    int&& c ;   //c is rvalue ref
    prt(3);      //prt(int i) or prt(int&& i)
    prt(a);      //prt(int i) or prt(int&  i)
    prt(b);      //prt(int i) or prt(int&  i)
}

//NULL
int *ptr = NULL;
cout << "The value of ptr is " << ptr ;  //0

//extern
extern "C" int x; //is just a declaration 
extern "C" { int y; } //is a definition

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
//basically the two are the same, however if explicit is used in constr, the  2nd is not ok
C c1(7)       //direct-initialization 
C c2 = 7     // called copy-initialization


//map::find
map<int, string>  dic = { {1, "one"}, {2, "two"} };
bool exists1 = dic.find(1) != dic.end();// 1

//set.find
//std::includes
set<char> chars { 'A', 'B', 'C', 'D' };   //must be sorted before std::includes
set<char> chars2 { 'A', 'C' };            //must be sorted before std::includes
cout << (chars.find('A') != chars.end()) << endl;  //1
cout << (chars.find('E') != chars.end()) << endl;  //0
bool containAll = includes( chars.begin(), chars.end(), chars2.begin(), chars2.end());   //1

int container[] = {5,10,15,20,25,30,35,40,45,50};
std::sort (container,container+10);   //5 10 15 20 25 30 35 40 45 50

//vector initialization
//1
std::vector<int> myvector = {32,71,12,45,26,80,53,33};
//2
int myints[] = {32,71,12,45,26,80,53,33};
std::vector<int> myvector (myints, myints+8);

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

//enum
enum Season {
    Summer, Fall, Winter, Spring
};
enum Season2: char {
    Summer2, Fall2, Winter2, Spring2
};
Season winter = Winter;
int baseValue = winter;           //2
std::cout <<  Fall << std::endl;  //1
std::cout << Fall2 << std::endl;  //1

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

//std::transform
string str = "Lower and upper";
std::transform(str.begin(), str.end(), str.begin(), ::tolower); //::tolower global namespace, which is tolower of C lauguage. str is "lower and upper"
std::transform(str.begin(), str.end(), str.begin(), ::toupper); //str is "LOWER AND UPPER"

//std::set.{insert,erase,clear}
set<char> set{ 'A', 'B', 'C' };
set.insert('D'); //{ 'A', 'B', 'C', 'D' }
set.erase('A');  //{ 'B', 'C', 'D' }
for(const char &c: set) cout << c << ";"; //B;C;D;
set.clear();     //{ }

//std::{set_union,intersection,set_difference,equal}
set<int> first  { 1, 2, 3 };
set<int> second { 3, 4, 5 };
set<int> third;
insert_iterator<set<int>> iterator(third, third.begin());
set_union       (first.begin(), first.end(), second.begin(), second.end(), iterator );  //third is { 1, 2, 3, 4, 5 }
set_intersection(first.begin(), first.end(), second.begin(), second.end(), iterator);   //third is { 3 }
vector <int> vthird;
set_intersection(first.begin(), first.end(), second.begin(), second.end(), back_inserter(vthird)); //third is { 3 }
set_difference  (first.begin(), first.end(), second.begin(), second.end(), iterator);              //third is { 1, 2 }
equal           (first.begin(), first.end(), second.begin(),second.end());

//std::string.substr
string str = "one way ticket";
str.substr(4, 3)     //return "way"`,  str unchanged

//std::string.{erase,find}
std::string s = "This is an example";
s.erase(0, 5);                               //erase 0~5, s = "is an example",
s.erase(s.find(' '));                        //erase 4~ , s = "This",             //s.find(' ') return 4
s.erase(std::find(s.begin(), s.end(), ' ')); //erase 4~5, s = "Thisis an example" //std::find() return InputIt

//std::{remove_if,remove,find}
string str = "Hello everyone bye bye";
          remove_if(str.begin(), str.end(), isspace)
/*str = "Helloeveryonebyebye   "
                           ^    */
str.erase(remove_if(str.begin(), str.end(), isspace), str.end()); //str = Helloeveryonebyebye"
str.erase(remove(   str.begin(), str.end(), ' '),     str.end()); //str = Helloeveryonebyebye"
str.erase(find(s    tr.begin(),  str.end(), ' '));                //str = Helloeveryone bye bye

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

struct Person{ string name; int age; } p;
tuple<string, int> t;
p.name;
p.age;
get<0>(t);
get<1>(t);

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

//set: auto sort
#include <set>
#include <unordered_set>
set<int>           chars{'B', 'A', 'C', 'D'};
unordered_set<int> char2{'B', 'A', 'C', 'D'};
for (int c:chars) cout << c << ",";//65,66,67,68,
for (int c:chars) cout << string(1,c) << ";"; //A;B;C;D;
for (int c:char2) cout << c << ":";//68:67:65:66:
