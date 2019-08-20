#include <iostream>
int main(){
enum PreciousMetal {
    Platinum, Gold, Silver
};

enum Planet {
    Mercury, Venus, Earth
};

PreciousMetal gold = Gold;
Planet earth = Earth;  
std::cout << gold << std::endl;
std::cout << earth << std::endl;
}