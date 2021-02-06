#include "BinaryNode.h"

class BST
{
private:

	BinaryNode* root;		// root of the BST

public:

	// constructor
	BST();

	// search an item in the binary search tree
	BinaryNode* search(ItemType2 target, ItemType1 name);
	BinaryNode* search(BinaryNode* root, ItemType2 target, ItemType1 name);

	// insert an item to the binary search tree
	void insert(ItemType2 ID, ItemType1 Name, ItemType2 age, ItemType1 status);
	void insert(BinaryNode*& root, ItemType2 ID, ItemType1 Name, ItemType2 age, ItemType1 status);

	//Update an item's node in the binary search tree
	BinaryNode* Update(ItemType2 target, ItemType1 status);
	BinaryNode* Update(BinaryNode* t, ItemType2 target, ItemType1 status);

	// delete an item from the binary search tree
	void remove(ItemType2 target);
	void remove(BinaryNode*& root, ItemType2 target);

	// traverse the binary search tree in inorder
	void inorder();
	void inorder(BinaryNode* t);

	// traverse the binary search tree in preorder
	void preorder();
	void preorder(BinaryNode* t);

	// traverse the binary search tree in postorder
	void postorder();
	void postorder(BinaryNode* t);

	// check if the binary search tree is empty
	bool isEmpty();

	// ---------------- to be implemented -------------------

	// count the number of nodes in the binary search tree
	int countNodes();
	int countNodes(BinaryNode* t);

	// compute the height of the binary search tree
	int getHeight();
	int getHeight(BinaryNode* t);

	// check if the binary search tree is balanced
	bool isBalanced();
	bool isBalanced(BinaryNode* t);



};
