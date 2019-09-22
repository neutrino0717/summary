#include <iostream>
#include <bitset>

int main(){
    std::bitset<10> b1("1111110000");
    std::cout << b1.size() << '\n';
    size_t idx = 0;
    for(; idx<10; idx++){
        std::cout << idx << ":" << b1.test(idx) << std:: endl;
    }
    std::cout << "b1[0]:" << b1[0] << b1.test(0) << std:: endl;
    std::cout << "b1[9]:" << b1[9] << b1.test(9) << std:: endl;
    std::cout << "b1:" << b1<< "\n";
    std::cout << "b1.to_string():" << b1.to_string() << "\n";


}
