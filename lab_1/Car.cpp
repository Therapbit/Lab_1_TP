#include "Car.h"
#include "Keeper.h"
#include <iostream>
using namespace std;



Car::Car() : yearRelease(0), volumeLoad(0), brandCar("Unknown"), modelCar("Unknown") {
    cityTimeDelivery.addToTail("Unknown");
}

// ����������� � �����������
Car::Car(string brandCar, string modelCar, int yearRelease, int volumeLoad, string city, int hour) {
    this->brandCar = brandCar;
    this->modelCar = modelCar;
    this->yearRelease = yearRelease;
    this->volumeLoad = volumeLoad;
    this->cityTimeDelivery.addToTail(city, hour);



}

// ����������� �����������
Car::Car(const Car& other) {
    this->brandCar = other.brandCar;
    this->modelCar = other.modelCar;
    this->yearRelease = other.yearRelease;
    this->volumeLoad = other.volumeLoad;
    this->cityTimeDelivery = other.cityTimeDelivery; // ����������� ������ ������� � ������� ��������
}



void Car::setYearRelease(int yearRelease) { this->yearRelease = yearRelease; }
void Car::setBrandCar(string brandCar) { this->brandCar = brandCar; }
void Car::setModelCar(string modelCar) { this->modelCar = modelCar; }
void Car::setVolumeLoad(int volumeLoad) { this->volumeLoad = volumeLoad; }

void Car::setCityTimeDelivery(string city, int hour) {
    cityTimeDelivery.addToTail(city, hour);
}

int Car:: getYearRelease() { return yearRelease; }
int Car::getVolumeLoad() { return volumeLoad; }
string Car::getBrandCar() { return brandCar; }
string Car::getModelCar() { return modelCar; }

List Car::getCityTimeDelivery() {
    return cityTimeDelivery;
}


void Car::input() {
    cout << "������� ����� ����������:";
    string brand;
    cin >> brand;
    setBrandCar(brand);

    cout << "������� ������ ����������:";
    string model;
    cin >> model;
    setModelCar(model);
    
    getchar();
    cout << "������� ��� ������� ����������:";
    int yearRelease;
    cin >> yearRelease;
    setYearRelease(yearRelease);

    cout << "������� ������������ ����� ����� � ����������:";
    int volumeLoad;
    cin >> volumeLoad;
    setVolumeLoad(volumeLoad);

    string city;
    int hour;

    while (true) {
        cout << "������� ����� �������� (��� ������� 'q' ��� ����������): ";
        cin >> city;
        if (city == "q" || city == "Q") {
            break;
        }

        cout << "������� ���� �������� �� ������ " << city << ": ";
        cin >> hour;

        cityTimeDelivery.addToTail(city, hour);
    }


}


void Car::print() {
    cout << "Car" << endl;
    cout << "Brand:" << getBrandCar() << endl;
    cout << "Model:" << getModelCar() << endl;
    cout << "Year of release:" << getYearRelease() << endl;
    cout << "Volume of load:" << getVolumeLoad() << endl;
    List cityTimeDelivery = getCityTimeDelivery();
    Node* current = cityTimeDelivery.getHead();
    int i = 1;
    while (current != nullptr) {
        cout << i++ << "." << "City:" << current->city << ", Hour:" << current->hour << endl;
        current = current->next;
    }
}