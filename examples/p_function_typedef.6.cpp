#include <iostream>
#include <vector>

int addn(int a, int b) { return a + b; }

void PrintValue(int value) { std::cout <<"Value: " << value << std::endl; }

void ForEach(const std::vector<int>& values, void(*func)(int)) {
    for (int value : values) func(value);
}

int main()
{
  int (*addn_ptr1)(int,int); addn_ptr1 = &addn; //or
  int (*addn_ptr2)(int,int); addn_ptr2 = addn;  //or
  int (*addn_ptr3)(int,int) = addn; //or
  auto  addn_ptr4 = addn;
  printf("result: %d\n", addn(0,11));         //11
  printf("result: %d\n", addn_ptr1(1,11));    //12
  printf("result: %d\n", addn_ptr2(2,11));    //13
  printf("result: %d\n", addn_ptr3(3,11));    //14
  printf("result: %d\n", addn_ptr4(4,11));    //15
  typedef int(*Func)(int,int); //define type Func
  Func addn_ptr5 = addn;
  std::cout << "result: " << addn_ptr5(5, 11) << std::endl;  //16

  std::vector<int> nums = { 7, 11, 6, 17, 2, 5, 16 };
  ForEach(nums, PrintValue);
  ForEach(nums, [](int value){ std::cout <<"Value: " << value << std::endl; });
}
