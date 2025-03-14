//This file is optional and here for your own use
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Weapon {
    string name;
    int power;
    float consumption;
};

struct Starship {
    string name;
    string shipClass;
    short length;
    int shield;
    float maxWarp;
    vector<Weapon> armaments;
};

string readString(ifstream &file);
vector<Starship> loadShips(const string &filename);
void printShip(const Starship &ship);
void printAllShips(const vector<Starship> &ships);
Starship findStrongestWeaponShip(const vector<Starship> &ships);
Starship findStrongestShip(const vector<Starship> &ships);
Starship findWeakestShip(const vector<Starship> &ships);
vector<Starship> findUnarmedShips(const vector<Starship> &ships);
