#ifndef ABS_H
#define ABS_H

#include <iostream>

template <typename T>
class ABS {
private:
    T* data;  // 데이터를 저장할 배열
    unsigned int size;
    unsigned int maxCapacity;

public:
    ABS() {
        size = 0;
        maxCapacity = 1;
        data = new T[maxCapacity]; // data를 할당
    }

    ABS(int capacity) {
        size = 0;
        maxCapacity = capacity;  // maxCapacity를 지정된 값으로 설정
        data = new T[maxCapacity]; // data를 할당
    }

    // 소멸자: 메모리 해제
    ~ABS() {
        delete[] data;  // 동적 할당된 배열 해제
    }

    // 데이터를 스택에 추가하는 함수
    void push(T value) {
        if (size == maxCapacity) {
            T* newData = new T[maxCapacity * 2];  // 새로운 배열 할당
            for (unsigned int i = 0; i < size; i++) {
                newData[i] = data[i];  // 기존 데이터 복사
            }
            delete[] data;
            data = newData;
            maxCapacity *= 2;
        }

        data[size] = value;  // 새로운 데이터 추가
        size++;
    }

    // 데이터를 스택에서 꺼내는 함수
    T pop() {
        if (size == 0) {
            throw std::runtime_error("Stack is empty");
        }
        T value = data[--size];

        float scaleFactor = 2.0f;  // 축소 비율을 2로 설정 (1/2로 축소)

        if (size / (float)maxCapacity < 1 / scaleFactor && maxCapacity > 1) {
            // 용량 축소 (최소 1 이상)
            maxCapacity = std::max(maxCapacity / 2, 1u);
            T* newData = new T[maxCapacity];
            for (unsigned int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        return value;
    }

    // 스택에서 가장 위에 있는 값 확인하는 함수
    T peek() {
        if (size == 0) {
            throw std::runtime_error("Stack is empty");
        }
        return data[size - 1];  // 가장 위에 있는 값 반환
    }

    // 스택의 현재 크기 반환
    unsigned int getSize() {
        return size;
    }

    // 스택의 최대 용량 반환
    unsigned int getMaxCapacity() {
        return maxCapacity;
    }

    // 스택의 데이터 배열 반환
    T* getData() {
        return data;
    }
};

#endif