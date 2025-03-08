#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class LinkedList {
public:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& value) {
            data = value;
            next = nullptr;
            prev = nullptr;
        }
    };

private:
    Node* head;
    Node* tail;
    unsigned int nodeCount;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        nodeCount = 0;
    }

    LinkedList(const LinkedList<T>& other) {
        head = nullptr;
        tail = nullptr;
        nodeCount = 0;

        if (other.head == nullptr) {
            return;
        }

        Node* current = other.head;
        while (current != nullptr) {
            AddTail(current->data);
            current = current->next;
        }
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        nodeCount = 0;
    }

    LinkedList<T>& operator=(const LinkedList<T>& other) {
        if (this == &other) {
            return *this;
        }

        while (head != nullptr) { // delete original
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        nodeCount = 0;

        Node* current = other.head;
        while (current != nullptr) { // copy new
            AddTail(current->data);
            current = current->next;
        }

        return *this;
    }

    T& operator[](unsigned int index) {
        Node* node = GetNode(index);
        return node->data;
    }

    const T& operator[](unsigned int index) const {
        const Node* node = GetNode(index);
        return node->data;
    }

    unsigned int NodeCount() const {
        return nodeCount;
    }

    Node* GetHead() {
        return head;
    }

    const Node* GetHead() const {
        return head;
    }

    Node* GetTail() {
        return tail;
    }

    const Node* GetTail() const {
        return tail;
    }

    Node* Find(const T& value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void FindAll(std::vector<Node*>& outData, const T& value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                outData.push_back(current);
            }
            current = current->next;
        }
    }

    Node* GetNode(unsigned int index) {
        if (index >= nodeCount) {
            throw std::out_of_range("Index out of range");
        }

        Node* current = head;
        for (unsigned int i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }

    const Node* GetNode(unsigned int index) const {
        if (index >= nodeCount) {
            throw std::out_of_range("Index out of range");
        }

        const Node* current = head;
        for (unsigned int i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }

    void AddHead(const T& value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head; // newNode -> head
            head->prev = newNode; // newNode <- head
            head = newNode; // https://stackoverflow.com/questions/46575583/how-to-add-node-to-front-of-linked-list-c-im-overthinking-the-concept
        }
        nodeCount++;
    }

    void AddTail(const T& value) {
        Node* newNode = new Node(value);

        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail; // opposite to AddHead
            tail->next = newNode;
            tail = newNode;
        }
        nodeCount++;
    }

    void AddNodesHead(const T* values, unsigned int count) {
        for (unsigned int i = count; i > 0; i--) {
            AddHead(values[i - 1]);
        }
    }

    void AddNodesTail(const T* values, unsigned int count) {
        for (unsigned int i = 0; i < count; i++) {
            AddTail(values[i]);
        }
    }

    void PrintForward() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }

    void PrintReverse() const {
        Node* current = tail;
        while (current != nullptr) {
            std::cout << current->data << std::endl;
            current = current->prev;
        }
    }

    void InsertBefore(Node* node, const T& value) {
        Node* newNode = new Node(value);
        newNode->prev = node->prev;
        newNode->next = node;
        node->prev->next = newNode;
        nodeCount++;
    }

    void InsertAfter(Node* node, const T& value) {
        Node* newNode = new Node(value);
        newNode->next = node->next;
        newNode->prev = node;
        node->next->prev = newNode;
        node->next = newNode;
        nodeCount++;
    }

    void InsertAt(const T& value, unsigned int index) {
        if (index > nodeCount) throw std::out_of_range("Index out of range");
        if (index == 0) AddHead(value);
        else if (index == nodeCount) AddTail(value);
        else InsertBefore(GetNode(index), value);
    }

    bool operator==(const LinkedList& otherList) const {
        if (nodeCount != otherList.nodeCount) return false;

        Node* currentThis = head;
        Node* currentOther = otherList.head;
        while (currentThis && currentOther) {
            if (currentThis->data != currentOther->data) return false;
            currentThis = currentThis->next;
            currentOther = currentOther->next;
        }
        return currentThis == nullptr && currentOther == nullptr;
    }

    void PrintForwardRecursive(Node* node) const {
        if (!node) return;
        std::cout << node->data << std::endl;
        PrintForwardRecursive(node->next); // pointing until there is no node to point
    }

    void PrintReverseRecursive(Node* node) const {
        if (!node) return;
        std::cout << node->data << std::endl;
        PrintReverseRecursive(node->prev); // pointing until there is no node to point
    }

    bool RemoveHead() {
        if (!head) return false; // if list is empty
        Node* temp = head;
        if (head == tail) {
          head = nullptr;
          tail = nullptr;
        } else {
            head = head->next;  // set new head before delete original one
            head->prev = nullptr;
        }
        delete temp;
        nodeCount--;
        return true;
    }

    bool RemoveTail() {
        if (!tail) return false; // if list is empty
        Node* temp = tail;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev; // set new tail before delete original one
            tail->next = nullptr;
        }
        delete temp;
        nodeCount--;
        return true;
    }

    bool RemoveAt(unsigned int index) {
        if (index >= nodeCount) return false;

        if (index == 0) return RemoveHead();
        if (index == nodeCount - 1) return RemoveTail();

        Node* node = GetNode(index);
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete node;
        nodeCount--;
        return true;
    }

    int Remove(const T& value) {
        int count = 0;
        Node* temp = head;
        Node* prev = nullptr;

        while (temp && temp->data == value) {
            head = temp->next;
            delete temp;
            temp = head;
            count++;
        }

        while (temp) {
            if (temp->data == value) {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
                count++;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        return count;
    }

    void Clear() {
        while (head) RemoveHead();
    }
};