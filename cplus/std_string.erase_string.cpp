#include <iostream>
#include <algorithm>
#include <string>
 
int main()
{
    std::string s = "This is an example";
    s.erase(0, 5); // Erase "This "
    std::cout << s << '\n';
 
    s = "This is an example";
    s.erase(std::find(s.begin(), s.end(), ' ')); // Erase ' '
    std::cout << s << '\n';
    auto p = std::find(s.begin(), s.end(), ' ');
    std::cout << *p << '\n';
 
    s = "This is an example";
    s.erase(s.find(' ')); // Trim from ' ' to the end of the string
    std::cout << s << '\n';

    auto pp = s.find(' ');
    std::cout << pp << '\n';   //4
}
