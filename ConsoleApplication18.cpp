#include <iostream>
#include <string>
#include <vector>
#include <cstring> 
using namespace std;

class Person {
private:
    char* name; 
    int age;   

public:
    Person() : name(nullptr), age(0) {}

    Person(const char* name, int age) : age(age) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    Person(const Person& other) : age(other.age) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    Person& operator=(const Person& other) {
        if (this == &other) return *this;
        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        age = other.age;
        return *this;
    }

    ~Person() {
        delete[] name;
    }

    void print() const {
        cout << "Full name: " << name << ", Age: " << age << endl;
    }
};

class Apartment {
private:
    Person* residents;
    int numResidents;

public:
    Apartment() : residents(nullptr), numResidents(0) {}
    Apartment(Person* persons, int numResidents) : numResidents(numResidents) {
        residents = new Person[numResidents];
        for (int i = 0; i < numResidents; ++i) {
            residents[i] = persons[i];
        }
    }

    Apartment(const Apartment& other) : numResidents(other.numResidents) {
        residents = new Person[numResidents];
        for (int i = 0; i < numResidents; ++i) {
            residents[i] = other.residents[i];
        }
    }

    Apartment& operator=(const Apartment& other) {
        if (this == &other) return *this;
        delete[] residents;
        numResidents = other.numResidents;
        residents = new Person[numResidents];
        for (int i = 0; i < numResidents; ++i) {
            residents[i] = other.residents[i];
        }
        return *this;
    }

    ~Apartment() {
        delete[] residents;
    }

    void print() const {
        cout << "Apartment with " << numResidents << " residents:\n";
        for (int i = 0; i < numResidents; ++i) {
            residents[i].print();
        }
    }
};

class House {
private:
    vector<Apartment> apartments;

public:
    void addApartment(const Apartment& apartment) {
        apartments.push_back(apartment);
    }

    void print() const {
        cout << "House with  " << apartments.size() << " apartments:\n";
        for (size_t i = 0; i < apartments.size(); ++i) {
            cout << "Apartment " << i + 1 << ":\n";
            apartments[i].print();
            cout << "----------------------\n";
        }
    }
};

int main() {
    Person p1();
    Person p2();
    Person p3();

    Person apt1Residents[] = { p1, p2 };
    Apartment apt1(apt1Residents, 2);

    Person apt2Residents[] = { p3 };
    Apartment apt2(apt2Residents, 1);

    House house;
    house.addApartment(apt1);
    house.addApartment(apt2);
    house.print();
}
