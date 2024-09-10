#include "Plane.h"
#include <iostream>
#include <cstdlib>

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
        cout << i++ << "." << "City:" << current->city << ", ";
        current = current->next;
    }
    cout << endl;
}