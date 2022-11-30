#include <iostream>

using namespace std;

enum Sides {
	LEFT,
	RIGHT
};


class Node {
	
public:
	int value;
	Node* left;
	Node* right;
	
	Node() {
		value = 0;
		left = NULL;
		right = NULL;
	}
	
	Node(int _value) {
		value = _value;
		left = NULL;
		right = NULL;
	}
	
	Node(int _value, Node* _left, Node* _right) {
		value = _value;
		left = _left;
		right = _right;
	}
};


class Tree {
	
private:
	int spaces;	

public:
	Node* firstNode;
	int depth;
	
	Tree() {
		firstNode = NULL;
		depth = 0;
	}
	
	Tree(Node* node) {
		firstNode = node;
	}
	
	Tree(int* values, int n){
		firstNode = new Node(values[0]);
		
		for(int i = 1; i < n; i++) {
			add(values[i], firstNode);
		}
		
	}
	
	void add(int value, Node* parent) {
		if (value < parent->value) {
			if (parent->left == NULL) {
				parent->left = new Node(value);
			}
			else {
				this->add(value, parent->left); 
			}
		} else {
			if (parent->right == NULL) {
				parent->right = new Node(value);
			}
			else {
				this->add(value, parent->right); 
			}	
		}
	}
	
	void showTree() {
		spaces = 0;
		showSubTree(firstNode);	
	}
	
	void showSubTree(Node* node) {
		
		if (node == NULL) return;
		spaces++;
		
		showSubTree(node->left);
		
		for (int i = 0; i < spaces; i++) cout << " ";
		cout << node->value << endl;
		
		showSubTree(node->right);
		
		spaces--;
	}

};




int main() {
	int n = 0;
	
	cout << "Enter the number of nodes: ";
	cin >> n;
	
	int* values = new int(n);
	for (int i = 0; i < n; i++) {
		cin >> values[i];
	}
	
	Tree tree(values, n);
	tree.showTree();
}