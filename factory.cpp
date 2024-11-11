#include <iostream>

using namespace std;

class Vehicle {
  public:
    virtual void CreateVehicle() = 0;
};

class Car : public Vehicle {
  public:
    void CreateVehicle() {
      cout << "creating car" << endl;
    }
};

class Bike : public Vehicle {
  public:
    void CreateVehicle() {
      cout << "creating bike" << endl;
    }
};

class VehicleFactory {
  public:
    static Vehicle* getVehicle(string type) {
      if (type == "car")
        return new Car();
      else if (type == "bike")
        return new Bike();
      else
        return NULL;
    }
};

int main() {
  Vehicle* vehicle = VehicleFactory::getVehicle("bike");
  vehicle->CreateVehicle();
}