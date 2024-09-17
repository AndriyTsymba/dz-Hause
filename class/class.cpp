#include <iostream>
using namespace std;

class Person {
public:
    string name; 
    int age;

 
    Person(string personName = nullptr, int personAge = 0) {
        name = personName;
        age = personAge;
    }

    void print()  {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Apartment {
public:
    Person people[2]; 
    int peopleCount;  

    Apartment(int count = 0) {
        peopleCount = count;
    }

    void addPerson(int index, string name, int age) {
        if (index < 2) {
            people[index] = Person(name, age);
        }
    }

    void print() {
        for (int i = 0; i < peopleCount; ++i) {
            people[i].print();
        }
    }
};

class House {
public:
    Apartment apartments[2]; 
    int apartmentCount;      

    House(int count = 0) {
        apartmentCount = count;
    }

    void addApartment(int index, int peopleCount) {
        if (index < 2) {
            apartments[index] = Apartment(peopleCount);
        }
    }

    void addPersonToApartment(int apartmentIndex, int personIndex, string name, int age) {
        if (apartmentIndex < 2) {
            apartments[apartmentIndex].addPerson(personIndex, name, age);
        }
    }
    void print() {
        for (int i = 0; i < apartmentCount; ++i) {
            cout << "Apartment " << i + 1 << ":\n";
            apartments[i].print();
        }
    }
};

int main() {
    House house(2);
    house.addApartment(0,2);
    house.addPersonToApartment(0, 0, "Mark", 30);
    house.addPersonToApartment(0, 1, "Vika", 28);
    house.addApartment(1, 1);
    house.addPersonToApartment(1, 0, "Alice", 25);
    house.print();
    return 0;
}
