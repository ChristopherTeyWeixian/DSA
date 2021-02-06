#pragma once
//Done by Christopher Tey(S10193226C)
typedef int ItemType2;
typedef string ItemType1;
struct BinaryNode
{
	ItemType2 ID;		// data ID
	ItemType1 Name; //data name
	ItemType2 age; // data age
	ItemType1 status; //data status
	BinaryNode* left;	// pointer pointing to left subtree
	BinaryNode* right;	// pointer pointing to right subtree
};
