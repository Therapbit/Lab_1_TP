#include "LinkedList.h"
#include <iostream>
#include "Plane.h"
#include "Train.h"
#include "Car.h"

using namespace std;



void LinkedList::add(CargoCarrier* transport) {
    LNode* newNode = new LNode{ transport };
    if (head == nullptr) {
        head = newNode;
    }
    else {
        LNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    ++size;
}

void LinkedList::print() const {
    LNode* current = head;
    while (current != nullptr) {
        current->transport->print();
        current = current->next;
    }
}


void LinkedList::printTypeTransport(int type) const {
    LNode* current = head;
    while (current != nullptr) {
        
        if (dynamic_cast<Plane*>(current->transport) && type == 1) {
           
            current->transport->print(); 

        }
        else if (dynamic_cast<Train*>(current->transport) && type == 2) {
           
            current->transport->print(); 

        }
        else if (dynamic_cast<Car*>(current->transport) && type == 3) {
           
            current->transport->print(); 

        }
        current = current->next;
    }
}