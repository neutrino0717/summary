//Prefix ++ operator overloading with return type
#include <iostream>
using namespace std;

class Check{
  private:
    int i;
  public:
    Check(): i(0) {  }
    Check operator ++() {
      Check temp;
      temp.i = ++i;
      return temp;
    }
    void Display()  { cout << "i=" << i << endl; }
};
int main(){
  Check obj, obj2;
  obj.Display();
  obj2 = ++obj; 
  obj.Display();
  obj2.Display();
  return 0;
}