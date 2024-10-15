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
        cout << i++ << "." << "City:" << current->city << endl;
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
    file << "City Destination:\n";
    while (current != nullptr) {
        file << i++ << "." << "City:" << current->city << endl;
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

    getline(file, line);  // Считываем строку с маршрутами
    line = line.substr(line.find(":") + 1);  // Убираем метку "Route:"
    // Чтение списка городов доставки

    while (getline(file, line)) {
        if (line.empty()) break;  // Останавливаемся, когда встречаем пустую строку
        // Извлекаем город из строки формата "i. City: <название города>"
        size_t pos = line.find("City:");
        if (pos != string::npos) {
            string city = line.substr(pos + 5);  // 6 символов для "City: "
            cityDestination.addToTail(city);
        }
    }
}


void Plane::makeChange() {
    int command = 0;
    Node* current = cityDestination.getHead();
    Node* prev = nullptr;
    while (command != 7) {
        cout << "Выберите какое значение вы хотите поменять\n1.Тип самолета\n2.Наименование самолета\n3.Габариты\n4.Вмещаемый объем\n5.Изменить город\n6.Добавить город\n7.Вернуться в меню\n";
        cin >> command;
        switch (command) {
        case 1: {
            string typePlane;
            system("cls");
            cout << "Введите новый тип самолета\nType of plane:";
            cin >> typePlane;
            setTypePlane(typePlane);
            cout << "Тип самолета успешно изменен" << endl;
            system("pause");
            system("cls");
            break;
        }
        case 2: {
            string namePlane;
            system("cls");
            cout << "Введите новое наименование самолета\nName of Plane:";
            cin >> namePlane;
            setName(namePlane);
            cout << "Наименование самолета успешно изменено" << endl;
            system("pause");
            system("cls");
            break;
        }
        case 3: {
            string size;
            system("cls");
            cout << "Введите габариты самолета\nSize:";
            cin >> size;
            setSize(size);
            cout << "Габариты самолета успешно изменены" << endl;
            system("pause");
            system("cls");
            break;
        }
        case 4: {
            int volumeLoad;
            system("cls");
            cout << "Введите новую вмещаемость самолета\nVolume of Load:";
            cin >> volumeLoad;
            setVolumeOfLoad(volumeLoad);
            cout << "Вмещаемость самолета успешно изменена\n";
            system("pause");
            system("cls");
            break;
        }
        case 5: {
            string cityOld, cityNew;
            cout << "Введите город, который хотите поменять:";
            cin >> cityOld;
            cout << "Введите новый город";
            cin >> cityNew;
            while (current != nullptr) {
                if (cityOld == current->city) {
                    current->city = cityNew;
                }
                prev = current;
                current = current->next;
            }
            cout << "Город " << cityOld << " заменен на " << cityNew << " успешно\n";
            break;
        }
        case 6: {
            string cityNew;
            cout << "Введите новый город, он добавится в конец списка:";
            cin >> cityNew;
            cityDestination.addToTail(cityNew);
            cout << "Город " << cityNew << " успешно добавлен" << endl;
        }
        case 7: {
            break;
        }
        }
    }
}