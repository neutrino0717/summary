// unordered_map::count
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,double> mymap = {
     {"Burger",2.99},
     {"Fries",1.99},
     {"Soda",1.50} };

  for (auto& x: {"Burger","Pizza","Salad","Soda"}) {
      std::cout << "mymap has "<< mymap.count(x) << " " << x << std::endl;
  }

  std::cout << "mymap.size() is " << mymap.size() << std::endl;

  return 0;
}
