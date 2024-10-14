#include "Train.h"
#include <fstream>

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

    // ���������� ��������� "TRAIN"
    getline(file, line);

    // ������ ������������ ������
    getline(file, line);
    setNameTrain(line.substr(line.find(":") + 1));

    // ������ ���� �������
    getline(file, line);
    setYearRelease(stoi(line.substr(line.find(":") + 1)));

    // ������ ���������� �������
    getline(file, line);
    setAmountWagon(stoi(line.substr(line.find(":") + 1)));

    // ������ ������ ������������ �����
    getline(file, line);
    setVolumeLoad(stoi(line.substr(line.find(":") + 1)));


    getline(file, line);  // ��������� ������ � ����������
    line = line.substr(line.find(":") + 1);  // ������� ����� "Route:"
    // ������ �������� �������

    while (getline(file, line)) {
        if (line.empty()) break;  // ���������������, ����� ��������� ������ ������
        // ��������� ����� �� ������ ������� "i. City: <�������� ������>"
        size_t pos = line.find("City:");
        if (pos != string::npos) {
            string city = line.substr(pos + 5);  // 6 �������� ��� "City:"
            route.addToTail(city);
        }
    }
}


void Train::makeChange() {
    int command = 0;

    while (command != 5) {
        cout << "�������� ����� �������� �� ������ ��������\n1.����������� ������\n2.��� �������\n3.���������� �������\n4.��������� �����\n5.��������� � ����\n";
        cin >> command;
        switch (command) {
        case 1: {
            string nameTrain;
            system("cls");
            cout << "������� ����� ������������ ������\nName of train:";
            cin >> nameTrain;
            setNameTrain(nameTrain);
            cout << "������������ ������ ������� ��������";
            system("pause");
            system("cls");
            break;
        }
        case 2: {
            int yearRelease;
            system("cls");
            cout << "������� ����� ��� ������� ������\nYear of release:";
            cin >> yearRelease;
            setYearRelease(yearRelease);
            cout << "��� ������� ������� �������";
            system("pause");
            system("cls");
            break;
        }
        case 3: {
            int amountWagons;
            system("cls");
            cout << "������� ����� ���������� �������\nAmount of wagons:";
            cin >> amountWagons;
            setAmountWagon(amountWagons);
            cout << "���������� ������� ������� ��������";
            system("pause");
            system("cls");
            break;
        }
        case 4: {
            int volumeLoad;
            system("cls");
            cout << "������� ����� ����������� ������\nVolume of Load:";
            cin >> volumeLoad;
            setVolumeLoad(volumeLoad);
            cout << "����������� ������ ������� ��������\n";
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