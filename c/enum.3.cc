#include <iostream>
enum Level {
    Error, Warning, Info   //default A = 0, B = 1, C = 2
};

enum Example2: unsigned char {
    A, B, C   //default A = 0, B = 1, C = 2
};

int main() {
    Level logLevel = Info;
    std::cout << logLevel  << std::endl;

}
