#pragma once
#include<string>
#include<iostream>
using namespace std;

typedef string ItemType;
typedef int ItemType2;

class ScheduleList
{
private:
	struct Node
	{
		ItemType date;	// data item
		ItemType2 starttime, endtime, bus, ID;
		ItemType Driver;
		Node* prev;// pointer pointing to prev item	
		Node* next;// pointer pointing to next item
	};
	Node* firstNode;	// point to the first item
	int  size;			// number of items in the list

public:
	ScheduleList();		// constructor
	~ScheduleList();		// distructor

	// add an item to the back of the list (append)
	// pre : size < MAX_SIZE
	// post: item is added to the back of the list
	//       size of list is increased by 1
	bool add(ItemType2 ID, ItemType date, ItemType2 bus, ItemType2 starttime, ItemType2 endtime, ItemType Driver);


	// remove an item at a specified position in the list
	// pre : 0 <= index < size
	// post: item is removed the specified position in the list
	//       items after the position are shifted forward by 1 position
	//       size of list is decreased by 1
	void remove(ItemType2 ID, ItemType date, ItemType2 bus, ItemType2 starttime);

	void update(int index, ItemType2 ID, ItemType date, ItemType2 bus, ItemType2 starttime, ItemType2 endtime);

	// check if the list is empty
	// pre : none
	// post: none
	// return true if the list is empty; otherwise returns false
	bool isEmpty();

	// check the size of the list
	// pre : none
	// post: none
	// return the number of items in the list
	int getLength();


	//------------------- Other useful functions -----------------

	// display the items in the list
	void print();

	bool search(ItemType2 ID, ItemType date, ItemType2 bus, ItemType2 starttime);


	// void replace(int index, ItemType item);
	// int search(ItemType item);
};
