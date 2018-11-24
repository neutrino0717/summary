#include <iostream>
#include <string>     //std::string
#include <string.h>   //strlen

int main() {
    const char* name1="Cherno";
    const char  name2[] = {'C','h','e','r','n','o',0,'A'};
    const char  name3[] = {'C','h','e','r','n','o','\0','A'};
    //std::basic_string<char> name4 =  "Cherno"; //it is const char array
    std::string  name4 =  "Cherno"; //it is const char array
    strlen(name1);
    std::cout << name1 << strlen(name1) <<std::endl; 
    std::cout << name2 << strlen(name2) <<std::endl; 
    std::cout << name3 << strlen(name3) <<std::endl; 
    std::cout << name4 << name4.size()  <<std::endl; 
    name4 += " hello!";
    std::string name5 = std::string("Cherno") + " hello!"; //it is const char array
    std::cout << name4 <<std::endl; 
    std::cout << name5 <<std::endl; 
    bool b =  name5.find("no") != std::string::npos;
    std::cout << b <<std::endl; 

}
