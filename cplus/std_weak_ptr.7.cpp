#include <iostream>
#include <string>
#include <memory>

class Entity {
public:
    Entity() { std::cout << "Created Entity!" << std::endl; }
    ~Entity() { std::cout << "Destroyed Entity!" << std::endl; }
    void Print() { std::cout << "Doing some work!" << std::endl;  }
};

int main() {
    std::cout << ">> 1. test weak_ptr" << std::endl;
    std::weak_ptr<Entity> e1;
    {
        std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
        e1 = sharedEntity;

    }
    std::cout << "after exit block, only has one weak reference to sharedEntity" << std::endl; 
    //std::cin.get();
}
/*
https://en.cppreference.com/w/cpp/memory/weak_ptr
>> 1. test weak_ptr
Created Entity!
Destroyed Entity!
after exit block, only has one weak reference to sharedEntity
 */