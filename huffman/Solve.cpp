#include"Solve.h"
#include<iostream>
int  CodingDecodingAlgorithm::countOccurrence(const char c, std::string& text) {
	int counter = 0;
	for ( char& ch : text) {
		if (ch == c) {
			ch = '`';
			counter++; // este contorizata aparitia fiecarui caracter.
		}
	}
	return counter;
}

void CodingDecodingAlgorithm::encode(Node* root , std::string str, Pair arr[], int& position) {
	if (root == nullptr)
		return;
	if (root->getLeft() == nullptr && root->getRight() == nullptr)
	{
		TElement telem = root->getTElement();
		char ch = telem.getCharacter();
		arr[position++] = Pair{ch, str};
	}
	encode(root->getLeft(), str + "0", arr, position);
	encode(root->getRight(), str + "1", arr, position);

}

void CodingDecodingAlgorithm::decode(Node* root, int& index, std::string str) {
	if (root == nullptr) {
		return;
	}
	if (root->getLeft() == nullptr && root->getRight() == nullptr) {
		std::cout << root->getTElement().getCharacter();
		return;
	}
	index++;
	if (str[index] == '0') {
		decode(root->getLeft(), index, str);
	}
	else {
		decode(root->getRight(), index, str);

	}
}

void CodingDecodingAlgorithm::initializeTree(PriorityQueue& pq, std::string text) {
	int frequency = countOccurrence('~', text);
	if (frequency > 0) {
		BinaryTree *tree = new BinaryTree{ TElement{ '~', frequency } };
		pq.push(tree);
	}
	for (auto ch : text) {
		if (ch != '`') {
			int frequency = countOccurrence(ch, text);
			BinaryTree *tree = new BinaryTree{ TElement{ ch, frequency } };
			pq.push(tree);
		}
	}
}

void CodingDecodingAlgorithm::buildHuffmanTree(std::string text) {
	PriorityQueue pq;
	std::string copyText= text;

	initializeTree(pq, text);

	text = copyText;

	//std::cout <<"TEXT:"<< text<<"\n";
	
	// afisare frecvente caractere
	BinaryTree *aux = pq.front();
	while (aux != nullptr) {
		std::cout << aux->getTElement().getCharacter() << "  " << aux->getTElement().getFrequency() << "\n";
		aux = aux->getNext();
	}
	std::cout << "\n";
	//se construieste arborele huffman
	while (pq.size() > 1) {

		const BinaryTree* leftAB= pq.front();
		Node* left = new Node;
		*left = *(leftAB->getRoot());
		pq.pop();
		const BinaryTree* rightAB= pq.front();
		Node* right = new Node;
		*right = *(rightAB->getRoot());
		pq.pop();
		int n1 = left->getTElement().getFrequency();
		int n2 = right->getTElement().getFrequency();
		int sum = n1 + n2;
		pq.push(new BinaryTree(TElement{ '\0',sum }, left, right));
		
	}
	
	
	//vector de perechi care memoreaza caracterul si codul sau corespunzator
	Pair array[200];
	int length = 0;
	BinaryTree* huffmanTree = pq.front();
	Node* root= new Node;
	*root = *(huffmanTree->getRoot());
	std::cout << "Codul obtinut in varful stivei: " << huffmanTree->getTElement().getFrequency()<<"\n";
	pq.pop();
	std::string encodedString;

	// este apelata metoda de codificare si se afiseaza perechiile obtinute
	encode(root, "", array, length);
	for (int i = 0; i < length; i++) {
		std::cout << array[i].ch << "  " << array[i].st << "\n";
	}


	//"inlocuim" fiecare caracter cu codul sau unic intr-un string
	for (auto ch : text) {
		for (int i = 0; i < length; i++) {
			if (ch == array[i].ch) {
				encodedString += array[i].st;
				break;
			}
		}
	}
	
	std::cout <<"\nEncoded string: "<< encodedString<<"\n";

	std::cout << "\nDecoded string is: ";
	int index = -1;
	int size = encodedString.size();
	while (index < size-1) {
		decode(root, index, encodedString);
	}
	
//	delete root;
	pq.push(new BinaryTree(TElement{ '\0',4 }, root, nullptr));

}
