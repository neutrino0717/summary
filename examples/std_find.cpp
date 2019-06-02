#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
 
int main()
{
    int n1 = 3;
    int n2 = 5;
 
    std::vector<int> v{0, 1, 2, 3, 4};
    //std::find() 
    auto result1 = std::find(std::begin(v), std::end(v), n1);
    auto result2 = std::find(std::begin(v), std::end(v), n2);
    
    std::cout << (result1 == std::end(v)) << '\n';
    std::cout << (result2 == std::end(v)) << '\n';
    
    std::string s = "this is a book";
    auto result3 = std::find(std::begin(s), std::end(s), 'a');
    //std::string.find()
    auto result4 = s.find('a');
    std::cout << (result3 == std::end(s)) << '\n';
    std::cout << result4 << '\n';
}
