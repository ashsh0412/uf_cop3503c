#ifndef ABQ_H
#define ABQ_H

#include <stdexcept>

template <typename T>
class ABQ {
private:
    T* data;  // 큐에 저장될 데이터를 위한 배열
    unsigned int size;
    unsigned int maxCapacity;

public:
    // 기본 생성자
    ABQ() {
        size = 0;
        maxCapacity = 1;
        data = new T[maxCapacity];  // 용량이 1인 배열 할당
    }

    // 지정된 용량으로 큐를 생성하는 생성자
    ABQ(int capacity) {
        size = 0;              // 큐의 크기 초기화
        maxCapacity = capacity;  // 큐의 최대 용량을 지정된 용량으로 설정
        data = new T[maxCapacity];  // 지정된 용량의 배열 할당
    }

    // 소멸자
    ~ABQ() {
        delete[] data;  // 동적으로 할당된 메모리 해제
    }

    // 큐에 새로운 데이터를 추가하는 함수
    void enqueue(T newData) {
        if (size == maxCapacity) {  // 큐가 가득 차면 용량을 두 배로 늘림
            unsigned int newMaxCapacity = maxCapacity * 2;  // 새로운 용량 계산
            T* newDataArray = new T[newMaxCapacity];  // 새로운 배열 생성

            // 기존 데이터를 새 배열로 복사
            for (unsigned int i = 0; i < size; i++) {
                newDataArray[i] = data[i];  // 배열의 데이터를 복사
            }

            delete[] data;
            data = newDataArray;
            maxCapacity = newMaxCapacity;
        }

        // 데이터를 큐의 뒤쪽에 추가
        data[size] = newData;
        size++;  // 큐 크기 증가
    }

    // 큐에서 데이터를 제거하고 반환하는 함수
    T dequeue() {
        if (size == 0) {
            throw std::runtime_error("Queue is empty");
        }

        T value = data[0];  // 큐의 앞에서 값을 가져옴
        // 큐에서 앞 데이터 제거
        for (unsigned int i = 1; i < size; i++) {
            data[i - 1] = data[i];
        }
        size--;

        float scaleFactor = 2.0f;  // 축소 비율을 2로 설정 (1/2로 축소)

        if (size / (float)maxCapacity < 1 / scaleFactor && maxCapacity > 1) {
            // 용량 축소 (최소 1 이상)
            maxCapacity = std::max(maxCapacity / 2, 1u);
            T* newDataArray = new T[maxCapacity];
            for (unsigned int i = 0; i < size; i++) {
                newDataArray[i] = data[i];
            }
            delete[] data;
            data = newDataArray;
        }

        return value;  // 큐에서 제거한 값 반환
    }

    // 큐의 앞에 있는 데이터를 반환 (제거하지 않음)
    T peek() {
        if (size == 0) {
            throw std::runtime_error("Queue is empty");
        }

        return data[0];
    }

    // 현재 큐에 들어 있는 데이터의 개수를 반환
    unsigned int getSize() {
        return size;
    }

    // 현재 큐의 최대 용량을 반환
    unsigned int getMaxCapacity() {
        return maxCapacity;
    }

    // 큐를 나타내는 배열을 반환
    T* getData() {
        return data;
    }
};

#endif