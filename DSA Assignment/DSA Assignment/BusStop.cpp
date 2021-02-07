//Done by: Benjamin Tey Zhi Xian(s10197846A)
//add(self organising list)
#include "BusStop.h"

List::List()
{
	firstNode = NULL;//make the first node
	size = 0;
}
List::~List() {}

bool List::add(ItemType item)
{
	//make sure that everything is capitalize
	transform(item.begin(), item.end(), item.begin(), ::toupper);
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
		Node* trail = NULL;
		//tranverse list to find insert location
		while (current->next != NULL)
		{
			if (current->item >= newNode->item) 
			{
				break;
			}
			else
			{
				trail = current;
				current = current->next;
			}
		}

		//case 2 -insert at firstnode(not empty)
		if (current == firstNode) 
		{
			newNode->next = firstNode;
			firstNode = newNode;
		}
		else
		{
			newNode->next = current;
			trail->next = newNode;
		}
	}

	size++; //Increase size by 1

	return true;
}

void remove(int index) 
{

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
//search busstop name
bool List::search(ItemType bitem)
{
	if (firstNode == NULL)
	{
		return false;
	}
	else
	{
		Node* current = firstNode;
		//tranverse through the list and check if the busname and stop just before the null
		while (current->item != (bitem) && current->next!=NULL)
		{
			current = current->next;
		}
		//if the last node is not equal to the bitem
		if (current->item != bitem) 
		{
			return false;
		}
		//Else meaning that the last node is the seach item
		else
		{
			return true;
		}
	}
}
void List::remove(int index)
{
	if ((index >= 0) && (index <= size))// make sure the index is more than 0 and does not exceed the current size
	{
		cout << "asd" << endl;
		Node* temp1 = firstNode;

		if (index == 1)
		{
			firstNode = temp1->next;
			size--;
		}

		else
		{
			int i;
			for (i = 0; i < index - 2; i++)
			{
				temp1 = temp1->next;
			}

			Node* temp2 = temp1->next;
			temp1->next = temp2->next;
			size--;
		}
	}	
	else
	{
		cout << "Invalid Index" << endl;
	}
}

//get BusStop name based on index
ItemType List::get(int index)
{
	// make sure it does not exceed the list size
	bool success = (index >= 0) && (index <= size);
	Node* temp = firstNode;
	if (success) 
	{
		//a int to keep track of index
		int counter = 1;
		//tranverse through the list until it reach the index
		while(counter!=index)
		{
			temp = temp->next;
			counter++;
		}
		//return the index
		return (temp->item);
	}
	//If it exceed the list size return invalid
	else
	{
		return "Invalid Index";
	}
}

void List::update(int index, ItemType item)
{
	// make sure it does not exceed the list size
	bool success = (index >= 0) && (index <= size);
	Node* temp = firstNode;
	if (success)
	{
		//a int to keep track of index
		int counter = 1;
		//tranverse through the list until it reach the index
		while (counter != index)
		{
			temp = temp->next;
			counter++;
		}
		//return the index
		temp->item = item;
	}
}