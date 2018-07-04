#include"PriorityQueue.h"

void PriorityQueue::push(BinaryTree* e) {

	if (empty()) // daca coada este vida elementul este adaugat la inceput
	{
		first = e;
		return;
	}
	// daca elementul este in relatie cu primul element, adaugarea acestuia se face la inceput
	if (relation(*e, *first))
	{
		BinaryTree *aux = first;
		first = e;
		e->next = aux;
		return;
	}
	// Se itereaza prin coada si se adauga elementul in fata elementului cu care este in relatie.
	BinaryTree *pre = first;
	BinaryTree *current = first;
	while (current != nullptr) {
		if (relation(*e, *current))
			break;
		pre = current;
		current = current->next;
	}
	pre->next = e;
	e->next = current;
}

void PriorityQueue::pop() {
	if (first != nullptr) {
		BinaryTree* aux = first;
		first = first->next;
		delete aux;	
	}

}

BinaryTree* PriorityQueue::front() const {
	return first;
}

bool PriorityQueue::empty() const {
	if (first == nullptr)
		return true;
	return false;
}

int PriorityQueue::size() const {
	BinaryTree* aux;
	aux = first;
	int counter = 0;
	while (aux != nullptr) {
		counter++;
		aux = aux->next;
	}
	return counter;
}