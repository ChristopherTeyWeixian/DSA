//Done by: Benjamin Tey Zhi Xian(s10197846A)
#pragma once
#include<string>
#include<iostream>

#include<algorithm>
using namespace std;

typedef string ItemTyp;
typedef string ItemType;

class BList
{
private:
	struct Node
	{
		ItemTyp busstop;
		ItemType item;
		Node* next;
	};

	Node* firstNode;	// point to the first item
	int  size;		// number of items in the list

public:
	// constructor
	BList();

	// destructor
	~BList();

	// add an item to the back of the list (append)
	bool add(ItemType item);

	
	//create a bus and add a busroute to it.
	bool append(ItemType item, ItemTyp busstop );

	bool search(ItemType item);
	// add an item at a specified position in the list (insert)
	bool add(int index, ItemType item);

	// remove an item at a specified position in the list
	void remove(int index);

	// get an item at a specified position of the list (retrieve)
	ItemType get(int index);

	// check if the list is empty
	bool isEmpty();

	// check the size of the list
	int getLength();

	
	void print();

	void printroute(ItemType item);
};
