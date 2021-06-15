#pragma once
#include "Tree.h"
#include "Node.h"
#include <stack>

template <class T> 
class bstIterator {
public:
	bstIterator(node<T>* root) {
		fillStack(root);
	}

	void fillStack(node<T>* ptr) {
		while (ptr != nullptr) {
			s.push(ptr);
			ptr = ptr->left;
		}
	}

	T next() {
		node<T>* current = s.top();
		s.pop();
		if (current->right != nullptr) {
			fillStack(current->right);
		}
		return current->value;
	}

	bool hasNext() {
		return !s.empty();
	}

private:
	std::stack<node<T>*> s; 
};

