#include "CargoCarrier.h"
#include "Car.h"
#include "Plane.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "Keeper.h"
using namespace std;


int main()
{
   
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Plane plane;
    plane.input();
    plane.print();
}
