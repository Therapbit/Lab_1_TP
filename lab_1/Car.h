#pragma once
#include "CargoCarrier.h"
#include "Keeper.h"
#include "List.h"
#include "LinkedList.h"
#include <string>
#include <iostream>
using namespace std;

class Car : public CargoCarrier
{
private:
    int yearRelease;
    string brandCar;
    string modelCar;
    List cityTimeDelivery;
    int volumeLoad;       
public:


    Car();
    Car(string brandCar, string modelCar, int yearRelease, int volumeLoad, string city, int hour);
    Car(const Car& other);


    void setYearRelease(int yearRelease);
    void setBrandCar(string brandCar);
    void setModelCar(string modelCar);
    void setVolumeLoad(int volumeLoad);
    void setCityTimeDelivery(string city, int hour);

    int getYearRelease();
    string getBrandCar();
    string getModelCar();
    int getVolumeLoad();
    List getCityTimeDelivery();
    void print();
    void input();

    void saveToFile(ofstream& file);
    void loadFromFile(ifstream& file);
};
