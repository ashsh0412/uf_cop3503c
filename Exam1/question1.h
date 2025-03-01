#include <string>
#include <iostream>
using namespace std;

// Write your solution below this line.
class Pet{
    string name;
    string species;
    string owner;
    int age;
public:
    Pet(){
        this->name = "Garfield";
        this->species = "Cat";
        this->owner = "Jon";
        this->age = 0;
    }
    Pet(string _name, string _species, string _owner, int _age){
        this->name = _name;
        this->species = _species;
        this->owner = _owner;
        this->age = _age;
    }
    void becomeOlder(){
        age += 1;
    }
    void Adopt(string _owner){
        owner = _owner;
    }
    void Display(){
        cout << "Name: " << name <<endl;
        cout << "Species: " <<species <<endl;
        cout << "Owner: " <<owner <<endl;
        cout << "Age: " <<age <<endl;
    }
    string getName(){
        return name;
    }
    string getSpecies(){
        return species;
    }
    string getOwner(){
        return owner;
    }
    int getAge(){
        return age;
    }
};