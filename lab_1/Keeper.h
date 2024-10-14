#pragma once
#include "CargoCarrier.h"
#include "LinkedList.h"
#include <iostream>
#include "Plane.h"
#include "Train.h"
#include "Car.h"
using namespace std;


class Keeper
{
private:

	LinkedList transportList;

public:
	Keeper() {};
	~Keeper() { clearTransport(); };

	void addTransport(CargoCarrier* transport);
	void removeTransport();
	void changeTransport();
	void printTransport() const; 
	void clearTransport();

	void saveToFile(string filename);
	void loadFromFile(string filename);

};