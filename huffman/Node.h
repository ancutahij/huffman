#pragma once
#include"TElement.h"
class BinaryTree;
/*
	Un nod contine:
	-informartia utila (caracter + frecventa)
	-legatura catre nodul din stanga
	-legatura catre nodul din dreapta
*/
class Node {
	TElement e;
	Node* left;
	Node* right;
	friend class BinaryTree;
public:
	/*
		Constructorii pentru clasa Nod.
		Sunt acomodate mai multe tipuri de date pentru instantierea unui obiect de tip Nod
	*/
	// Este oferita doar informatia utila,  left si right urmand a fi nullptr
	Node(TCharacter character, TFrequency freq)
		: e{ TElement(character, freq) } {
		left = nullptr;
		right = nullptr;
	}
	// Este oferita atat informatia utila, cat si cele 2 legaturi
	Node(TCharacter character, TFrequency freq, Node* left, Node* right)
		: e{ TElement(character, freq) } {
		left = left;
		right = right;
	}
	// Este oferita doar informatia utila,  left si right urmand a fi nullptr
	Node(TElement e)
		: e{ e } {
		left = nullptr;
		right = nullptr;
	}
	// Contructorul default
	Node() {
		left = nullptr;
		right = nullptr;

	}
	
	/*
		A fost suprascris operatorul de atribuire a doua obiecte de tip Nod.
		Se va face deep copy folosindu-se functia de getDeepCopy declarata mai jos.
	*/
	Node&  operator=(const Node& t);
	/*
		Se va copia informatia utila din fiecare nod la o adresa noua
	*/
	Node* getDeepCopy(Node* e);
	/*
		Returneaza informatia utila din nod (caracter+ frecventa). 
	*/
	const TElement& getTElement() const;
	/*
		Returneaza adresa nodului stang.
	*/
	Node* getLeft() const;
	/*
		Returneaza adresa nodului drept.
	*/
	Node* getRight() const;
	/*
		Adresa curenta a nodului stang va fi modificata cu una noua.
	*/
	void setLeft(Node*);
	/*
		Adresa curenta a nodului drept va fi modificata cu una noua.
	*/
	void setRight(Node*);



};