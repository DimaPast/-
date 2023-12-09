#include <iostream>
#include <string>


class Vehicle {
public:
    virtual void drive() const = 0;
};


class Car : public Vehicle {
public:
    void drive() const override {
        std::cout << "Driving a car\n";
    }
};


class Motorcycle : public Vehicle {
public:
    void drive() const override {
        std::cout << "Riding a motorcycle\n";
    }
};


class VehicleFactory {
public:
   
    virtual Vehicle* createVehicle() const = 0;
};

class CarFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() const override {
        return new Car();
    }
};


class MotorcycleFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() const override {
        return new Motorcycle();
    }
};

int main() {
  
    VehicleFactory* carFactory = new CarFactory();
    Vehicle* car = carFactory->createVehicle();
    car->drive();
    delete carFactory;
    delete car;


    VehicleFactory* motorcycleFactory = new MotorcycleFactory();
    Vehicle* motorcycle = motorcycleFactory->createVehicle();
    motorcycle->drive();
    delete motorcycleFactory;
    delete motorcycle;

    return 0;
}