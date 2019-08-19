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
    std::cout << ">> 1. test unique_ptr" << std::endl;
    { 
        //std::unique_ptr<Entity> entity(new Entity());
        std::unique_ptr<Entity> entity = std::make_unique<Entity>(); //preferred way
        entity->Print();
    }
/*
>> 1. test unique_ptr
Created Entity!
Doing some work!
Destroyed Entity!
 */
    std::cout << ">> 2. test shared_ptr 1" << std::endl;
    std::shared_ptr<Entity> e1;
    {
        std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
        sharedEntity->Print();
        //e1 = sharedEntity;
    }
    std::cout << "after exit block, no more reference to sharedEntity" << std::endl;
/*
>> 2. test shared_ptr 1
Created Entity!
Doing some work!
Destroyed Entity!
after exit block, no more reference to sharedEntity
 */

    std::cout << ">> 3. test shared_ptr 2" << std::endl;
    std::shared_ptr<Entity> e2;
    {
        std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
        sharedEntity->Print();
        e2 = sharedEntity;

    }
    std::cout << "after exit block, still has one reference to sharedEntity" << std::endl; 
    //std::cin.get();
/*
>> 3. test shared_ptr 2
Created Entity!
Doing some work!
after exit block, still has one reference to sharedEntity
Destroyed Entity!
*/

}
