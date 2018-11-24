#include <iostream>
#include <vector>
#include <algorithm>  //std::find_if
#include <functional>

void PrintValue(int value) { std::cout <<"Value: " << value << std::endl; }

void ForEach1(const std::vector<int>& values, void(*func)(int)) {
    for (int value : values) func(value);
}

void ForEach2(const std::vector<int>& values, const std::function<void(int)>& func) {
    for (int value : values) func(value);
}

int main()
{
  std::vector<int> nums = { 1, 4, 2, 3 };
  //.begin() returns an iterator to the beginning 
  auto it = std::find_if(nums.begin(), nums.end(), [](int value) { return value > 3; });
  std::cout << *it << std::endl;

  ForEach1(nums, PrintValue);
  auto lambda =  [](int value){ std::cout <<"Value: " << value << std::endl; };           //lambda
  ForEach2(nums, lambda);
  ForEach2(nums, [](int value){ std::cout <<"Value: " << value << std::endl; }); //lambda
  int a = 5;
  ForEach2(nums, [&a](int value){ std::cout <<"Value: " << value << a << std::endl; });//capture by ref
  ForEach2(nums, [a] (int value){ std::cout <<"Value: " << value << a << std::endl; }); //capture by value 
  ForEach2(nums, [=] (int value){ std::cout <<"Value: " << value << a << std::endl; }); //pass everything by val
  ForEach2(nums, [=] (int value){ std::cout <<"Value: " << value << a << std::endl; }); //pass everything by ref
}
