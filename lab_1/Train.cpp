#include "Train.h"
#include <fstream>

// Конструктор по умолчанию
Train::Train() : nameTrain("Unknown"), yearRelease(0), amountWagon(0), volumeLoad(0)
{
    cout << "Конструктор по умолчанию вызван" << endl;
}

// Конструктор с параметрами
Train::Train(string nameTrain, int yearRelease, int amountWagon, int volumeLoad)
    : nameTrain(nameTrain), yearRelease(yearRelease), amountWagon(amountWagon), volumeLoad(volumeLoad)
{
    cout << "Конструктор с параметрами вызван" << endl;
}

// Конструктор копирования
Train::Train(const Train& other)
    : nameTrain(other.nameTrain), yearRelease(other.yearRelease), route(other.route), amountWagon(other.amountWagon), volumeLoad(other.volumeLoad)
{
    cout << "Конструктор копирования вызван" << endl;
}

// Деструктор
Train::~Train()
{
    cout << "Деструктор вызван" << endl;
}

void Train::input() {
    cout << "Введите наименование поезда:";
    string nameTrain;
    getline(cin, nameTrain);
    setNameTrain(nameTrain);

    cout << "Введите год выпуска поезда:";
    int yearRelease;
    cin >> yearRelease;
    setYearRelease(yearRelease);

    getchar();
    cout << "Введите количество вагонов:";
    int amountWagon;
    cin >> amountWagon;
    setAmountWagon(amountWagon);

    cout << "Введите объем перевозимого груза:";
    int volumeLoad;
    cin >> volumeLoad;
    setVolumeLoad(volumeLoad);

    string city;
    cout << "Введите города маршрута через Enter (или введите 'q' для завершения): " << endl;
    while (true) {
        cin >> city;
        if (city == "q" || city == "Q") {
            break;
        }

        route.addToTail(city);
    }
}


void Train::print() {
    cout << "Train" << endl;
    cout << "Name:" << getNameTrain() << endl;
    cout << "Year of release:" << getYearRelease() << endl;
    cout << "Amount of wagons:" << getAmountWagon() << endl;
    cout << "Volume of load:" << getVolumeLoad() << endl;
    List route = getRoute();
    Node* current = route.getHead();
    int i = 1;
    cout << "Route:\n";
    while (current != nullptr) {
        cout << i++ << "." << "City:" << current->city << endl;
        current = current->next;
    }
    cout << endl;
}

void Train::saveToFile(ofstream& file) {
    file << "TRAIN" << endl;
    CargoCarrier::saveToFile(file);
    file << "Name:" << getNameTrain() << endl;
    file << "Year of release:" << getYearRelease() << endl;
    file << "Amount of wagons:" << getAmountWagon() << endl;
    file << "Volume of load:" << getVolumeLoad() << endl;
    List route = getRoute();
    Node* current = route.getHead();
    int i = 1;
    file << "Route:\n";
    while (current != nullptr) {
        file << i++ << "." << "City:" << current->city << endl;
        current = current->next;
    }
    file << endl;
}

void Train::loadFromFile(ifstream& file) {
    string line;

    // Пропускаем заголовок "TRAIN"
    getline(file, line);

    // Чтение наименования поезда
    getline(file, line);
    setNameTrain(line.substr(line.find(":") + 1));

    // Чтение года выпуска
    getline(file, line);
    setYearRelease(stoi(line.substr(line.find(":") + 1)));

    // Чтение количества вагонов
    getline(file, line);
    setAmountWagon(stoi(line.substr(line.find(":") + 1)));

    // Чтение объема перевозимого груза
    getline(file, line);
    setVolumeLoad(stoi(line.substr(line.find(":") + 1)));


    getline(file, line);  // Считываем строку с маршрутами
    line = line.substr(line.find(":") + 1);  // Убираем метку "Route:"
    // Чтение маршрута поездов

    while (getline(file, line)) {
        if (line.empty()) break;  // Останавливаемся, когда встречаем пустую строку
        // Извлекаем город из строки формата "i. City: <название города>"
        size_t pos = line.find("City:");
        if (pos != string::npos) {
            string city = line.substr(pos + 5);  // 6 символов для "City:"
            route.addToTail(city);
        }
    }
}


void Train::makeChange() {
    int command = 0;

    while (command != 5) {
        cout << "Выберите какое значение вы хотите поменять\n1.Наименовние поезда\n2.Год выпуска\n3.Количество вагонов\n4.Вмещаемый объем\n5.Вернуться в меню\n";
        cin >> command;
        switch (command) {
        case 1: {
            string nameTrain;
            system("cls");
            cout << "Введите новое наименование поезда\nName of train:";
            cin >> nameTrain;
            setNameTrain(nameTrain);
            cout << "Наименование поезда успешно изменено";
            system("pause");
            system("cls");
            break;
        }
        case 2: {
            int yearRelease;
            system("cls");
            cout << "Введите новый год выпуска поезда\nYear of release:";
            cin >> yearRelease;
            setYearRelease(yearRelease);
            cout << "Год выпуска успешно изменен";
            system("pause");
            system("cls");
            break;
        }
        case 3: {
            int amountWagons;
            system("cls");
            cout << "Введите новое количество вагонов\nAmount of wagons:";
            cin >> amountWagons;
            setAmountWagon(amountWagons);
            cout << "Количество вагонов успешно изменено";
            system("pause");
            system("cls");
            break;
        }
        case 4: {
            int volumeLoad;
            system("cls");
            cout << "Введите новую вмещаемость поезда\nVolume of Load:";
            cin >> volumeLoad;
            setVolumeLoad(volumeLoad);
            cout << "Вмещаемость поезда успешно изменена\n";
            system("pause");
            system("cls");
            break;
        }
        case 5: {
            break;
        }
        }
    }
}