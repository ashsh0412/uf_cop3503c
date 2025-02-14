#include "ContactBook.h"
#include <algorithm>

// 기본 생성자
ContactBook::ContactBook(){
  curr_size = 0;
}

// 복사 생성자
ContactBook::ContactBook(const ContactBook& other){
    curr_size = other.curr_size;
    for (int i = 0; i < curr_size; i++) {
        contacts[i] = other.contacts[i];
    }
}

// 연락처 찾기
Contact* ContactBook::Find(const std::string& search) {
    for (int i = 0; i < curr_size; i++) {
        if (contacts[i]->getName() == search || contacts[i]->getNumber() == search) {
            return contacts[i];
        }
    }
    return nullptr;
}

// 연락처 추가
void ContactBook::Add(Contact& contact) {
    if (curr_size < MAX_SIZE) {
        contacts[curr_size++] = &contact;
    }
}

// 여러 연락처 추가
void ContactBook::AddContacts(const std::vector<Contact*>& newContacts) {
    for (Contact* contact : newContacts) {
        if (curr_size < MAX_SIZE) {
            contacts[curr_size++] = contact;
        }
    }
}

// 연락처 삭제
void ContactBook::Remove(const Contact& contact) {
    // https://stackoverflow.com/questions/879603/remove-an-array-element-and-shift-the-remaining-ones
    for (unsigned int i = 0; i < curr_size; i++) {
        if (contacts[i]->getName() == contact.getName() &&
            contacts[i]->getNumber() == contact.getNumber()) {
            for (unsigned int j = i; j < curr_size - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            curr_size--;
        }
    }
}

// 모든 연락처 출력
void ContactBook::Display() const {
    for (unsigned int i = 0; i < curr_size; i++) {
        contacts[i]->Display();
    }
}

// 알파벳 순으로 정렬
void ContactBook::Alphabetize() {
    std::sort(contacts, contacts + curr_size,
        // lambda function.
        [](Contact* a, Contact* b) {
            return a->getName() < b->getName();
        });
}

// 대입 연산자 오버로딩
ContactBook& ContactBook::operator=(const ContactBook& other) {
    if (this != &other) {
        curr_size = other.curr_size;
        for (unsigned int i = 0; i < curr_size; i++) {
            contacts[i] = other.contacts[i];
        }
    }
    return *this;
}

// += 연산자 오버로딩 (Contact 추가)
ContactBook& ContactBook::operator+=(const Contact& contact) {
    if (curr_size < MAX_SIZE) {
        contacts[curr_size++] = new Contact(contact);
    }
    return *this;
}

// += 연산자 오버로딩 (다른 ContactBook 추가)
ContactBook& ContactBook::operator+=(const ContactBook& other) {
    for (unsigned int i = 0; i < other.curr_size && curr_size < MAX_SIZE; i++) {
        contacts[curr_size++] = other.contacts[i];
    }
    return *this;
}

// + 연산자 오버로딩 (두 ContactBook 합치기)
ContactBook ContactBook::operator+(const ContactBook& other) const {
    ContactBook result = *this;
    result += other;
    return result;
}

// -= 연산자 오버로딩 (Contact 삭제)
ContactBook& ContactBook::operator-=(const Contact& contact) {
    Remove(contact);
    return *this;
}

// -= 연산자 오버로딩 (다른 ContactBook의 모든 Contact 삭제)
ContactBook& ContactBook::operator-=(const ContactBook& other) {
    for (unsigned int i = 0; i < other.curr_size; i++) {
        Remove(*other.contacts[i]);
    }
    return *this;
}

// - 연산자 오버로딩 (두 ContactBook의 차이 반환)
ContactBook ContactBook::operator-(const ContactBook& other) const {
    ContactBook result = *this;
    result -= other;
    return result;
}

// == 연산자 오버로딩 (같은 연락처인지 비교)
bool ContactBook::operator==(const ContactBook& other) const {
    if (curr_size != other.curr_size) return false;

    for (unsigned int i = 0; i < curr_size; i++) {
        for (unsigned int j = 0; j < other.curr_size; j++) {
            if (contacts[i]->getName() == other.contacts[j]->getName() &&
                contacts[i]->getNumber() == other.contacts[j]->getNumber()) {
            }
        }
    }
    return true;
}

// != 연산자 오버로딩
bool ContactBook::operator!=(const ContactBook& other) const {
    return !(*this == other);
}