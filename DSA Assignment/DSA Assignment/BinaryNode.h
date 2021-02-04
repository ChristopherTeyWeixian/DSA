#pragma once
typedef int ItemType2;
typedef string ItemType1;
struct BinaryNode
{
	ItemType2 ID;		// data item
	ItemType1 Name;
	ItemType2 age;
	ItemType1 status;
	BinaryNode* left;	// pointer pointing to left subtree
	BinaryNode* right;	// pointer pointing to right subtree
};
