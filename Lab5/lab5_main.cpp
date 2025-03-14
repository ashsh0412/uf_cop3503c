#include <iostream>
#include <fstream>
#include "extrafile.h"
using namespace std;

int main()
{
    cout << "Which file(s) to open?\n";
    cout << "1. friendlyships.shp" << endl;
    cout << "2. enemyships.shp" << endl;
    cout << "3. Both files" << endl;
    int option;
    cin >> option;

    // Load files here
    vector<Starship> ships;

    if (option == 1 || option == 3) ships = loadShips("friendlyships.shp");
    if (option == 2 || option == 3) {
        vector<Starship> enemyShips = loadShips("enemyships.shp");
        for (int i = 0; i < enemyShips.size(); i++) {
            ships.push_back(enemyShips[i]);
        }
    }
    cout << "1. Print all ships" << endl;
    cout << "2. Starship with the strongest weapon" << endl;
    cout << "3. Strongest starship overall" << endl;
    cout << "4. Weakest ship (ignoring unarmed)" << endl;
    cout << "5. Unarmed ships" << endl;

    cin >> option;

    // Work your magic here
    if (option == 1) printAllShips(ships);
    else if (option == 2) printShip(findStrongestWeaponShip(ships));
    else if (option == 3) printShip(findStrongestShip(ships));
    else if (option == 4) printShip(findWeakestShip(ships));
    else if (option == 5) printAllShips(findUnarmedShips(ships));
    return 0;
}