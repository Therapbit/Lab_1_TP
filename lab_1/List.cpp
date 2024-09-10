#include "List.h"
#include <iostream>


//List::~List() 
//{
//     while (head != nullptr) 
//     {
//         Node* temp = head;
//         head = head->next;
//         delete temp;
//     }
//}


void List::addToTail(string city, int hour) {
    Node* newNode = new Node{ city, hour, nullptr };
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}


Node& List::operator[](int index) {
    Node* current = head;
    int count = 0;

    while (current != nullptr) {
        if (count == index) {
            return *current;
        }
        current = current->next;
        count++;
    }
}

void List::print(int index) {
    Node& node = (*this)[index];
    cout << "City: " << node.city << endl;
}
    