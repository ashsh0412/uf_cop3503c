#include <iostream>
#include <string>

class Vehicle {
    private:
        std::string make;
        std::string model;
        int year;
        float price;
        int mileage;
    public:
        Vehicle();
        Vehicle(std::string make, std::string model, int year, float price, int mileage);

        void Display();
        std::string GetYearMakeModel();
        float GetPrice();
};

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