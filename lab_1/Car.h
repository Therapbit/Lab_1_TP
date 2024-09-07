#pragma once
#include "CargoCarrier.h"
#include <string>
#include <iostream>
using namespace std;


class Car : public CargoCarrier
{
private:
	int yearRelease;
	string brandCar;
	string modelCar;
	string cityDelivery;
	int timeDelivery;
	int volumeLoad;

public:

	Car();
	Car(int yearRelease, string brandCar, string modelCar, string cityDelivery, int timeDelivery, int volumeLoad);
	Car(const Car& other);
	~Car();


	void setYearRelease(int yearRelease) { this->yearRelease = yearRelease; }
	void setBrandCar(string brandCar) { this->brandCar = brandCar; }
	void setModelCar(string modelCar) { this->modelCar = modelCar; }
	void setCityDelivery(string cityDelivery) { this->cityDelivery = cityDelivery; }
	void setTimeDelivery(int timeDelivery) { this->timeDelivery = timeDelivery; }
	void setVolumeLoad(int volumeLoad) { this->volumeLoad = volumeLoad; }

	int getYearRelease() { return yearRelease; }
	string getBrandCar() { return brandCar; }
	string getCityDelivery() { return cityDelivery; }
	int getTimeDelivery() { return timeDelivery; }
	int getVolumeLoad() { return volumeLoad; }
};

