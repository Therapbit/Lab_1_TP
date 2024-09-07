#include "Train.h"

// ����������� �� ���������
Train::Train() : nameTrain("Unknown"), yearRelease(0), route("Unknown"), amountWagon(0), volumeLoad(0)
{
    cout << "����������� �� ��������� ������" << endl;
}

// ����������� � �����������
Train::Train(string nameTrain, int yearRelease, string route, int amountWagon, int volumeLoad)
    : nameTrain(nameTrain), yearRelease(yearRelease), route(route), amountWagon(amountWagon), volumeLoad(volumeLoad)
{
    cout << "����������� � ����������� ������" << endl;
}

// ����������� �����������
Train::Train(const Train& other)
    : nameTrain(other.nameTrain), yearRelease(other.yearRelease), route(other.route), amountWagon(other.amountWagon), volumeLoad(other.volumeLoad)
{
    cout << "����������� ����������� ������" << endl;
}

// ����������
Train::~Train()
{
    cout << "���������� ������" << endl;
}