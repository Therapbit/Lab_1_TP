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
    cout << "Route:";
    while (current != nullptr) {
        cout << current->city << ", ";
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
    file << "Route:";
    while (current != nullptr) {
        file << current->city << ", ";
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

    // Чтение маршрута поездов

    // Разбираем города через запятую
    size_t start = 0;
    size_t end = line.find(", ");
    while (end != string::npos) {
        route.addToTail(line.substr(start, end - start));
        start = end + 2;  // Пропускаем запятую и пробел
        end = line.find(", ", start);
    }

    // Добавляем последний город
    if (start < line.size()) {
        route.addToTail(line.substr(start));
    }
}