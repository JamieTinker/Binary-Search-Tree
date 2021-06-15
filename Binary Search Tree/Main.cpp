// Jamie Tinker
// Binary Search Tree Implementation
//
// Required files: Node.h, Tree.h, Tree.cpp
//
// Main.cpp

#include <iostream>
#include "Tree.h"
#include "BSTIterator.h"

using namespace std;

int main() {
	//demonstration of BST functions
	BST<int> bstObject;
	
	cout << "Welcome to the Binary search tree demonstration: " << endl << endl;

	cout << "The size of BST is currently: " << bstObject.size() << endl << endl;

	cout << "Is the BST empty? " << bstObject.empty() << endl << endl;

	cout << "------------------------------------------------" << endl << endl;

	cout << "We will now insert 12 integers to the tree in this order:" << endl
		<< "{9, 5, 11, 3, 7, 14, 10, 1, 4, 6, 8, 15}.." << endl << endl;

	bstObject.insert(9);
	bstObject.insert(5);
	bstObject.insert(11);
	bstObject.insert(3);
	bstObject.insert(7);
	bstObject.insert(14);
	bstObject.insert(10);
	bstObject.insert(1);
	bstObject.insert(4);
	bstObject.insert(6);
	bstObject.insert(8);
	bstObject.insert(15);

	cout << "The root of the tree is: " << bstObject.showRoot() << endl << endl;

	cout << "The tree now has " << bstObject.size() << " objects" << endl << endl;

	cout << "Is the tree still empty? " << bstObject.empty() << endl << endl;

	cout << "The contents of the tree will now be printed in order from least to greatest " << endl <<
		"demonstrating the depth first traversal function.." << endl << endl;

	bstObject.depthTraverse();

	cout << endl << endl << "-----------------------------------------" << endl << endl;

	cout << "We will now search for the item 8 in the tree.." << endl << endl;

	cout << "Was the item found in the tree? " << bstObject.find(8) << endl << endl;

	cout << "We will now search for the item 21 in the tree.." << endl << endl;

	cout << "Was the item found in the tree? " << bstObject.find(21) << endl << endl;

	cout << "-------------------------------------------" << endl << endl;

	cout << "The contents of the tree will now be printed in level order, demonstrating the  " << endl <<
		"breadth first traversal function..... " << endl << endl;

	bstObject.breadthTraverse();

	cout << endl << endl << "----------------------------------------------" << endl << endl;

	cout << "The size of BST is currently: " << bstObject.size() << endl << endl;

	cout << "We will now use the erase function to erase the root 9, the item 1, and the item 11.." << endl << endl;

	bstObject.erase(9);
	bstObject.erase(1);
	bstObject.erase(11);

	cout << "The size of BST is currently: " << bstObject.size() << endl << endl;

	cout << "We will use the breadth first traversal function to varify that the deletion worked correctly.." << endl << endl;

	bstObject.breadthTraverse();

	cout << endl << endl << "The root of the tree is now: " << bstObject.showRoot();
	
	//testing iterator
	cout << endl << endl << "----------------------------------------------" << endl << endl;

	cout << "Testing BST iterator: " << endl << endl; 

	bstIterator<int> iter(bstObject.getRootPtr());

	while (iter.hasNext() == 1){
		cout << "Has Next? " << iter.hasNext() << endl << "Next : " << iter.next() << endl;
	}

	cout << endl << "End of demonstration." << endl << endl;
	
	cin.get(); //console waits for enter to be pressed
}