#include "Car.h"

//Конструктор по умолчанию
Car::Car() : yearRelease(0), brandCar("Unknown"), modelCar("Unknown"), cityDelivery("Unknown"), timeDelivery(0), volumeLoad(0)
{
    cout << "Конструктор по умолчанию вызван" << endl;
}

// Конструктор с параметрами
Car::Car(int yearRelease, string brandCar, string modelCar, string cityDelivery, int timeDelivery, int volumeLoad)
    : yearRelease(yearRelease), brandCar(brandCar), modelCar(modelCar), cityDelivery(cityDelivery), timeDelivery(timeDelivery), volumeLoad(volumeLoad)
{
    cout << "Конструктор с параметрами вызван" << endl;
}

// Конструктор копирования
Car::Car(const Car& other)
    : yearRelease(other.yearRelease), brandCar(other.brandCar), modelCar(other.modelCar), cityDelivery(other.cityDelivery), timeDelivery(other.timeDelivery), volumeLoad(other.volumeLoad)
{
    cout << "Конструктор копирования вызван" << endl;
}

// Деструктор
Car::~Car()
{
    cout << "Деструктор вызван" << endl;
}