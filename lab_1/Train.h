#pragma once
#include "CargoCarrier.h"
#include <string>
#include <iostream>
using namespace std;

class Train :  public CargoCarrier
{
private:
	string nameTrain;
	int yearRelease;
	string route;
	int amountWagon;
	int volumeLoad;

public:

	Train();
	Train(string nameTrain, int yearRelease, string route, int amountWagon, int volumeLoad);
	Train(const Train& other);
	~Train();


	void setNameTrain(string nameTrain) { this->nameTrain = nameTrain; }
	void setYearRelease(int yearRelease) { this->yearRelease = yearRelease; }
	void setRoute(string route) { this->route = route; }
	void setAmountWagon(int amountWagon) { this->amountWagon = amountWagon; }
	void setVolumeLoad(int volumeLoad) { this->volumeLoad = volumeLoad; }

	string getNameTrain() { return nameTrain; }
	int getYearRelease() { return yearRelease; }
	string getRoute() { return route; }
	int getAmountWagon() { return amountWagon; }
	int getVolumeLoad() { return volumeLoad; }
};

