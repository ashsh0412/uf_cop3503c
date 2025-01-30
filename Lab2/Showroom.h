#include <iostream>
#include <string>
#include <vector>
#include "Vehicle.h"

class Showroom {
private:
    std::string name;
    std::vector<Vehicle> vehicles;
    int capacity;
public:
    Showroom();
    Showroom(std::string name, int capacity);

    void AddVehicle(Vehicle v);
    void ShowInventory();
    float GetInventoryValue();
};
