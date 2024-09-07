#pragma once
#include "CargoCarrier.h"
#include <string>
#include <iostream>
using namespace std;

class Plane : public CargoCarrier
{
private:
	string typePlane;
	string name;
	int volumeOfLoad;
	string size;
	string cityOfDestination;

public:

	Plane();
	Plane(string typePlane, string name, int volumeOfLoad, string size, string cityOfDestination);
	Plane(const Plane& other);
	~Plane();

	void setTypePlane(string typePlane) { this->typePlane = typePlane; }
	void setName(string name) { this->name = name; }
	void setVolumeOfLoad(int volumeOfLoad) { this->volumeOfLoad = volumeOfLoad; }
	void setSize(string size) { this->size = size; }
	void setCityOfDestination(string cityOfDestination) { this->cityOfDestination = cityOfDestination; }

	string getTypePlabe() { return typePlane; }
	string getName() { return name; }
	int getVolumeofLoad() { return volumeOfLoad; }
	string getSize() { return size; }
	string getCityOfDestination() { return cityOfDestination; }

};

