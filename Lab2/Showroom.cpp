#include "Showroom.h"
#include <iostream>

Showroom::Showroom() {
    name = "Unnamed Showroom";
    capacity = 0;
}

Showroom::Showroom(std::string name, unsigned int capacity) {
    this->name = name;
    this->capacity = capacity;
}

void Showroom::AddVehicle(Vehicle v) {
    if (vehicles.size() >= capacity) {
        std::cout << "Showroom is full! Cannot add " << v.GetYearMakeModel() << std::endl;
        return;
    }
    vehicles.push_back(v);
}

void Showroom::ShowInventory() {
    if (vehicles.empty()) {
        std::cout << name << " is empty!" << std::endl;
    } else {
        std::cout << "Vehicles in " << name << std::endl;
        for (auto& vehicle : vehicles) {
            vehicle.Display();
        }
    }
}

float Showroom::GetInventoryValue() {
    float total = 0;
    for (auto& vehicle : vehicles) {
        total += vehicle.GetPrice();
    }
    return total;
}

std::vector<Vehicle> Showroom::GetVehicleList() {
    return vehicles;
}