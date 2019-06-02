#include <iostream>
#include <vector>
#include <algorithm>
//using namespace std;
//func(val,x) == f=std::bind1st(func,v);f(x) 
//func(x,val) == f=std::bind2st(func,v);f(x) 

int main(){
int a[] = {1, 2, 100, 200};
 
// remove all elements that is less that 100
std::vector< int> arr(a, a + 4);
arr.erase( std::remove_if( arr.begin(),  arr.end(),std::bind2nd( std::less< int>(), 100)), arr.end());
for(int &i: arr) std::cout << i << " "; std::cout << std::endl;

// remove all elements that is less that or equal 100
std::vector< int> arr2(a, a + 4);
arr2.erase( std::remove_if( arr2.begin(),  arr2.end(),std::not1(std::bind2nd( std::greater< int>(), 100))), arr2.end());
for(int &i: arr2) std::cout << i << " "; std::cout << std::endl;

// remove all elements that is bigger that 100
std::vector< int> arr3(a, a + 4);
arr3.erase( std::remove_if( arr3.begin(),  arr3.end(),std::bind1st( std::less< int>(), 100)), arr3.end());
for(int &i: arr3) std::cout << i << " "; std::cout << std::endl;
// remove all elements that is bigger that 100
arr.erase( std::remove_if( arr.begin(),  arr.end(),std::bind2nd( std::greater< int>(), 100)), arr.end());


}
