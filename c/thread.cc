#include <iostream>
#include <thread>
static bool s_finished = false;
using namespace std::literals::chrono_literals;

void DoWork() {
    while(!s_finished){
        std::cout << "Started thread id=" << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(1s);
    }
}

int main(){
    std::thread worker(DoWork);

    //std::cin.get();

    std::this_thread::sleep_for(5s);
    s_finished = true;
    worker.join();
    std::cout << "Main thread id=" << std::this_thread::get_id() << std::endl;
    std::cout << "finished! \n";

}

//lib: -pthread
