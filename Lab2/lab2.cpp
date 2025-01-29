#include "lab2.h"
#include <iostream>
#include <string>

Vehicle::Vehicle() {
    make = "COP3503";
    model = "Rust Bucket";
    year = 1900;
    price = 0;
    mileage = 0;
}

Vehicle::Vehicle(std::string make, std::string model, int year, float price, int mileage) {
    this->make = make;
    this->model = model;
    this->year = year;
    this->price = price;
    this->mileage = mileage;
}

void Vehicle::Display() {
    std::cout << year << " " << make << " " << model << " $" << price << " " << mileage << std::endl;
}

std::string Vehicle::GetYearMakeModel() {
    return std::to_string(year) + " " + make + " " + model;
}

float Vehicle::GetPrice() {
    return price;
}

Showroom::Showroom() {
    name = "Unnamed Showroom";
    capacity = 0;
}




