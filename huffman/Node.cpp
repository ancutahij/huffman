#include"Node.h"

const TElement& Node::getTElement() const {
	return e;
}

Node* Node::getLeft() const {
	return left;
}

Node* Node::getRight() const {
	return right;
}

void Node::setLeft(Node* l) {
	left = l;
}
void Node::setRight(Node* r) {
	right = r;
}

Node* Node::getDeepCopy(Node* e) {
	Node* nodAux = new  Node(e->getTElement()); // nodului curent i se atribuie o noua adresa si se copie informatia utila
	if (e->getLeft() != nullptr)	// se restabilesc legaturile
		nodAux->setLeft(getDeepCopy(e->getLeft()));
	if (e->getRight() != nullptr)
		nodAux->setRight(getDeepCopy(e->getRight()));
	return nodAux;
}
Node&  Node::operator=(const Node& t) {
	e = t.e;
	if (t.left != nullptr)
		setLeft(getDeepCopy(t.left));
	if (t.right!= nullptr)
		setRight(getDeepCopy(t.right));
	return *this;
}



