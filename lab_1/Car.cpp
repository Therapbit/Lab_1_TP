#include "Car.h"
#include "Keeper.h"
#include <iostream>
#include <fstream>
using namespace std;



Car::Car() : yearRelease(0), volumeLoad(0), brandCar("Unknown"), modelCar("Unknown"), numberCar("Unknown") {
}

// ����������� � �����������
Car::Car(string brandCar, string modelCar, int yearRelease, int volumeLoad, string city, int hour, string numberCar) {
    this->brandCar = brandCar;
    this->modelCar = modelCar;
    this->yearRelease = yearRelease;
    this->volumeLoad = volumeLoad;
    this->cityTimeDelivery.addToTail(city, hour);
    this->numberCar = numberCar;


}

// ����������� �����������
Car::Car(const Car& other) {
    this->brandCar = other.brandCar;
    this->modelCar = other.modelCar;
    this->yearRelease = other.yearRelease;
    this->volumeLoad = other.volumeLoad;
    this->numberCar = other.numberCar;
    this->cityTimeDelivery = other.cityTimeDelivery; // ����������� ������ ������� � ������� ��������
}



void Car::setYearRelease(int yearRelease) { this->yearRelease = yearRelease; }
void Car::setBrandCar(string brandCar) { this->brandCar = brandCar; }
void Car::setModelCar(string modelCar) { this->modelCar = modelCar; }
void Car::setVolumeLoad(int volumeLoad) { this->volumeLoad = volumeLoad; }
void Car::setNumberCar(string numberCar) { this->numberCar = numberCar; }
void Car::setCityTimeDelivery(string city, int hour) {
    cityTimeDelivery.addToTail(city, hour);
}

int Car:: getYearRelease() { return yearRelease; }
int Car::getVolumeLoad() { return volumeLoad; }
string Car::getBrandCar() { return brandCar; }
string Car::getModelCar() { return modelCar; }
string Car::getNumberCar() { return numberCar; }
List Car::getCityTimeDelivery() {
    return cityTimeDelivery;
}


void Car::input() {
    cout << "������� ����� ����������:";
    string numberCar;
    cin >> numberCar;
    setNumberCar(numberCar);
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
    cout << "number of car:" << getNumberCar() << endl;
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


void Car::saveToFile(ofstream& file) {
    file << "CAR" << endl;
    file << "number of car:" << getNumberCar() << endl;
    file << "Brand:" << getBrandCar() << endl;
    file << "Model:" << getModelCar() << endl;
    file << "Year of release:" << getYearRelease() << endl;
    file << "Volume of load:" << getVolumeLoad() << endl;
    List cityTimeDelivery = getCityTimeDelivery();
    Node* current = cityTimeDelivery.getHead();
    int i = 1;
    while (current != nullptr) {
        file << i++ << "." << "City:" << current->city << ", Hour:" << current->hour << endl;
        current = current->next;
    }
}


void Car::loadFromFile(ifstream& file) {
    string line;

    // ���������� ��������� "CAR"
    getline(file, line);

    getline(file, line);
    setNumberCar(line.substr(line.find(":") + 1));
    // ������ ����� ����������
    getline(file, line);
    setBrandCar(line.substr(line.find(":") + 1));

    // ������ ������ ����������
    getline(file, line);
    setModelCar(line.substr(line.find(":") + 1));

    // ������ ���� ������� ����������
    getline(file, line);
    setYearRelease(stoi(line.substr(line.find(":") + 1)));

    // ������ ������ ������������ �����
    getline(file, line);
    setVolumeLoad(stoi(line.substr(line.find(":") + 1)));

    // ������ ������ ������� � ������� ��������

    while (getline(file, line)) {
        if (line.empty()) break;  // ���������������, ���� ��������� ������ ������

        // ��������� ����� � ���� ��������
        size_t cityPos = line.find("City:");
        size_t hourPos = line.find("Hour:");

        if (cityPos != string::npos && hourPos != string::npos) {
            string city = line.substr(cityPos + 5, hourPos - cityPos - 6);
            int hour = stoi(line.substr(hourPos + 5));
            cityTimeDelivery.addToTail(city, hour);
        }
    }
}


void Car::makeChange() {
    int command = 0;

    while (command != 6) {
        cout << "�������� ����� �������� �� ������ ��������\n1.����� ������\n2.����� ������\n3.������ ������\n4.��� �������\n5.��������� �����\n6.��������� � ����\n";
        cin >> command;
        switch (command) {
        case 1: {
            string numberCar;
            system("cls");
            cout << "������� ����� ����� ������\nNumber of Car:";
            cin >> numberCar;
            setNumberCar(numberCar);
            cout << "����� ������ ������� �������";
            system("pause");
            system("cls");
            break;
        }
        case 2: {
            string brandCar;
            system("cls");
            cout << "������� ����� ����� ������\nBrand:";
            cin >> brandCar;
            setBrandCar(brandCar);
            cout << "����� ������ ������� ��������";
            system("pause");
            system("cls");
            break;
        }
        case 3: {
            string modelCar;
            system("cls");
            cout << "������� ����� ������ ������\nModel:";
            cin >> modelCar;
            setModelCar(modelCar);
            cout << "������ ������ ������� ��������";
            system("pause");
            system("cls");
            break;
        }
        case 4: {
            int yearRelease;
            system("cls");
            cout << "������� ����� ��� ������� ������\nYear of release:";
            cin >> yearRelease;
            setYearRelease(yearRelease);
            cout << "��� ������� ������ ������� �������";
            system("pause");
            system("cls");
            break;
        }
        case 5: {
            int volumeLoad;
            system("cls");
            cout << "������� ����� ����������� ������\nVolume of Load:";
            cin >> volumeLoad;
            setVolumeLoad(volumeLoad);
            cout << "����������� ������ ������� ��������\n";
            system("pause");
            system("cls");
            break;
        }
        case 6: {
            break;
        }
        }
    }
}