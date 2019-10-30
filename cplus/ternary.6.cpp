#include <iostream>

void check (int score) {
    //pass both         -> master
    //pass first        -> pass
    //pass 1st, not 2nd -> fail
    std::string rank = score >= 60 ? score >= 80  ? "master" : "pass" : "fail";
    std::cout << rank << std::endl;
};

int main() {
    check(30);    //fail
    check(60);    //pass
    check(99);    //master
};
