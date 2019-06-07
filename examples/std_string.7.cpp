#include <iostream>
#include <string>     //std::string
#include <string.h>   //strlen
#include "pp.h"
using namespace std;
int main() {
    pp("1. strlen() vs. std::string.size()");
    const char* name1="Cherno";
    const char  name2[] = {'C','h','e','r','n','o',0,'A'};
    const char  name3[] = {'C','h','e','r','n','o','\0','A'};
    //std::basic_string<char> name4 =  "Cherno"; //it is const char array
    std::string  name4 =  "Cherno"; //it is const char array
    strlen(name1);
    std::cout << name1 << strlen(name1) <<std::endl; //Cherno6
    std::cout << name2 << strlen(name2) <<std::endl; //Cherno6
    std::cout << name3 << strlen(name3) <<std::endl; //Cherno6
    std::cout << name4 << name4.size()  <<std::endl; //Cherno6
    name4 += " hello!";
    std::cout << name4 <<std::endl;  //Cherno hello!
    std::string name5 = std::string("Cherno") + " hello!"; //it is const char array
    std::cout << name5 <<std::endl;  //Cherno hello!
    bool b =  name5.find("no") != std::string::npos;
    std::cout << b <<std::endl;      //1

    pp("2. push_back(), pop_back()");
    std::string str="rabbit";
    str.push_back('s');   // Using push_back() to insert a character at end
    cout << str << endl;  // rabbits
    str.pop_back();       // Using pop_back() to delete a character from end
    cout << str << endl;  // rabbit

    pp("3. resize(), capacity(), shrink_to_fit()");
    str = "geeksforgeeks";
    cout << str << endl;
    str.resize(5);         // Resizing string using resize()
    cout << str << endl;   //geeks
    cout << str.capacity() << endl;  //24
    str.shrink_to_fit();   // Decreasing the capacity of string
    cout << str.capacity() << endl;  //5

    pp("4. begin(), end(), rbegin(), rend()");
    str = "geeksforgeeks";
    std::string::iterator it;          // Declaring iterator
    std::string::reverse_iterator it1; // Declaring reverse iterator
    for (it=str.begin(); it!=str.end(); it++) cout << *it; cout << endl;        //geeksforgeeks
    for (it1=str.rbegin(); it1!=str.rend(); it1++) cout << *it1; cout << endl;  //skeegrofskeeg

    string str1 = "geeksforgeeks is for geeks";
    string str2 = "geeksforgeeks rocks";
    char ch[80];
    str1.copy(ch,13,0);                            //geeksforgeeks
    cout << ch << endl << endl;
    str1.swap(str2);    // using swap() to swap string content
    cout << "The 1st string after swapping is : ";
    cout << str1 << endl;                          //geeksforgeeks rocks
    cout << "The 2nd string after swapping is : "; //geeksforgeeks is for geeks
    cout << str2 << endl;


}
