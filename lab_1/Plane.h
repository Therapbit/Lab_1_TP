#pragma once
#include "CargoCarrier.h"
#include "List.h"
#include "LinkedList.h"
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
	List cityDestination;

public:

	Plane();
	Plane(string typePlane, string name, int volumeOfLoad, string size, string cityDestination);
	Plane(const Plane& other);
	~Plane();

	void setTypePlane(string typePlane) { this->typePlane = typePlane; }
	void setName(string name) { this->name = name; }
	void setVolumeOfLoad(int volumeOfLoad) { this->volumeOfLoad = volumeOfLoad; }
	void setSize(string size) { this->size = size; }
	void setCityOfDestination(string cityDestination) { this->cityDestination.addToTail(cityDestination); }

	string getTypePlane() { return typePlane; }
	string getName() { return name; }
	int getVolumeOfLoad() { return volumeOfLoad; }
	string getSize() { return size; }
	List getCityOfDestination() { return cityDestination; }

	void input();
	void print();
	void saveToFile(ofstream& file);
	void loadFromFile(ifstream& file);

};

