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
    Vertex* vertices1 = new Vertex[5];
    for (int i = 0; i< 5; i++)
        std::cout << vertices1[i] << std::endl;

    std::vector<Vertex> vertices2;
    vertices2.push_back({1, 2, 3});
    vertices2.push_back({4, 5, 6});
    vertices2.push_back({7, 8, 9});
    for (int i = 0; i< vertices2.size(); i++)
        std::cout << vertices2[i] << std::endl;
    for (Vertex v: vertices2)           //will copy
        std::cout << v << std::endl;
    for (const Vertex& v: vertices2)    //best, no copy
        std::cout << v << std::endl;
    vertices2.erase(vertices2.begin() + 1 ); //remove the 2nd element
    for (const Vertex& v: vertices2)    //best, no copy
        std::cout << v << std::endl;
    vertices2.clear();                        //remove all
    for (const Vertex& v: vertices2)    //best, no copy
        std::cout << v << std::endl;

    std::vector<int> vertices3;
}
