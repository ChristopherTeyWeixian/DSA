//Done by: Benjamin Tey Zhi Xian(s10197846A)
//Append
#include "Bus.h"

BList list;

BList::BList()
{
	firstNode = NULL;//make the first node
	size = 0;

}
BList::~BList() {}

bool BList::add(ItemType item)
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



void BList::print()
{
	Node* current = firstNode;
	int i = 1;
	//print everything in the linked list
	//cout << "Bus route for :" << current->item << endl;
	//current = current->next;
	cout << "The Bus Route for: " << current->item << endl;
	while (current != NULL )
	{
		cout <<"["<<i<<"]"<<current->busstop << endl;
		current = current->next;
		i++;
	}
}
void BList::printroute(ItemType item)
{
	Node* current = firstNode;
	int i=1;
	while (current != NULL) 
	{
		if (current->item == item) 
		{
			cout << "[" << i << "]" << current->busstop << endl;
			i++;
		}
		current = current->next;
	}
	
}

bool BList::append(ItemType item, ItemTyp busstop)
{
	//the node for the new bus route
	Node* newNode = new Node;
	newNode->busstop = busstop;
	newNode->item = item;
	newNode->next = NULL;
	//If the first node is empty just input it in
	if (firstNode == NULL) 
	{
		firstNode = newNode;
	}
	//check the first node
	else if (firstNode->item == item) 
	{
		Node* current = firstNode;
		//check if the next node is not empty
		while (current->next != NULL) 
		{
			//check if the busstop belongs to the specified bus
			if (current->next->item != item) 
			{
				//stop at the position
				break;
			}
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
		
	}
	else if (firstNode->item != item) 
	{
		Node* current = firstNode;
		while (current->item!=item && current->next !=NULL)
		{
			current = current->next;
		}
		//if a certain bus is in between different buses
		if (current->item == item) 
		{
			while (current->next != NULL)
			{
				if (current->next->item != item)
				{
					break;
				}
				current = current->next;
			}
			newNode->next = current->next;
			current->next = newNode;
		}
		//If there is no such (61 bus) then it will just add at the end of the list
		else if(current->next==NULL)
		{
			current->next = newNode;
			
		}
		size++;
		return true;
	}
	
}

bool BList::search(ItemType bitem)
{
	//If list is empty so just return false
	if (firstNode == NULL)
	{
		return false;
	}
	else
	{
		//temp node to traverse through the list
		Node* current = firstNode;
		//if the busItem(bitem) is not found and if there is no more node to traverse to
		//It will repeat the while loop
		while (current->item != (bitem) && current->next != NULL)
		{
			current = current->next;
		}
		//When the program reaches here it means its on its lst node
		if (current->item != bitem)
		{
			return false;
		}
		//or there is a matching item in the linked list
		else
		{
			return true;
		}
	}
}




