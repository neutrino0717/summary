#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <pp.h>

class Device {};
class DeviceManager {
private:
        std::unordered_map<std::string, std::vector<Device*>>  m_Devices;
public:
  const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const {
    return m_Devices;
  } 

};
int main() {
  auto a = 5;
  auto b = 6L;
  auto c = 7.7f;
  auto d = "test";
  std::cout << a << " " << b << " " << c << " " << d << std::endl;
  
  std::vector<std::string> strings;
  strings.push_back("Apple");
  strings.push_back("Orange");

  for (std::vector<std::string>::iterator it1 = strings.begin(); it1 != strings.end(); it1++) std::cout << *it1 <<" "; std::cout << std::endl; //Apple Orange
  for (auto                               it2 = strings.begin(); it2 != strings.end(); it2++) std::cout << *it2 <<" "; std::cout << std::endl; //Apple Orange
  for (auto it3: strings)                                                                     std::cout <<  it3 <<" "; std::cout << std::endl; //Apple Orange

  DeviceManager dm;
  const std::unordered_map<std::string, std::vector<Device*>>& devices1 = dm.GetDevices(); //or
  const auto&                                                  devices2 = dm.GetDevices(); //or

  using DeviceMap = std::unordered_map<std::string, std::vector<Device*>>; //alias the type
  const DeviceMap&                                             devices3 = dm.GetDevices(); //or
  typedef std::unordered_map<std::string, std::vector<Device*>> type_Dmap;
  const type_Dmap&                                             devices4 = dm.GetDevices();

}
