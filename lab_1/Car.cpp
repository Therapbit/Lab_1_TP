#include "Car.h"

//����������� �� ���������
Car::Car() : yearRelease(0), brandCar("Unknown"), modelCar("Unknown"), cityDelivery("Unknown"), timeDelivery(0), volumeLoad(0)
{
    cout << "����������� �� ��������� ������" << endl;
}

// ����������� � �����������
Car::Car(int yearRelease, string brandCar, string modelCar, string cityDelivery, int timeDelivery, int volumeLoad)
    : yearRelease(yearRelease), brandCar(brandCar), modelCar(modelCar), cityDelivery(cityDelivery), timeDelivery(timeDelivery), volumeLoad(volumeLoad)
{
    cout << "����������� � ����������� ������" << endl;
}

// ����������� �����������
Car::Car(const Car& other)
    : yearRelease(other.yearRelease), brandCar(other.brandCar), modelCar(other.modelCar), cityDelivery(other.cityDelivery), timeDelivery(other.timeDelivery), volumeLoad(other.volumeLoad)
{
    cout << "����������� ����������� ������" << endl;
}

// ����������
Car::~Car()
{
    cout << "���������� ������" << endl;
}