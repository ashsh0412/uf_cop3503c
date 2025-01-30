

#include "Showroom.h"

Showroom::Showroom() {
    name = "Unnamed Showroom";
    capacity = 0;
}

Showroom::Showroom(std::string name, int capacity) {
    this->name = name;
    this->capacity = capacity;
}

void Showroom::AddVehicle(Vehicle v) {
    if (vehicles.size() <= capacity) {
        std::cout << "Showroom is full! Cannot add " << v.GetYearMakeModel() << std::endl;
        return;
    }
    vehicles.push_back(v);
}

void Showroom::ShowInventory() {
    for (int i = 0; i < vehicles.size(); i++) {
        Vehicle& v = vehicles[i];
        v.Display();
    }
}

float Showroom::GetInventoryValue() {
    float total = 0;
    for (int i = 0; i < vehicles.size(); i++) {
        total += vehicles[i].GetPrice();
    }
}
