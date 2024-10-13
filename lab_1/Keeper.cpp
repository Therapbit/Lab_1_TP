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

