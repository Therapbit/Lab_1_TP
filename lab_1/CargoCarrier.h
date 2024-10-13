#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class CargoCarrier
{
public:
	virtual void print() = 0 ;
	virtual void input() = 0;
	virtual void saveToFile(ofstream& file);
	virtual void loadFromFile(ifstream& file);
};

