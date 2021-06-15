//Tree.h
#pragma once
#include "Node.h"
#include <queue>

template <class T>
class BST {
public:
	BST();					//constructor
	~BST();					//deconstructor
	void insert(T item);	//insert an item into the tree
	void erase(T item);		//searches for an item and erases it from the tree if it exists
	int size();				//return size of tree
	bool empty();			//return isEmpty bool
	bool find(T item);		//search for item, return isFound bool
	void breadthTraverse();	//traverse and print items
	void depthTraverse();	//Traverse and print items
	node<T>* getRootPtr();  //returns a pointer to root node
	T showRoot();			//return value of root of tree

private:
	bool findPrivate(T item);
	void insertPrivate(T item, node<T>* ptr);
	node<T>* erasePrivate(T item, node<T>* ptr);
	node<T>* findMinimum(node<T>* ptr);
	void depthTraversePrivate(node<T>* ptr);
	void breadthTraversePrivate(node<T>* ptr);
	node<T>* root;
	node<T>* newNode(T item);
	int tSize;
	void removeSubtree(node<T>* ptr);
};

#include "Tree.cpp"