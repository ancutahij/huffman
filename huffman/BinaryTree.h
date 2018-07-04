#pragma once
#include"Node.h"
class PriorityQueue;
/*
	Fiecare arbore contine:
	-adresa catre radacina
	-adresa catre urmatorul nod din coada cu prioritati
*/
class BinaryTree {
	Node* root;
	BinaryTree* next;
	/*
		Functie de distrugere a unui arbore
	*/
	void destroyNode(Node** r);
	friend class PriorityQueue;
public:
	/*
		Constructorii pentru clasa BinaryTree.
		Sunt acomodate mai multe tipuri de date pentru instantierea unui obiect de tip BinaryTree
	*/

	// Este oferita doar informatia utila
	BinaryTree(const TElement& e) {
		root = new Node(e);
		next = nullptr;
	}
	// Construcotul default
	BinaryTree() {
		root = nullptr;
		next = nullptr;
	}
	// Este oferita atat informatia utila, cat si legaturile din stanga si dreapta radacinii.
	BinaryTree(const TElement& e, Node* left, Node* right){

		root = new Node{ e };
		root->setLeft(left);
		root->setRight(right);
		next = nullptr;

	}
	/*
		Legatura din stanga nodului va fi inlocuita cu cea data ca parametru.
	*/
	void addLeftTree(Node* left);
	/*
		Legatura din dreapta nodului va fi inlocuita cu cea data ca parametru.
	*/
	void addRightTree(Node* left);
	/*
		Arborele va contine un singur nod, iar informatia utila din nod va fi egala cu e
	*/
	void createLeaf(const TElement& e);
	/*
		Returneaza informatia utila din radacina.
	*/
	const TElement& getTElement() const;
	/*
		Returneaza adresa urmatorului arbore din coada cu prioritati.
	*/
	BinaryTree* getNext() const;
	/*
		Returneaza adresa radacinii
	*/
	Node* getRoot() const;
	/*
		Destructorul clasei
	*/
	~BinaryTree() {
		destroyNode(&root);
	}
};