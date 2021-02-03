#include "BusStop.h"

List::List()
{
	firstNode = NULL;//make the first node
	size = 0;
}
List::~List() {}

bool List::add(ItemType item)
{
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	if (firstNode == NULL)//To check if there is an existing node
	{
		//Add item to first node
		firstNode = newNode;
	}

	else //If 1st node not available, traverse to next available node
	{
		Node* current = firstNode;

		while (current->next != NULL)
		{
			current = current->next;
		}

		current->next = newNode;
	}

	size++; //Increase size by 1

	return true;
}
void List::print()
{
	Node* current = firstNode;
	int i = 1;
	while (current != NULL)
	{
		cout <<"["<<i<<"]"<< current->item << endl;
		i++;
		current = current->next;
	}
}
bool List::search(ItemType bitem)
{
	if (firstNode == NULL)
	{
		return false;
	}
	else
	{
		Node* current = firstNode;
		while (current->item != (bitem) && current->next!=NULL)
		{
			current = current->next;
		}
		if (current->item != bitem) 
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}
