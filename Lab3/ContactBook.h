#include <vector>
#include <string>
#include <iostream>

class Contact {
private:
    std::string name;
    std::string number;

public:
    // 생성자
    Contact(std::string name, std::string number) {
        this->name = name;
        this->number = number;
    }

    std::string getName() const { return name; }
    std::string getNumber() const { return number; }

    void Display() const {
        std::cout << name << ", " << number << std::endl;
    }
};

class ContactBook {
private:
    static const int MAX_SIZE = 100;
    Contact* contacts[MAX_SIZE];
    unsigned int curr_size;

public:
    ContactBook();
    ContactBook(const ContactBook& other);
    ContactBook& operator=(const ContactBook& other);

    // 연락처 관련 메서드
    Contact* Find(const std::string& search);
    void Add(Contact& contact);
    void AddContacts(const std::vector<Contact*>& newContacts);
    void Remove(const Contact& contact);
    void Display() const;
    void Alphabetize();

    // 연산자 오버로딩
    ContactBook& operator+=(const Contact& contact);
    ContactBook& operator+=(const ContactBook& other);
    ContactBook operator+(const ContactBook& other) const;
    ContactBook& operator-=(const Contact& contact);
    ContactBook& operator-=(const ContactBook& other);
    ContactBook operator-(const ContactBook& other) const;
    bool operator==(const ContactBook& other) const;
    bool operator!=(const ContactBook& other) const;
};