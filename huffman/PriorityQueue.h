#pragma once
#include"BinaryTree.h"
typedef int(*TRelation)(const BinaryTree& bt1, const BinaryTree& bt2);

/*
	Functia de relatie
	Un arbore este in relatie cu altul daca, frecventa sa din informatia utila din radacina este mai mica
	sau egala cu frecventa celuilalt.
	Returneaza:   1, daca un arbore este in relatie cu celalalt
				  0, atfel
*/
inline  int getPriority(const BinaryTree& bt1, const BinaryTree& bt2) {
	int frq1 = bt1.getTElement().getFrequency();
	int frq2 = bt2.getTElement().getFrequency();

	return frq1-frq2<=0? 1 : 0;
}

/*
	Fiecare coada de prioritati este definita de o relatie intre elementele ei si contine
	adresa primului element din aceasta.
*/
class PriorityQueue {

	TRelation relation;
	BinaryTree* first;

public:
	// Constructorul clasei
	PriorityQueue() {
		relation = getPriority;
		first = nullptr;
	}
	/*
		Functie de adaugare a elementelor pastrandu-se ordinea acestora.
	*/
	void push(BinaryTree* e);
	/*
		Elementul de prioritate maxima este extras din coada.
	*/
	void pop();
	/*
		Este returnat elementul de prioritate maxima, dar acesta nu este eliminat
		din coada.
	*/
	BinaryTree* front() const;
	/*
		Returneaza: 1 ,daca coada este goala
					0, altfel 
	*/
	bool empty() const;
	/*
		Returneaza dimensiunea curenta a cozii( numarul de elemente stocate).
	*/
	int size() const;
	/*
		Destructorul clasei.
	*/
	~PriorityQueue() {
		while (first != nullptr) {
			BinaryTree* aux = first->next;
			delete first;
			first = aux;
		}
		
	}
};