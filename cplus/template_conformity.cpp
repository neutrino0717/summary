#include <iostream>
#include <vector>

using namespace std;
class Vehicle {
public:
  void Test() {
        //Implementation
        cout << "in Vehicle" << endl;
    }
};
class Car: public Vehicle {
public:
    void Test() {
        //Implementation
        cout << "in Car" << endl;
    }
 
 };
class Truck {};
template <typename T>
class Service {
    vector<T> list;
    
public:
    void add(T item) {
        list.push_back(item);
    }
    
    void test() {
        for (T item : list) {
            item.Test();
        }
    }
};


int main(){

Vehicle vehicle;
Car car;
Truck truck;

Service<Vehicle> service;;
service.add(vehicle);
service.add(car);
service.test();

//service.add(truck);//<- Error

}