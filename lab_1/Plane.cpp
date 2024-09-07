#include "Plane.h"

// Конструктор по умолчанию
Plane::Plane() : typePlane("Unknown"), name("Unknown"), volumeOfLoad(0), size("Unknown"), cityOfDestination("Unknown")
{
    cout << "Конструктор по умолчанию вызван" << endl;
}

// Конструктор с параметрами
Plane::Plane(string typePlane, string name, int volumeOfLoad, string size, string cityOfDestination)
    : typePlane(typePlane), name(name), volumeOfLoad(volumeOfLoad), size(size), cityOfDestination(cityOfDestination)
{
    cout << "Конструктор с параметрами вызван" << endl;
}

// Конструктор копирования
Plane::Plane(const Plane& other)
    : typePlane(other.typePlane), name(other.name), volumeOfLoad(other.volumeOfLoad), size(other.size), cityOfDestination(other.cityOfDestination)
{
    cout << "Конструктор копирования вызван" << endl;
}

// Деструктор
Plane::~Plane()
{
    cout << "Деструктор вызван" << endl;
}