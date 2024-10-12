#include "Train.h"

// ����������� �� ���������
Train::Train() : nameTrain("Unknown"), yearRelease(0), amountWagon(0), volumeLoad(0)
{
    cout << "����������� �� ��������� ������" << endl;
}

// ����������� � �����������
Train::Train(string nameTrain, int yearRelease, int amountWagon, int volumeLoad)
    : nameTrain(nameTrain), yearRelease(yearRelease), amountWagon(amountWagon), volumeLoad(volumeLoad)
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

void Train::input() {
    cout << "������� ������������ ������:";
    string nameTrain;
    getline(cin, nameTrain);
    setNameTrain(nameTrain);

    cout << "������� ��� ������� ������:";
    int yearRelease;
    cin >> yearRelease;
    setYearRelease(yearRelease);

    getchar();
    cout << "������� ���������� �������:";
    int amountWagon;
    cin >> amountWagon;
    setAmountWagon(amountWagon);

    cout << "������� ����� ������������ �����:";
    int volumeLoad;
    cin >> volumeLoad;
    setVolumeLoad(volumeLoad);

    string city;
    cout << "������� ������ �������� ����� Enter (��� ������� 'q' ��� ����������): " << endl;
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