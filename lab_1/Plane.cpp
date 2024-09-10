#include "Plane.h"
#include <iostream>
#include <cstdlib>

using namespace std;
// Конструктор по умолчанию
Plane::Plane()
{
   
    cout << "Конструктор по умолчанию вызван" << endl;
}

// Конструктор с параметрами
Plane::Plane(string typePlane, string name, int volumeOfLoad, string size, string cityOfDestination)
    : typePlane(typePlane), name(name), volumeOfLoad(volumeOfLoad), size(size)
{
    this->cityDestination.addToTail(cityOfDestination);
    cout << "Конструктор с параметрами вызван" << endl;
}

// Конструктор копирования
Plane::Plane(const Plane& other)
    : typePlane(other.typePlane), name(other.name), volumeOfLoad(other.volumeOfLoad), size(other.size), cityDestination(other.cityDestination)
{
    cout << "Конструктор копирования вызван" << endl;
}

// Деструктор
Plane::~Plane()
{
    cout << "Деструктор вызван" << endl;
}


void Plane::input() {
    cout << "Введите тип самолета:";
    string typePlane;
    cin >> typePlane;
    setTypePlane(typePlane);

    cout << "Введите наименование самолета:";
    string name;
    getchar();
    getline(cin, name);
    setName(name);
    
    cout << "Введите габариты самолета:";
    string size;
    cin >> size;
    setSize(size);

    cout << "Введите объем перевозимого груза:";
    int volumeLoad;
    cin >> volumeLoad;
    setVolumeOfLoad(volumeLoad);

    string city;

    while (true) {
        cout << "Введите город доставки (или введите 'q' для завершения): ";
        cin >> city;
        if (city == "q" || city == "Q") {
            break;
        }

        cityDestination.addToTail(city);
    }
}


void Plane::print() {
    cout << "Plane" << endl;
    cout << "Type:" << getTypePlane() << endl;
    cout << "Name:" << getName() << endl;
    cout << "Size:" << getSize() << endl;
    cout << "Volume of load:" << getVolumeOfLoad() << endl;
    List cityDestination = getCityOfDestination();
    Node* current = cityDestination.getHead();
    int i = 1;
    while (current != nullptr) {
        cout << i++ << "." << "City:" << current->city << ", ";
        current = current->next;
    }
    cout << endl;
}