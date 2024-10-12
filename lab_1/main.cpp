#include "CargoCarrier.h"
#include "Car.h"
#include "Plane.h"
#include "Train.h"
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
    

    Keeper keeper;
    int choice = 0;

    while (choice != 10) {
        cout << "----------------МЕНЮ----------------\n\n" << endl;
        cout << "1 - Ввод Поезда\n2 - Ввод Самолета\n3 - Ввод Машины\n";
        cout << "4 - Удалить персонажа\n";
        cout << "5 - Сохранить в файл\n";
        cout << "6 - Загрузить из файла\n";
        cout << "7 - Найти персонажа\n";
        cout << "8 - Изменить данные персонажа\n";
        cout << "9 - Показать все содержимое контейнера\n";
        cout << "10 - Завершить программу\n";
        cout << ">>> ";
        cin >> choice;

        switch (choice) {
        case 1: {
            system("cls");
            getchar();
            Train* train = new Train();
            train->input();
            keeper.addTransport(train);
            system("cls");
            break; 
        }
        case 2: {
            system("cls");

            Plane* plane = new Plane();
            plane->input();
            keeper.addTransport(plane);
            system("cls");
            break;
        }
        case 3: {
            system("cls");
            Car* car = new Car();
            car->input();
            keeper.addTransport(car);
            system("cls");
            break;
        }
        case 9:
            //печать всего контейнера
            system("cls");
            keeper.printTransport();//функция в Кипере, которая прогоняет весь список и выводит всю информацию
            system("pause");
            system("cls");
            break; // Выход из switch
        case 10:
            // Выход из программы
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
            break;
        }
    }


        keeper.clearTransport();

        return 0;
}
