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
	CargoCarrier* searchName(string& n);
	void printTransport() const; 
	void clearTransport();
	void removeByName(string& n);

	void saveToFile(const char* filename);
	void loadFromFile(const char* filename);

	void printlist();
};