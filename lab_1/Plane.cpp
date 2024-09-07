#include "Plane.h"

// ����������� �� ���������
Plane::Plane() : typePlane("Unknown"), name("Unknown"), volumeOfLoad(0), size("Unknown"), cityOfDestination("Unknown")
{
    cout << "����������� �� ��������� ������" << endl;
}

// ����������� � �����������
Plane::Plane(string typePlane, string name, int volumeOfLoad, string size, string cityOfDestination)
    : typePlane(typePlane), name(name), volumeOfLoad(volumeOfLoad), size(size), cityOfDestination(cityOfDestination)
{
    cout << "����������� � ����������� ������" << endl;
}

// ����������� �����������
Plane::Plane(const Plane& other)
    : typePlane(other.typePlane), name(other.name), volumeOfLoad(other.volumeOfLoad), size(other.size), cityOfDestination(other.cityOfDestination)
{
    cout << "����������� ����������� ������" << endl;
}

// ����������
Plane::~Plane()
{
    cout << "���������� ������" << endl;
}