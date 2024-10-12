#pragma once
#include "CargoCarrier.h"


struct LNode {
	CargoCarrier* transport;
	LNode* next;

	LNode(CargoCarrier* newTransport) : transport(newTransport), next(nullptr) {}
};

class LinkedList
{
	private:
	LNode* head;
	size_t size;
	public:
	LinkedList() : head(nullptr), size(0) {};

	void add(CargoCarrier* transport);
	void print() const;
	void printTypeTransport(int type) const;
	LNode* getHead() { return head; }
	void setHead(LNode* newHead) { head = newHead; }
};

