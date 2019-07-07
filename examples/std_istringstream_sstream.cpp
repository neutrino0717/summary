#include <iostream>
#include <sstream>

int main(){;
std::string str = "true";
bool boolValue;

std::istringstream(str) >> std::boolalpha >> boolValue;
std::cout << boolValue << std::endl;
}
