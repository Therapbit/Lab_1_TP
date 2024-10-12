#include "Keeper.h"
#include <iostream>
#include <fstream>

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