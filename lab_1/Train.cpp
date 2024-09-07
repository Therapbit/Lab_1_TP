#include "Train.h"

// Конструктор по умолчанию
Train::Train() : nameTrain("Unknown"), yearRelease(0), route("Unknown"), amountWagon(0), volumeLoad(0)
{
    cout << "Конструктор по умолчанию вызван" << endl;
}

// Конструктор с параметрами
Train::Train(string nameTrain, int yearRelease, string route, int amountWagon, int volumeLoad)
    : nameTrain(nameTrain), yearRelease(yearRelease), route(route), amountWagon(amountWagon), volumeLoad(volumeLoad)
{
    cout << "Конструктор с параметрами вызван" << endl;
}

// Конструктор копирования
Train::Train(const Train& other)
    : nameTrain(other.nameTrain), yearRelease(other.yearRelease), route(other.route), amountWagon(other.amountWagon), volumeLoad(other.volumeLoad)
{
    cout << "Конструктор копирования вызван" << endl;
}

// Деструктор
Train::~Train()
{
    cout << "Деструктор вызван" << endl;
}