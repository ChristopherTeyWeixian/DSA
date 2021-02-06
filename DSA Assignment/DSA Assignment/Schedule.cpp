#include "Schedule.h"

ScheduleList::ScheduleList()
{
	firstNode = NULL;
	size = 0;
}

ScheduleList::~ScheduleList() {}

bool ScheduleList::add(ItemType2 ID, ItemType date, ItemType2 bus, ItemType2 starttime, ItemType2 endtime, ItemType Driver)
{
	Node* newNode = new Node;
	newNode->ID = ID;
	newNode->date = date;
	newNode->bus = bus;
	newNode->starttime = starttime;
	newNode->endtime = endtime;
	newNode->Driver = Driver;
	newNode->prev = NULL;
	newNode->next = NULL;

	if (firstNode == NULL)
	{
		//Add item to first node
		firstNode = newNode;
	}

	else //If 1st node not available, traverse to next available node
	{
		firstNode->prev = newNode;
		newNode->next = firstNode;
		firstNode = newNode;
	}

	size++; //Increase size by 1

	return true;
}

/*
void ScheduleList::remove(ItemType2 ID, ItemType date, ItemType2 bus, ItemType2 starttime)
{
	Node* CurrentNode = firstNode;
	while (CurrentNode != NULL)
	{
		CurrentNode = CurrentNode->next;
	}

	if (CurrentNode->ID == ID && CurrentNode->date == date && CurrentNode->bus == bus && CurrentNode->starttime == starttime)
	{
		if (firstNode->next == NULL)
		{
			firstNode = NULL;

		}
		else {
			CurrentNode->prev->next = CurrentNode->next;
			CurrentNode->next->prev = CurrentNode->prev;
		}

	}

	delete CurrentNode;
	size -= 1;
}
*/
void ScheduleList::update(int index, ItemType2 ID, ItemType date, ItemType2 bus, ItemType2 starttime, ItemType2 endtime) {}
bool ScheduleList::isEmpty() { return size == 0; }

int ScheduleList::getLength() { return size; }

void ScheduleList::print()
{
	Node* current = firstNode;
	cout << "Schedule List" << endl;
	cout << "==================" << endl;
	while (current != NULL)
	{
		cout << "ID:" << current->ID << endl;
		cout << current->Driver << endl;
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
