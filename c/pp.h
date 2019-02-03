//
// Created by Evan on 2019/02/03.
//

#ifndef C_PP_H
#define C_PP_H

#endif //C_PP_H

int  pp(std::string s) {
    int len = 80;
    int pad1 = (len - s.length()) / 2;
    int pad2 = len - pad1 - s.length();
    std::cout << "\n" << std::string(pad1, '=')  << s << std::string(pad2, '=') << "\n";
}

int  ppp(std::string s) {
    int len = 80;
    int pad1 = (len - s.length()) / 2;
    int pad2 = len - pad1 - s.length();
    std::cout << "\n" << std::string(pad1, '-')  << s << std::string(pad2, '-') << "\n";
}