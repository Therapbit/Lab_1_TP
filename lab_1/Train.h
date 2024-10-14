#pragma once
#include "CargoCarrier.h"
#include <string>
#include "List.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

class Train :  public CargoCarrier
{
private:
	string nameTrain;
	int yearRelease;
	List route;
	int amountWagon;
	int volumeLoad;

public:

	Train();
	Train(string nameTrain, int yearRelease, int amountWagon, int volumeLoad);
	Train(const Train& other);
	~Train();


	void setNameTrain(string nameTrain) { this->nameTrain = nameTrain; }
	void setYearRelease(int yearRelease) { this->yearRelease = yearRelease; }
	void setRoute(string route) { this->route.addToTail(route); }
	void setAmountWagon(int amountWagon) { this->amountWagon = amountWagon; }
	void setVolumeLoad(int volumeLoad) { this->volumeLoad = volumeLoad; }

	string getNameTrain() { return nameTrain; }
	int getYearRelease() { return yearRelease; }
	List getRoute() { return route; }
	int getAmountWagon() { return amountWagon; }
	int getVolumeLoad() { return volumeLoad; }

	void input();
	void print();
	void makeChange();
	void saveToFile(ofstream& file);
	void loadFromFile(ifstream& file);
};

