#include <string>
#include "Showroom.h"

class Dealership {
    private:
        std::string name;
        std::vector<Showroom> showrooms;
        unsigned int capacity;
    public:
        Dealership();
        Dealership(std::string name, unsigned int capacity);

        void AddShowroom(Showroom s);
        float GetAveragePrice();
        void ShowInventory();
};



