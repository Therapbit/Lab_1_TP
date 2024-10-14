#include "Keeper.h"
#include <iostream>
#include <fstream>
#include "CargoCarrier.h"
void Keeper::addTransport(CargoCarrier* transport) {
    transportList.add(transport);
}

void Keeper::printTransport() const {
    transportList.print(); 
}


void Keeper::clearTransport() {
   
    LNode* current = transportList.getHead();
    while (current != nullptr) {
        LNode* next = current->next;
        delete current->transport;
        delete current;
        current = next;
    }
    transportList = LinkedList(); 
}


void Keeper::saveToFile(string filename) {
    LNode* current = transportList.getHead();

    ofstream file(filename);

    if (file.is_open()) {
        while (current != nullptr) {
            current->transport->saveToFile(file);
            current = current->next;
        }
        file.close();
        cout << "������ � ����." << endl;
    }
    else {
        cout << "�������" << endl;
    }
}


void Keeper::loadFromFile(string filename) {
    int answer = 0;
    
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "������ ������ �����" << endl;
        return;
    }

    cout << "���� ������" << endl;
    cout << "��� �������� ������ �� �����, ������� ��������� ���� ������ ����� ��������. �� ������ ����������?\n1 - ��\n2 - ����� � ����" << endl;
    cin >> answer;
    if (answer == 2) {
        return;
    }
    if (answer != 1 && answer != 2) {
        cout << "�������� ��������. ���������� �����.";
        return;
    }

    

    clearTransport();

    string type;
    
    while (file >> type) {
        CargoCarrier* transport = nullptr;

        if (type == "PLANE")
            transport = new Plane();
        else if (type == "TRAIN")
            transport = new Train();
        else if (type == "CAR")
            transport = new Car();

        if (transport) {
            transport->loadFromFile(file);
            addTransport(transport);
        }

    }

    file.close();
    system("cls");
    cout << "������ ���������� ������� �������� �� �����." << endl;
}


void Keeper::removeTransport() {
    int command = 0;
    string nameTrain, namePlane, numberCar;
    LNode* current = transportList.getHead();
    LNode* prev = nullptr;
    while (command != 4) {
        cout << "�������� �������" << endl;
        cout << "����� ��������� ������ �������?\n1.Train\n2.Plane\n3.Car\n4.��������� � ����\n";
        cin >> command;
        switch (command) {
        case 1: {
            cout << "������� ��� ������:";
            cin >> nameTrain;
            while (current != nullptr) {
                Train* train = dynamic_cast<Train*>(current->transport);
                if (train != nullptr && train->getNameTrain() == nameTrain) {
                    // ���� ����� ������
                    if (prev == nullptr) {
                        // ������� ������ �������
                        transportList.setHead(current->next);
                    }
                    else {
                        // ���������� ������� �������
                        prev->next = current->next;
                    }

                    delete current->transport; // ������� ��� ������ ������������� ��������
                    delete current; // ������� ���� ������

                    cout << "����� � ������ " << nameTrain << " ������� �����." << endl;
                    return;
                }
                prev = current;
                current = current->next;
            }
            cout << "����� � ������ " << nameTrain << "������� ������" << endl;
            break;
        }
        case 2: {
            cout << "������� ��� ��������:";
            cin >> namePlane;
            while (current != nullptr) {
                Plane* plane = dynamic_cast<Plane*>(current->transport);
                if (plane != nullptr && plane->getName() == namePlane) {
                    // ���� ����� ������
                    if (prev == nullptr) {
                        // ������� ������ �������
                        transportList.setHead(current->next);
                    }
                    else {
                        // ���������� ������� �������
                        prev->next = current->next;
                    }

                    delete current->transport; // ������� ��� ������ ������������� ��������
                    delete current; // ������� ���� ������

                    cout << "������� � ������ " << namePlane << " ������� �����." << endl;
                    return;
                }
                prev = current;
                current = current->next;

            }
            break;
        }
        case 3:{
            cout << "������� ����� ������:";
            cin >> numberCar;
            while (current != nullptr) {
                Car* car = dynamic_cast<Car*>(current->transport);
                if (car != nullptr && car->getNumberCar() == numberCar) {
                    // ���� ����� ������
                    if (prev == nullptr) {
                        // ������� ������ �������
                        transportList.setHead(current->next);
                    }
                    else {
                        // ���������� ������� �������
                        prev->next = current->next;
                    }

                    delete current->transport; // ������� ��� ������ ������������� ��������
                    delete current; // ������� ���� ������

                    cout << "������ � ������� " << numberCar << " ������� ������a." << endl;
                    return;
                }
                prev = current;
                current = current->next;

            }
            break;
        }
        case 4: {
            break;
        }
        }
    }
}


void Keeper::changeTransport() {
    int command = 0;
    string nameTrain, namePlane, numberCar;
    LNode* current = transportList.getHead();
    LNode* prev = nullptr;
    while (command != 4) {
        cout << "�������� �������" << endl;
        cout << "����� ��������� ������ ��������?\n1.Train\n2.Plane\n3.Car\n4.��������� � ����\n";
        cin >> command;
        switch (command) {
        case 1: {
            cout << "������� ��� ������:";
            cin >> nameTrain;
            while (current != nullptr) {
                Train* train = dynamic_cast<Train*>(current->transport);
                if (train != nullptr && train->getNameTrain() == nameTrain) {
                    train->makeChange();
                    return;
                }
                prev = current;
                current = current->next;
            }
            break;
        }
        case 2: {
            cout << "������� ��� ��������:";
            cin >> namePlane;
            while (current != nullptr) {
                Plane* plane = dynamic_cast<Plane*>(current->transport);
                if (plane != nullptr && plane->getName() == namePlane) {
                    plane->makeChange();
                    return;
                }
                prev = current;
                current = current->next;

            }
            break;
        }
        case 3: {
            cout << "������� ����� ������:";
            cin >> numberCar;
            while (current != nullptr) {
                Car* car = dynamic_cast<Car*>(current->transport);
                if (car != nullptr && car->getNumberCar() == numberCar) {
                    car->makeChange();
                    return;
                }
                prev = current;
                current = current->next;

            }
            break;
        }
        case 4: {
            break;
        }
        }
    }
}