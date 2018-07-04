#include"Tests.h"
void Test::TElementTests() {
	TElement e1{ '3', 34 };
	TElement e2{ '4', 134 };

	assert(e1.getCharacter() == '3');
	assert(e2.getCharacter() == '4');
	assert(e1.getFrequency() == 34);
	assert(e2.getFrequency() == 134);

}

void Test::NodeTests() {
	Node *n1 = new Node{ 'e',2 };
	
	assert(n1->getTElement().getCharacter() == 'e');
	assert(n1->getTElement().getFrequency()== 2);

	delete n1;
}


void Test::BinaryTreeTests() {
	TElement e1{ '3', 34 };
	TElement e2{ '4', 134 };

	BinaryTree ab{ e1 };
	assert(ab.getTElement().getCharacter() == '3');
	assert(ab.getTElement().getFrequency() == 34);

	//BinaryTree *ab1 = new BinaryTree{ e1 };

	//Node *n1 = new Node{ 'e',2 };
}
void Test::PriorityQueueTests() {
	//add tests
	TElement e1{ '4', 134 };
	TElement e2{ '4', 134 };
	TElement e3{ '2', 4 };
	BinaryTree *ab1 = new BinaryTree{ e1 };
	BinaryTree *ab2= new BinaryTree{e2};
	BinaryTree *ab3= new BinaryTree{ e3};
	PriorityQueue pq;
	pq.push(ab1);
	pq.push(ab2);
	pq.push(ab3);

	TElement e4{ '2', 8};
	BinaryTree *ab4= new BinaryTree{ e4 };
	pq.push(ab4);


	TElement e5{ 's', 1 };
	BinaryTree *ab5 = new BinaryTree{ e5};
	pq.push(ab5);
	

	/*
		front/ pop tests
	*/
	const BinaryTree* e = pq.front();
	assert(e->getTElement().getFrequency() == 1);
	assert((*e).getTElement().getCharacter()== 's');

	pq.pop();
	const BinaryTree* el = pq.front();
	assert(el->getTElement().getFrequency() == 4);
	assert((*el).getTElement().getCharacter() == '2');

	/*
		Empty queue tests
	*/
	assert(pq.empty() == false);
	pq.pop();
	pq.pop();
	pq.pop();
	pq.pop();

	assert(pq.empty() == true);

}

void cls() noexcept
{
	system("cls");
}

void Test::SolvingAlgorithmsTests() {



	CodingDecodingAlgorithm::buildHuffmanTree("Huffman coding is a data compression algorithm.");
	CodingDecodingAlgorithm::buildHuffmanTree("abracadabra");
	CodingDecodingAlgorithm::buildHuffmanTree("aaaaaaaaaaaaaaaaaaaaaadfeefefadhrja");
	cls();
}