#include <iostream>
#include <vector>
#include <stdexcept> // out_of_range 예외를 위해 필요

// 템플릿 클래스 LinkedList 정의
template <typename T>
class LinkedList {
public:
    // Node 구조체: LinkedList의 구성요소
    struct Node {
        T data;          // 데이터 저장
        Node* next;      // 다음 노드 가리킴
        Node* prev;      // 이전 노드 가리킴
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}  // 생성자
    };

private:
    Node* head;    // 리스트의 첫 노드
    Node* tail;    // 리스트의 마지막 노드
    size_t nodeCount; // 현재 노드 개수

public:
    // 기본 생성자: 빈 리스트 초기화
    LinkedList() : head(nullptr), tail(nullptr), nodeCount(0) {}

    // 소멸자: 모든 노드 삭제
    ~LinkedList() { Clear(); }

    // 복사 생성자: 깊은 복사로 다른 리스트를 복제
    LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), nodeCount(0) {
        Node* current = other.head;
        while (current != nullptr) {
            AddTail(current->data);  // 하나씩 추가
            current = current->next;
        }
    }

    // 복사 대입 연산자: 기존 데이터 삭제하고 깊은 복사
    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            Clear();
            Node* current = other.head;
            while (current != nullptr) {
                AddTail(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    // 리스트 크기 반환
    size_t NodeCount() const { return nodeCount; }

    // head, tail 포인터 반환 (읽기/쓰기용)
    Node* GetHead() { return head; }
    const Node* GetHead() const { return head; }
    Node* GetTail() { return tail; }
    const Node* GetTail() const { return tail; }

    // AddHead: 맨 앞에 노드 추가
    void AddHead(const T& value) {
        Node* newNode = new Node(value);
        if (head == nullptr) head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        nodeCount++;
    }

    // AddTail: 맨 뒤에 노드 추가
    void AddTail(const T& value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        nodeCount++;
    }

    // 리스트 정방향 출력
    void PrintForward() const {
        for (Node* current = head; current; current = current->next) {
            std::cout << current->data << std::endl;
        }
    }

    // 리스트 역방향 출력
    void PrintReverse() const {
        for (Node* current = tail; current; current = current->prev) {
            std::cout << current->data << std::endl;
        }
    }

    // 재귀 정방향 출력
    void PrintForwardRecursive(Node* node) const {
        if (!node) return;
        std::cout << node->data << std::endl;
        PrintForwardRecursive(node->next);
    }

    // 재귀 역방향 출력
    void PrintReverseRecursive(Node* node) const {
        if (!node) return;
        std::cout << node->data << std::endl;
        PrintReverseRecursive(node->prev);
    }

    // 첫 번째 일치 노드 찾기
    Node* Find(const T& value) {
        for (Node* current = head; current; current = current->next) {
            if (current->data == value) return current;
        }
        return nullptr;
    }

    // 모든 일치 노드 찾기
    void FindAll(std::vector<Node*>& outData, const T& value) const {
        for (Node* current = head; current; current = current->next) {
            if (current->data == value) outData.push_back(current);
        }
    }

    // 인덱스로 노드 접근
    Node* GetNode(size_t index) {
        if (index >= nodeCount) throw std::out_of_range("Index out of range");
        Node* current = head;
        for (size_t i = 0; i < index; ++i) current = current->next;
        return current;
    }

    const Node* GetNode(size_t index) const {
        if (index >= nodeCount) throw std::out_of_range("Index out of range");
        Node* current = head;
        for (size_t i = 0; i < index; ++i) current = current->next;
        return current;
    }

    // 인덱스로 데이터 접근 (배열처럼 사용 가능)
    T& operator[](size_t index) {
        return GetNode(index)->data;
    }

    const T& operator[](size_t index) const {
        return GetNode(index)->data;
    }

    // 지정 노드 앞에 삽입
    bool InsertBefore(Node* node, const T& value) {
        if (!node) return false;
        if (node == head) AddHead(value);
        else {
            Node* newNode = new Node(value);
            newNode->prev = node->prev;
            newNode->next = node;
            node->prev->next = newNode;
            node->prev = newNode;
            nodeCount++;
        }
        return true;
    }

    // 지정 노드 뒤에 삽입
    bool InsertAfter(Node* node, const T& value) {
        if (!node) return false;
        if (node == tail) AddTail(value);
        else {
            Node* newNode = new Node(value);
            newNode->next = node->next;
            newNode->prev = node;
            node->next->prev = newNode;
            node->next = newNode;
            nodeCount++;
        }
        return true;
    }

    // 인덱스에 삽입
    void InsertAt(const T& value, size_t index) {
        if (index > nodeCount) throw std::out_of_range("Index out of range");
        if (index == 0) AddHead(value);
        else if (index == nodeCount) AddTail(value);
        else InsertBefore(GetNode(index), value);
    }

    // 리스트 비교 연산자
    bool operator==(const LinkedList& rhs) const {
        if (nodeCount != rhs.nodeCount) return false;
        Node* left = head;
        Node* right = rhs.head;
        while (left && right) {
            if (left->data != right->data) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }

    // 삭제 관련 함수들
    bool RemoveHead() { return RemoveAt(0); }
    bool RemoveTail() { return RemoveAt(nodeCount - 1); }

    bool RemoveAt(size_t index) {
        if (index >= nodeCount) return false;
        Node* node = GetNode(index);
        if (node == head) head = node->next;
        if (node == tail) tail = node->prev;
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
        delete node;
        nodeCount--;
        return true;
    }

    size_t Remove(const T& value) {
        size_t removed = 0;
        for (Node* current = head; current;) {
            if (current->data == value) {
                Node* toDelete = current;
                current = current->next;
                RemoveNode(toDelete);
                removed++;
            } else {
                current = current->next;
            }
        }
        return removed;
    }

    void Clear() {
        while (head) RemoveHead();
    }
};