#pragma once
#include <vector>
#include <string>
#include "Vehicle.h"

class Showroom {
private:
    std::string name;
    std::vector<Vehicle> vehicles;
    unsigned int capacity;
public:
    Showroom();
    Showroom(std::string name, unsigned int capacity);

    void AddVehicle(Vehicle v);
    void ShowInventory();
    float GetInventoryValue();
    std::vector<Vehicle> GetVehicleList();
};