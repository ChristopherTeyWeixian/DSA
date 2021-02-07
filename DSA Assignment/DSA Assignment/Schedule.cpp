#include "Schedule.h"
//Done by Christopher Tey(S10193226C)
//Add Function,Print
ScheduleList::ScheduleList()
{
	firstNode = NULL;
	size = 0;
}

ScheduleList::~ScheduleList() {}

//Adding of Schedue to the member ID
bool ScheduleList::add(ItemType2 ID, ItemType date, ItemType2 bus, ItemType2 starttime, ItemType2 endtime)
{
	Node* newNode = new Node;
	newNode->ID = ID;
	newNode->date = date;
	newNode->bus = bus;
	newNode->starttime = starttime;
	newNode->endtime = endtime;
	newNode->prev = NULL;
	newNode->next = NULL;

	if (firstNode == NULL)
	{
		//Add item to first node
		firstNode = newNode;
	}

	else
	{
		firstNode->prev = newNode;
		newNode->next = firstNode;
		firstNode = newNode;
	}

	size++; //Increase size by 1

	return true;
}

void ScheduleList::remove(ItemType2 ID, ItemType date, ItemType2 bus, ItemType2 starttime)
{
}


//Update existing schedule with new information
void ScheduleList::update(int index, ItemType2 ID, ItemType date, ItemType2 bus, ItemType2 starttime, ItemType2 endtime) {}

//check if list is empty or not
bool ScheduleList::isEmpty() { return size == 0; }

//return size of list
int ScheduleList::getLength() { return size; }

// display the schedules in the list from the latest one
void ScheduleList::print()
{
	Node* current = firstNode;
	cout << "Schedule List" << endl;
	cout << "==================" << endl;
	while (current != NULL)
	{
		cout << "ID:" << current->ID << endl;
		cout << "Date:" << current->date << endl;
		cout << "Bus:" << current->bus << endl;
		cout << "Start Shift:" << current->starttime << endl;
		cout << "End Shift:" << current->endtime << endl;
		cout << "\n";
		current = current->next;
	}
}

//Checks whether the value x is present in linked list 
bool ScheduleList::search(ItemType2 ID, ItemType date, ItemType2 bus, ItemType2 starttime)
{
	return 0;
}
