#include <iostream>
using namespace std;

// FREEZE CODE BEGIN
#pragma once
class String {
private:
    char* data;
    int length;
public:
    String();
    String(const char* str);
    ~String();
    String(const String& other);
    String& operator=(const String& other);
    String operator+(const String& other);
    int getLength() const { return length; }
    const char* c_str() const { return data; }
};
// FREEZE CODE END

String::String() {
    this->length = 0;
    this->data = new char[1];
}

String::String(const char* inputString) {
    length = 0;
    while (inputString[length] != '\0') {
        length++;
    }
    this->length = length;
    data = new char[length + 1];
    for (int i = 0; i <= length; i++) {
        data[i] = inputString[i];
    }
    this->data = data;
}

String::~String() {
    delete[] data;
}

String::String(const String& other) {
    length = other.length;
    data = new char[length+1];
    for (int i = 0; i <= length; i++) {
        data[i] = other.data[i];
    }
}

String& String::operator=(const String& other) {
    if (this == &other) {
        return *this;
    }
    delete[] data;
    length = other.length;
    data = new char[length+1];
    for (int i = 0; i <= length; i++) {
        data[i] = other.data[i];
    }
    return *this;
}

String String::operator+(const String& other) {
    String newString;

    delete[] newString.data;

    newString.length = this->length + other.length;
    newString.data = new char[newString.length + 1];

    int position = 0;
    for (int i = 0; i < this->length; i++) {
        newString.data[position] = this->data[i];
        position++;
    }
    for (int i = 0; i < other.length; i++) {
        newString.data[position] = other.data[i];
        position++;
    }

    newString.data[newString.length] = '\0';

    return newString;
}