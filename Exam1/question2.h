// FREEZE CODE BEGIN
#pragma once

#include <vector>
#include <cmath>

using namespace std;

// Class declaration
class Point3 {
    vector<float> data;

public:
    Point3();
    Point3(float x, float y, float z);

    vector<float> getData();

    Point3 operator+(const Point3& rhs);
    Point3 operator*(const float scale);

    Point3& operator+=(const Point3& rhs);
    Point3& operator*=(const float scale);

    float distance(const Point3& other) const;
};

// Default Constructor
Point3::Point3(){
    for(unsigned int i = 0; i < 3; i++)
        data.push_back(0);
}

// Parameterized constructor
Point3::Point3(float x, float y, float z) {
    data.push_back(x);
    data.push_back(y);
    data.push_back(z);
}

// Data getter
vector<float> Point3::getData() {
    return data;
}

// FREEZE CODE END

// Write your solution below this line.
Point3 Point3::operator+(const Point3& other){
    return Point3(
        data[0] + other.data[0],
        data[1] + other.data[1],
        data[2] + other.data[2]
    );
}
Point3 Point3::operator*(const float scale){
    return Point3(
        data[0] * scale,
        data[1] * scale,
        data[2] * scale
    );
}

Point3& Point3::operator+=(const Point3& other) {
    data[0] += other.data[0];
    data[1] += other.data[1];
    data[2] += other.data[2];
    return *this;
}

Point3& Point3::operator*=(const float scale) {
    data[0] *= scale;
    data[1] *= scale;
    data[2] *= scale;
    return *this;
}

float Point3::distance(const Point3& other) const {
    float x = data[0] - other.data[0];
    float y = data[1] - other.data[1];
    float z = data[2] - other.data[2];
    float value = pow(x, 2) + pow(y, 2) + pow(z, 2);
    return sqrt(value);
}