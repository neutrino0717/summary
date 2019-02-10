#include <iostream>
#include <string>
#include <regex>
#include <pp.h>

int main()
{
    // Simple regular expression matching
    const std::string fnames[] = {"foo.log.txt", "zoidberg"};
    const std::regex r1("[a-z]+\\.[a-z]+\\.txt");
    const std::regex r2("([a-z]+)\\.([a-z]+)\\.txt"); // Extraction of a sub-match

    for (const auto &fname : fnames) {
        std::smatch m2;
        bool b1 = std::regex_match(fname, r1);
        bool b2 = std::regex_match(fname, m2, r2);
        std::cout << b1 <<" " <<b2 << " " << m2.size() << " " << m2[0] <<" "<< m2[1] <<" "<< m2[2] << std::endl;
        //1 1 2 foo.txt foo
        //0 0 0
        if (b2) {//below for review
            // The first sub_match is the whole string; the next
            // sub_match is the first parenthesized expression.
            if (m2.size() == 2) {
                std::ssub_match base_sub_match = m2[1];
                std::string base = base_sub_match.str();
                //std::cout << fname << " has a base of " << base << '\n';
            }
        }
    }

    // Extraction of several sub-matches
    const std::regex pieces_regex("([a-z]+)\\.([a-z]+)");
    std::smatch pieces_match;

    for (const auto &fname : fnames) {
        if (std::regex_match(fname, pieces_match, pieces_regex)) {
            std::cout << fname << '\n';
            for (size_t i = 0; i < pieces_match.size(); ++i) {
                std::ssub_match sub_match = pieces_match[i];
                std::string piece = sub_match.str();
                std::cout << "  submatch " << i << ": " << piece << '\n';
            }
        }
    }
}