#include "Plane.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
// ����������� �� ���������
Plane::Plane()
{
   
    cout << "����������� �� ��������� ������" << endl;
}

// ����������� � �����������
Plane::Plane(string typePlane, string name, int volumeOfLoad, string size, string cityOfDestination)
    : typePlane(typePlane), name(name), volumeOfLoad(volumeOfLoad), size(size)
{
    this->cityDestination.addToTail(cityOfDestination);
    cout << "����������� � ����������� ������" << endl;
}

// ����������� �����������
Plane::Plane(const Plane& other)
    : typePlane(other.typePlane), name(other.name), volumeOfLoad(other.volumeOfLoad), size(other.size), cityDestination(other.cityDestination)
{
    cout << "����������� ����������� ������" << endl;
}

// ����������
Plane::~Plane()
{
    cout << "���������� ������" << endl;
}


void Plane::input() {
    cout << "������� ��� ��������:";
    string typePlane;
    cin >> typePlane;
    setTypePlane(typePlane);

    cout << "������� ������������ ��������:";
    string name;
    getchar();
    getline(cin, name);
    setName(name);
    
    cout << "������� �������� ��������:";
    string size;
    cin >> size;
    setSize(size);

    cout << "������� ����� ������������ �����:";
    int volumeLoad;
    cin >> volumeLoad;
    setVolumeOfLoad(volumeLoad);

    string city;

    while (true) {
        cout << "������� ����� �������� (��� ������� 'q' ��� ����������): ";
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

    // ���������� ��������� "PLANE"
    getline(file, line);

    // ������ ���� ��������
    getline(file, line);
    setTypePlane(line.substr(line.find(":") + 1));

    // ������ ������������ ��������
    getline(file, line);
    setName(line.substr(line.find(":") + 1));

    // ������ ��������� ��������
    getline(file, line);
    setSize(line.substr(line.find(":") + 1));

    // ������ ������ ������������ �����
    getline(file, line);
    setVolumeOfLoad(stoi(line.substr(line.find(":") + 1)));

    getline(file, line);  // ��������� ������ � ����������
    line = line.substr(line.find(":") + 1);  // ������� ����� "Route:"
    // ������ ������ ������� ��������

    while (getline(file, line)) {
        if (line.empty()) break;  // ���������������, ����� ��������� ������ ������
        // ��������� ����� �� ������ ������� "i. City: <�������� ������>"
        size_t pos = line.find("City:");
        if (pos != string::npos) {
            string city = line.substr(pos + 5);  // 6 �������� ��� "City: "
            cityDestination.addToTail(city);
        }
    }
}


void Plane::makeChange() {
    int command = 0;

    while (command != 5) {
        cout << "�������� ����� �������� �� ������ ��������\n1.��� ��������\n2.������������ ��������\n3.��������\n4.��������� �����\n5.��������� � ����\n";
        cin >> command;
        switch (command) {
        case 1: {
            string typePlane;
            system("cls");
            cout << "������� ����� ��� ��������\nType of plane:";
            cin >> typePlane;
            setTypePlane(typePlane);
            cout << "��� �������� ������� �������";
            system("pause");
            system("cls");
            break;
        }
        case 2: {
            string namePlane;
            system("cls");
            cout << "������� ����� ������������ ��������\nName of Plane:";
            cin >> namePlane;
            setName(namePlane);
            cout << "������������ �������� ������� ��������";
            system("pause");
            system("cls");
            break;
        }
        case 3: {
            string size;
            system("cls");
            cout << "������� �������� ��������\nSize:";
            cin >> size;
            setSize(size);
            cout << "�������� �������� ������� ��������";
            system("pause");
            system("cls");
            break;
        }
        case 4: {
            int volumeLoad;
            system("cls");
            cout << "������� ����� ����������� ��������\nVolume of Load:";
            cin >> volumeLoad;
            setVolumeOfLoad(volumeLoad);
            cout << "����������� �������� ������� ��������\n";
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