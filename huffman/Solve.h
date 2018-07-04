#pragma once
#include"PriorityQueue.h"
#include<string>
struct Pair {
	char ch;
	std::string st;
};
class CodingDecodingAlgorithm {
public:
	/*
		Numara si returneaza numarul de aparitii ale caracterului c in string-ul dat.
	*/
	static int countOccurrence(const char c, std::string& text);
	/*
		Construieste arborele binar Huffman
		Pentru fiecare caracter se va contoriza numarul de aparitii si se va crea un arbore binar,
		care va fi adaugat ca element in coada.
		Se vor extrage primii doi arbori si se va crea un al treilea care va avea ca subarbori stang si drept pe cei
		extrasi anterior.
		*/
	static void buildHuffmanTree(std::string text);
	/*
		Se afiseaza codarea Huffman calculata.
		Ramurile din stanga sunt numerotate cu 0, iar cele din dreapta cu 1.

	*/
	static void encode(Node* , std::string , Pair[], int&);
	/*
		Dandu-se arborele binar Huffman si stringul codat, se realizeaza decodarea.
	*/
	static void decode(Node*, int&, std::string);

	/* 
		Se creeaza arbori cu un singur nod (contin ca si informatie utila caracterul+ freceventa)
		care urmeaza a fi adaugati in coada.
	*/
	static void initializeTree(PriorityQueue& pq, std::string text);
};