#include <iostream>
using namespace std;

class Enemy {
public:
    std::string attach;
    virtual void attack() { }
};

class Ninja: public Enemy {
public:
    void attack() { attach = "hello"; cout << "Ninja!"<< attach << endl; }
};

class Monster: public Enemy {
public:
    void attack() { cout << "Monster!"<<endl; }
};

int main() {
    Ninja n;
    Monster m;
    Enemy *e1 = &n;
    Enemy *e2 = &m;

    e1->attack();
    e2->attack();
}
