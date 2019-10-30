#include <iostream>
#include <memory>
using namespace std;

class Dog{
  public:
    string m_name;
    void bark() { cout << "Dog " << m_name << " rules!" << endl; }
    Dog(){ cout <<"Nameless dog created"<< endl; m_name = "Nameless"; }
    Dog(string name){ cout << "Named dog created" << endl; m_name = name; }
    ~Dog(){ cout << "dog is destroyed: " << m_name << endl; }
};

void f(unique_ptr<Dog> p){
  p->bark();
}

int main(){
  cout << "\n:bad way\n";
  Dog* dg = new Dog("KeJi");
  dg->bark();
  delete dg;

  {
  cout << "\n:use unique pointer\n";
  unique_ptr<Dog> dg2(new Dog("ErHa"));
  dg2->bark();
  }

  cout << "\n:return the raw point, and dg3 release the ownereship, dog will not be deleted\n";
  unique_ptr<Dog> dg3(new Dog());
  dg3->bark();
  Dog* p = dg3.release();
  if(!dg3){cout << "dg3 is empty\n";}

  {
  cout << "\n:reset to another dog\n";
  unique_ptr<Dog> dg4(new Dog("LaPuLaDuo"));
  dg4->bark();
  dg4.reset(new Dog("JinMao"));
  if(!dg4){cout << "dg4 is empty\n";}else{cout << "dg4 is not empty\n";}
  }

  {
  cout << "\n:reset without any parameters\n";
  unique_ptr<Dog> dg5(new Dog("Fadou"));
  dg5->bark();
  //dg5 = nullptr;
  dg5.reset();
  if(!dg5){cout << "dg5 is empty\n";}else{cout << "dg5 is not empty\n";}
  }

  {
  cout << "\n:transfer ownership to another unique ptr with move\n";
  unique_ptr<Dog> dg6(new Dog("SaMoYe"));
  unique_ptr<Dog> dg7(new Dog("ZangAo"));
  dg7->bark();
  dg7 = move(dg6);
  //move:
  //1. ZangAo destoryed
  //2. dg6 becomes empty
  //3. dg7 owns SaMoYe 
  dg7->bark();
  }

  cout << "\n:function parametor\n";
  unique_ptr<Dog> dg8(new Dog("Tianyuan"));
  f(move(dg8));

}
