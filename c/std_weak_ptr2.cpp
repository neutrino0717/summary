
#include <iostream>
#include <memory>
#include <pp.h>


std::weak_ptr<int> gw;
//https://en.cppreference.com/w/cpp/memory/weak_ptr
void observe()
{
    std::cout << "use_count == " << gw.use_count() << ": ";  //returns the number of shared_ptr objects that manage the object
    if (auto spt = gw.lock()) { // Has to be copied into a shared_ptr before usage
        std::cout << "use_count == " << gw.use_count() << ": ";
        std::cout << *spt << "\n";
    }
    else {
        std::cout << "gw is expired\n";
    }
}

int main()
{
    {
        auto sp = std::make_shared<int>(42);
        gw = sp;
        observe();
    }
    observe();
}