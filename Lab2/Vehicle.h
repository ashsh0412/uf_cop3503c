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
