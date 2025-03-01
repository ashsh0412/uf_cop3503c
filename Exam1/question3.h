using namespace std;

// FREEZE CODE BEGIN
struct OfficeWorker {
    int money = 0;
    OfficeWorker(int m) {
        money = m;
    }

    void depositPaycheck(int amount) {
        money += amount;
    }
};

struct ConstructionWorker {
    int money = 0;
    ConstructionWorker(int m) {
        money = m;
    }

    void depositPaycheck(int amount) {
        money += amount;
    }
};
// FREEZE CODE END

template <typename T>
void payByCopy(T OfficeWorker, int amount) {
    // your code here :)
    OfficeWorker.depositPaycheck(amount);
}

template <typename T>
void payByRef(T& OfficeWorker, int amount) {
    // your code here :)
    OfficeWorker.depositPaycheck(amount);
}

template <typename T>
void payByPointer(T* OfficeWorker, int amount) {
    // your code here :)
    OfficeWorker->depositPaycheck(amount);
}