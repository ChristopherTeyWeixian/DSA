//Done by Christopher Tey(S10193226C)
//Add Function,Print
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
		ItemType2 starttime, endtime, bus, ID; //Data for start time, end time, bus , ID
		Node* prev;// pointer pointing to prev item	
		Node* next;// pointer pointing to next item
	};
	Node* firstNode;	// point to the first item
	int  size;			// number of items in the list

public:
	ScheduleList();		// constructor
	~ScheduleList();		// distructor

	// add an item to the front of the list (append)
	//Input Parameters: ID,Date,Bus, start time and end time
	// pre : size < MAX_SIZE
	// post: item is added to the front of the list
	//       size of list is increased by 1
	//return true when done
	bool add(ItemType2 ID, ItemType date, ItemType2 bus, ItemType2 starttime, ItemType2 endtime);


	// remove an item in the list
	//Input Parameters: ID,Date,Bus and start time
	// pre : size < MAX_SIZE
	// post: item is removed in the list
	//       items after the position are shifted forward by 1 position
	//       size of list is decreased by 1
	void remove(ItemType2 ID, ItemType date, ItemType2 bus, ItemType2 starttime);

	// check if schedule exist
	//Input Parameters: Index,ID,Date,Bus, start time and end time
	// pre : size<MAX_SIZE
	// post: Overwrite the node with the new information
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

	// display the schedules in the list from the latest one
	void print();

	//search if the schedule already exist.
	//Input Parameters: ID,Date,Bus, start time and end time
	//return true if found, else false
	bool search(ItemType2 ID, ItemType date, ItemType2 bus, ItemType2 starttime);
};
