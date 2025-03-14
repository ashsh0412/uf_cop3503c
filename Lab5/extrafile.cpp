//This file is optional and here for your own use
#include "extrafile.h"

// translate binary to string
string readString(ifstream &file) {
    int length;
    file.read((char*)(&length), sizeof(int));
    char *buffer = new char[length]; // set address
    file.read(buffer, length); // set info into address
    string result = "";
    result = string(buffer);
    delete[] buffer;
    return result;
}

vector<Starship> loadShips(const string &filename) {
    ifstream file(filename, ios::binary);
    vector<Starship> ships;

    int shipCount;
    file.read((char*)(&shipCount), sizeof(int));

    for (int i = 0; i < shipCount; i++) {
        Starship ship;
        ship.name = readString(file); // string
        ship.shipClass = readString(file); // string
        file.read((char*)(&ship.length), sizeof(short));
        file.read((char*)(&ship.shield), sizeof(int));
        file.read((char*)(&ship.maxWarp), sizeof(float));

        int weaponCount;
        file.read((char*)(&weaponCount), sizeof(int));

        for (int j = 0; j < weaponCount; j++) {
            Weapon weapon;
            weapon.name = readString(file);
            file.read((char*)(&weapon.power), sizeof(int));
            file.read((char*)(&weapon.consumption), sizeof(float));
            ship.armaments.push_back(weapon);
        }

        ships.push_back(ship);
    }

    file.close();
    return ships;
}

void printShip(const Starship &ship) {
    cout << "Name: " << ship.name << endl;
    cout << "Class: " << ship.shipClass << endl;
    cout << "Length: " << ship.length << endl;
    cout << "Shield capacity: " << ship.shield << endl;
    cout << "Maximum Warp: " << ship.maxWarp << endl;
    cout << "Armaments:";

    if (ship.armaments.empty()) {
        cout << "Unarmed" << endl;
    } else {
        int totalPower = 0;
        for (const auto &weapon : ship.armaments) {
            cout << weapon.name << ", " << weapon.power << ", " << weapon.consumption << endl;
            totalPower += weapon.power;
        }
        cout << "Total firepower: " << totalPower << endl;
    }
}

void printAllShips(const vector<Starship> &ships) {
    for (const auto &ship : ships) {
        printShip(ship);
    }
}

Starship findStrongestWeaponShip(const vector<Starship> &ships) {
    Starship strongestShip;
    int maxPower = 0;

    for (const auto &ship : ships) {
        for (const auto &weapon : ship.armaments) {
            if (weapon.power > maxPower) {
                maxPower = weapon.power;
                strongestShip = ship;
            }
        }
    }
    return strongestShip;
}

Starship findStrongestShip(const vector<Starship> &ships) {
    Starship strongestShip;
    int maxTotalPower = 0;

    for (const auto &ship : ships) {
        int totalPower = 0;
        for (const auto &weapon : ship.armaments) {
            totalPower += weapon.power;
        }
        if (totalPower > maxTotalPower) {
            maxTotalPower = totalPower;
            strongestShip = ship;
        }
    }
    return strongestShip;
}

Starship findWeakestShip(const vector<Starship> &ships) {
    Starship weakestShip;
    int minTotalPower = 1000000000;

    for (const auto &ship : ships) {
        if (!ship.armaments.empty()) {
            int totalPower = 0;
            for (const auto &weapon : ship.armaments) {
                totalPower += weapon.power;
            }
            if (totalPower < minTotalPower) {
                minTotalPower = totalPower;
                weakestShip = ship;
            }
        }
    }
    return weakestShip;
}

vector<Starship> findUnarmedShips(const vector<Starship> &ships) {
    vector<Starship> unarmedShips;
    for (const auto &ship : ships) {
        if (ship.armaments.empty()) {
            unarmedShips.push_back(ship);
        }
    }
    return unarmedShips;
}