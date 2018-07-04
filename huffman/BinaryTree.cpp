#include"BinaryTree.h"


void BinaryTree::destroyNode(Node** r) {
	if (*r != nullptr) {

		destroyNode(&(*r)->left); // apeluri recursive de distrugere a fiecarui nod
		destroyNode(&(*r)->right);
		delete *r;
	}
}

void BinaryTree::createLeaf(const TElement& e) {
	root = new Node(e);
}

const TElement& BinaryTree::getTElement() const {
	return root->e;
}

BinaryTree* BinaryTree::getNext() const {
	return next;
}

Node* BinaryTree::getRoot() const {
	return root;
}
void BinaryTree::addLeftTree(Node* left) {
	root->setLeft(left);
}

void BinaryTree::addRightTree(Node* right) {
	root->setRight(right);
}
