#include "Plane.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
// Конструктор по умолчанию
Plane::Plane()
{
   
    cout << "Конструктор по умолчанию вызван" << endl;
}

// Конструктор с параметрами
Plane::Plane(string typePlane, string name, int volumeOfLoad, string size, string cityOfDestination)
    : typePlane(typePlane), name(name), volumeOfLoad(volumeOfLoad), size(size)
{
    this->cityDestination.addToTail(cityOfDestination);
    cout << "Конструктор с параметрами вызван" << endl;
}

// Конструктор копирования
Plane::Plane(const Plane& other)
    : typePlane(other.typePlane), name(other.name), volumeOfLoad(other.volumeOfLoad), size(other.size), cityDestination(other.cityDestination)
{
    cout << "Конструктор копирования вызван" << endl;
}

// Деструктор
Plane::~Plane()
{
    cout << "Деструктор вызван" << endl;
}


void Plane::input() {
    cout << "Введите тип самолета:";
    string typePlane;
    cin >> typePlane;
    setTypePlane(typePlane);

    cout << "Введите наименование самолета:";
    string name;
    getchar();
    getline(cin, name);
    setName(name);
    
    cout << "Введите габариты самолета:";
    string size;
    cin >> size;
    setSize(size);

    cout << "Введите объем перевозимого груза:";
    int volumeLoad;
    cin >> volumeLoad;
    setVolumeOfLoad(volumeLoad);

    string city;

    while (true) {
        cout << "Введите город доставки (или введите 'q' для завершения): ";
        cin >> city;
        if (city == "q" || city == "Q") {
            break;
        }

        cityDestination.addToTail(city);
    }
}


void Plane::print() {
    cout << "Plane" << endl;
    cout << "Type:" << getTypePlane() << endl;
    cout << "Name:" << getName() << endl;
    cout << "Size:" << getSize() << endl;
    cout << "Volume of load:" << getVolumeOfLoad() << endl;
    List cityDestination = getCityOfDestination();
    Node* current = cityDestination.getHead();
    int i = 1;
    while (current != nullptr) {
        cout << i++ << "." << "City:" << current->city << ", ";
        current = current->next;
    }
    cout << endl;
}


void Plane::saveToFile(ofstream& file) {
    file << "PLANE" << endl;
    CargoCarrier::saveToFile(file);
    file << "Type:" << getTypePlane() << endl;
    file << "Name:" << getName() << endl;
    file << "Size:" << getSize() << endl;
    file << "Volume of load:" << getVolumeOfLoad() << endl;
    List cityDestination = getCityOfDestination();
    Node* current = cityDestination.getHead();
    int i = 1;
    while (current != nullptr) {
        file << i++ << "." << "City:" << current->city << ", ";
        current = current->next;
    }
    file << endl;
}


void Plane::loadFromFile(ifstream& file) {
    string line;

    // Пропускаем заголовок "PLANE"
    getline(file, line);

    // Чтение типа самолета
    getline(file, line);
    setTypePlane(line.substr(line.find(":") + 1));

    // Чтение наименования самолета
    getline(file, line);
    setName(line.substr(line.find(":") + 1));

    // Чтение габаритов самолета
    getline(file, line);
    setSize(line.substr(line.find(":") + 1));

    // Чтение объема перевозимого груза
    getline(file, line);
    setVolumeOfLoad(stoi(line.substr(line.find(":") + 1)));

    // Чтение списка городов доставки

    while (getline(file, line)) {
        if (line.empty()) break;  // Останавливаемся, когда встречаем пустую строку
        // Извлекаем город из строки формата "i. City: <название города>"
        size_t pos = line.find("City:");
        if (pos != string::npos) {
            string city = line.substr(pos + 6);  // 6 символов для "City: "
            cityDestination.addToTail(city);
        }
    }
}