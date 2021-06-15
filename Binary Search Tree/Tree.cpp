//Tree.cpp

#ifndef _TREE_CPP_
#define _TREE_CPP_
#include "Tree.h"

using namespace std;

//constructor
template <class T>
BST<T>::BST() {
	root = nullptr;
	this->tSize = 0;
}


//deconstructor
template <class T>
BST<T>::~BST() {
	removeSubtree(root);
}


//removes node and everyhing in its subtree using post-order traversal - private
template <class T>
void BST<T>::removeSubtree(node<T>* ptr) {
	if (ptr != nullptr) {
		if (ptr->left != nullptr) {
			removeSubtree(ptr->left);
		}
		if (ptr->right != nullptr) {
			removeSubtree(ptr->right);
		}
		delete ptr;
	}
}


//search for an item in the tree - public
template <class T>
bool BST<T>::find(T item) {
	return this->findPrivate(item);
}


//search - private
template <class T>
bool BST<T>::findPrivate(T item) {
	node<T>* ptr = root;
	bool found = false;

	while (ptr != nullptr) {
		if (ptr->value == item) {
			found = true;
			break;
		}
		else if (item < ptr->value) {
			ptr = ptr->left;
		}
		else {
			ptr = ptr->right;
		}
	}
	return found;
}

template <class T> 
node<T>* BST<T>::getRootPtr() {
	return root; 
}


//returns current root of tree - public
template<class T>
T BST<T>::showRoot() {
	return root->value;
}


//returns the size of tree - public
template <class T>
int BST<T>::size() {
	return this->tSize;
}


//returns whether the tree is empty or not - public
template <class T>
bool BST<T>::empty() {
	if (root == nullptr) {
		return true;
	}
	else {
		return false;
	}
}


//creates new node whenever insert function is called - private
template<class T>
node<T>* BST<T>::newNode(T item) {
	node<T>* n = new node<T>;
	n->value = item;
	n->left = n->right = nullptr;
	this->tSize++;
	return n;
}


//insert a new node in tree - public
template <class T>
void BST<T>::insert(T item) {
	insertPrivate(item, root);
}


//insert - private
template <class T>
void BST<T>::insertPrivate(T item, node<T>* ptr) {
	if (root == nullptr) {
		root = newNode(item);

	}
	else if (item < ptr->value) {
		if (ptr->left != nullptr) {
			this->insertPrivate(item, ptr->left);
		}
		else {
			ptr->left = newNode(item);
		}
	}
	else if (item > ptr->value) {
		if (ptr->right != nullptr) {
			this->insertPrivate(item, ptr->right);
		}
		else {
			ptr->right = newNode(item);
		}
	}
}


//find and erase a specific item from the tree - public
template <class T>
void BST<T>::erase(T item) {
	erasePrivate(item, root);
}


//erase - private
template <class T>
node<T>* BST<T>::erasePrivate(T item, node<T>* ptr) {
	//empty tree
	if (root == nullptr) return ptr;
	//search
	else if (item < ptr->value) ptr->left = erasePrivate(item, ptr->left);
	else if (item > ptr->value) ptr->right = erasePrivate(item, ptr->right); 

	else {		//item is found
				//case 1 : found node has no children
		if (ptr->left == nullptr && ptr->right == nullptr) {
			delete ptr;
			ptr = nullptr;
			this->tSize--;
		}
		//case 2 : found node has one child
		else if (ptr->left == nullptr) {
			node<T>* temp = ptr;
			ptr = ptr->right;
			delete temp;
			this->tSize--;
		}
		else if (ptr->right == nullptr) {
			node<T>* temp = ptr;
			ptr = root->left;
			delete temp;
			this->tSize--;
		}
		//case 3 : found node has two children
		else {
			node<T>* temp = findMinimum(ptr->right);	//find minimum item in right subtree
			ptr->value = temp->value;
			ptr->right = erasePrivate(temp->value, ptr->right);
		}
	}
	return ptr;
}


//finds the minimum item in the right subtree of any node, helper function for erase function - private
template<class T>
node<T>* BST<T>::findMinimum(node<T>* ptr) {
	while (ptr->left != nullptr) ptr = ptr->left;
	return ptr;
}


//level-order traversal - public
template <class T>
void BST<T>::breadthTraverse() {
	breadthTraversePrivate(root);
}


//print contents of tree in level-order format using a queue - private
template <class T>
void BST<T>::breadthTraversePrivate(node<T>* ptr) {
	queue<node<T>*> q;

	if (ptr == nullptr) {
		return;
	}
	q.push(ptr);

	while (!q.empty()) {		//while loop to utilize queue for printing items
		node<T>* current = q.front();
		cout << current->value << " ";

		if (current->left != nullptr) q.push(current->left);
		if (current->right != nullptr) q.push(current->right);

		q.pop();
	}
}


//in-order traversal - public
template <class T>
void BST<T>::depthTraverse() {
	depthTraversePrivate(root);
}


//prints contents of tree using in-order traversal - private
template <class T>
void BST<T>::depthTraversePrivate(node<T>* ptr) {
	if (root != nullptr) {
		if (ptr->left != nullptr) {
			depthTraversePrivate(ptr->left);
		}
		cout << ptr->value << " ";

		if (ptr->right != nullptr) {
			depthTraversePrivate(ptr->right);
		}
	}
	else {
		cout << "The tree is empty" << endl;
	}
}

#endif // !_TREE_CPP_