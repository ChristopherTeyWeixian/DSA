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

		while (current->next != NULL)
		{
			current = current->next;
		}

		current->next = newNode;
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
void List::remove(int index)
{
	if (0 < index <= size)// make sure the index is more than 0 and does not exceed the current size
	{
		Node* temp1 = firstNode;

		if (index == 1)
		{
			firstNode = temp1->next;
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
		}

		size--;
	}
}

ItemType List::get(int index)
{
	bool success = (index >= 0) && (index <= size);
	Node* temp = firstNode;
	if (success) 
	{
		int counter = 1;
		while(counter!=index)
		{
			temp = temp->next;
			counter++;
		}
		return (temp->item);
	}
		
}
