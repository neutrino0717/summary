#include <iostream>
using String = std::string;
class Entity {
private:
  String m_Name;
public:
  Entity(): m_Name("unknown") {}
  Entity(const String& name):m_Name(name){}
  const String& GetName() const {return m_Name; } 
};

int main() {
  int a = 2;
  int* b = new int;
  int* c = new int[50]; //200 bytes
  Entity* d = (Entity*)malloc(sizeof(Entity)); //simillar to below, but not call the constructor
  Entity* e = new Entity;
  Entity* f = new Entity();
  Entity* g = new Entity[50];
  
  delete e;  //alway delete if using new
  delete f;
  delete[] g; 

}
