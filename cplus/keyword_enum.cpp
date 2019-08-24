#include <iostream>
int main(){
    enum PreciousMetal {
        Platinum, Gold, Silver
    };

    enum Planet {
        Mercury, Venus, Earth
    };

    PreciousMetal gold = Gold;
    std::cout << gold << std::endl;

    Planet earth = Earth;  
    std::cout << earth << std::endl;


    enum Season {
        Summer, Fall, Winter, Spring
    };

    Season winter = Winter;
    int baseValue = winter;
    //baseValue is 2

    enum Season2: char {
        Summer2, Fall2, Winter2, Spring2
    };

    std::cout <<  Fall << std::endl;
    std::cout << Fall2 << std::endl;
}
