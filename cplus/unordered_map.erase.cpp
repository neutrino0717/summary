// map::erase
#include <iostream>
#include <string>
#include <map>

int main ()
{
  std::map<std::string,std::string> mymap;

  // populating container:
  mymap["U.S."] = "Washington";
  mymap["U.K."] = "London";
  mymap["France"] = "Paris";
  mymap["Russia"] = "Moscow";
  mymap["China"] = "Beijing";
  mymap["Germany"] = "Berlin";
  mymap["Japan"] = "Tokyo";
  //mymap.erase ( mymap.begin() );      // erasing by iterator, china removed
  //mymap.erase ("Germany");            // erasing by key, germany removed
  mymap.erase ( mymap.find("China"), mymap.end() ); // erasing by range, all removed
  // show content:
  for ( auto& x: mymap )
    std::cout << x.first << ": " << x.second << std::endl;


  // erase examples:

  return 0;
}
