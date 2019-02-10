#include <iostream>
#include <string>
#include <vector>
struct Vertex {
    float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex) {
    stream << vertex.x << ", " << vertex.y << ", " <<vertex.z;
    return stream;
}
int main() {
    Vertex* vs1 = new Vertex[5];
    for (int i = 0; i< 5; i++) std::cout << vs1[i] <<"; "; std::cout << std::endl; //0, 0, 0; 0, 0, 0; 0, 0, 0; 0, 0, 0; 0, 0, 0;

    std::vector<Vertex> vs2;
    vs2.push_back({1, 2, 3});
    vs2.push_back({4, 5, 6});
    vs2.push_back({7, 8, 9});
    for (int i = 0; i< vs2.size(); i++) std::cout << vs2[i] <<"; "; std::cout << std::endl;  //1, 2, 3; 4, 5, 6; 7, 8, 9;
    //will copy
    for (Vertex v: vs2)                 std::cout << v      <<"; "; std::cout << std::endl;  //1, 2, 3; 4, 5, 6; 7, 8, 9;
    //best, no copy
    for (const Vertex& v: vs2)          std::cout << v      <<"; "; std::cout << std::endl;  //1, 2, 3; 4, 5, 6; 7, 8, 9;
    vs2.erase(vs2.begin() + 1 );  //remove the 2nd element
    //best, no copy
    for (const Vertex& v: vs2)          std::cout << v      <<"; "; std::cout << std::endl;  //1, 2, 3; 7, 8, 9;
    vs2.clear();                  //remove all
    //best, no copy
    for (const Vertex& v: vs2)          std::cout << v      <<"; "; std::cout << std::endl;

}
