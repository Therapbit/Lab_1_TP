#pragma once
#include <string>
using namespace std;

struct Node {
	string city;
	int hour;
	Node* next;
};

class List
{
private:
	Node* head;

public:

    List() : head(nullptr) {}

	//~List();

	void addToTail(string city, int hour=0);
	Node& operator[](int index);
	void print(int index);
	Node* getHead() { return head; }
};

