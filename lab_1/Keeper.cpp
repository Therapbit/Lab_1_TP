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
        cout << "Запись в файл." << endl;
    }
    else {
        cout << "Неуспех" << endl;
    }
}


void Keeper::loadFromFile(string filename) {
    int answer = 0;
    
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Ошибка чтения файла" << endl;
        return;
    }

    cout << "Файл открыт" << endl;
    cout << "При загрузке данных из файла, текущие внесенные вами данные будут отчищены. Вы хотите продолжить?\n1 - Да\n2 - Выйти в меню" << endl;
    cin >> answer;
    if (answer == 2) {
        return;
    }
    if (answer != 1 && answer != 2) {
        cout << "Неверное значение. Попробуйте снова.";
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
    cout << "Список транспорта успешно загружен из файла." << endl;
}


void Keeper::removeTransport() {
    int command = 0;
    string nameTrain, namePlane, numberCar;
    LNode* current = transportList.getHead();
    LNode* prev = nullptr;
    while (command != 4) {
        cout << "Выберите команду" << endl;
        cout << "Какой транспорт хотите удалить?\n1.Train\n2.Plane\n3.Car\n4.Вернуться в меню\n";
        cin >> command;
        switch (command) {
        case 1: {
            cout << "Введите имя поезда:";
            cin >> nameTrain;
            while (current != nullptr) {
                Train* train = dynamic_cast<Train*>(current->transport);
                if (train != nullptr && train->getNameTrain() == nameTrain) {
                    // Если поезд найден
                    if (prev == nullptr) {
                        // Удаляем первый элемент
                        transportList.setHead(current->next);
                    }
                    else {
                        // Пропускаем текущий элемент
                        prev->next = current->next;
                    }

                    delete current->transport; // Удаляем сам объект транспортного средства
                    delete current; // Удаляем узел списка

                    cout << "Поезд с именем " << nameTrain << " успешно удалён." << endl;
                    return;
                }
                prev = current;
                current = current->next;
            }
            cout << "Поезд с именем " << nameTrain << "Успешно удален" << endl;
            break;
        }
        case 2: {
            cout << "Введите имя самолета:";
            cin >> namePlane;
            while (current != nullptr) {
                Plane* plane = dynamic_cast<Plane*>(current->transport);
                if (plane != nullptr && plane->getName() == namePlane) {
                    // Если поезд найден
                    if (prev == nullptr) {
                        // Удаляем первый элемент
                        transportList.setHead(current->next);
                    }
                    else {
                        // Пропускаем текущий элемент
                        prev->next = current->next;
                    }

                    delete current->transport; // Удаляем сам объект транспортного средства
                    delete current; // Удаляем узел списка

                    cout << "Самолет с именем " << namePlane << " успешно удалён." << endl;
                    return;
                }
                prev = current;
                current = current->next;

            }
            break;
        }
        case 3:{
            cout << "Введите номер машины:";
            cin >> numberCar;
            while (current != nullptr) {
                Car* car = dynamic_cast<Car*>(current->transport);
                if (car != nullptr && car->getNumberCar() == numberCar) {
                    // Если поезд найден
                    if (prev == nullptr) {
                        // Удаляем первый элемент
                        transportList.setHead(current->next);
                    }
                    else {
                        // Пропускаем текущий элемент
                        prev->next = current->next;
                    }

                    delete current->transport; // Удаляем сам объект транспортного средства
                    delete current; // Удаляем узел списка

                    cout << "Машина с номером " << numberCar << " успешно удаленa." << endl;
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
        cout << "Выберите команду" << endl;
        cout << "Какой транспорт хотите изменить?\n1.Train\n2.Plane\n3.Car\n4.Вернуться в меню\n";
        cin >> command;
        switch (command) {
        case 1: {
            cout << "Введите имя поезда:";
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
            cout << "Введите имя самолета:";
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
            cout << "Введите номер машины:";
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