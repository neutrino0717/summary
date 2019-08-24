using namespace std;
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

int main(){}

