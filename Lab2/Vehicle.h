#pragma once
#include <string>
#include <iostream>

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