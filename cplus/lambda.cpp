#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void PrintValue(int value){ std::cout <<"Value: "<<value << std::endl; } 
void ForEach1(const std::vector<int>& values, void(*func)(int)){
    for (int value: values) func(value);        
}
void ForEach2(const std::vector<int>& values, const std::function<void(int)>& func){
    for (int value: values) func(value);        
}

int main() {
    std::vector<int> nums = {1, 4, 2, 3, 5};
    auto it = std::find_if(nums.begin(), nums.end(), [](int value){return value > 3;});
    std::cout << *it << std::endl;  //4
    ForEach1(nums, PrintValue);
    ForEach1(nums, [](int value){ std::cout<<"Value1: "<< value << std::endl;});
    ForEach2(nums, [](int value){ std::cout<<"Value2: "<< value << std::endl;});
    int a = 5;
    ForEach2(nums, [&a](int value){ std::cout<<"Value3: "<< value << a << std::endl;}); //caputre a by ref
    ForEach2(nums, [a] (int value){ std::cout<<"Value4: "<< value << a << std::endl;}); //caputre a by value
    ForEach2(nums, [&] (int value){ std::cout<<"Value5: "<< value << a << std::endl;}); //caputre all by ref
    ForEach2(nums, [=] (int value){ std::cout<<"Value6: "<< value << " " <<  a  << std::endl;}); //caputre all by value

}
