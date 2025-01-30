#include "Dealership.h"

Dealership::Dealership() {
    name = "Generic Dealership";
    capacity = 0;
}

Dealership::Dealership(std::string name, unsigned int capacity) {
    this->name = name;
    this->capacity = capacity;
}

void Dealership::AddShowroom(Showroom s) {
    if (showrooms.size() >= capacity) {
        std::cout << "Dealership is full, can't add another showroom!" << std::endl;
        return;
    }
    showrooms.push_back(s);
}

float Dealership::GetAveragePrice() {
    float totalSum = 0;
    int totalVehicles = 0;

    for (int i = 0; i < showrooms.size(); i++) {
        for (auto& vehicle : showrooms[i].GetVehicleList()) {
            totalSum += vehicle.GetPrice();
            totalVehicles += 1;
        }
    }
    return totalSum / totalVehicles;
}

void Dealership::ShowInventory() {
    float totalSum = 0;
    int totalVehicles = 0;

    if (showrooms.empty()) {
        std::cout << name << " is empty!" << std::endl;
        std::cout << "Average car price: $0.00";
        return;
    }

    for (int i = 0; i < showrooms.size(); i++) {
        showrooms[i].ShowInventory();

        totalSum += showrooms[i].GetInventoryValue();

        totalVehicles += showrooms[i].GetVehicleList().size();
        std::cout << std::endl;
    }

    if (totalVehicles > 0) {
        std::cout << "Average car price: $" << totalSum / totalVehicles;
    }
}