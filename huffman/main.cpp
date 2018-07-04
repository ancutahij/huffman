#include"Tests.h"
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#include<iostream>

void executeTests() {
	Test::TElementTests();
	Test::NodeTests();
	Test::BinaryTreeTests();
	Test::PriorityQueueTests();
	Test::SolvingAlgorithmsTests();
}
void menu() {
	
	//std::string menu= "\n*** MENU *** \n 1.Codifica"
	std::cout << "\n\n*** MENIU ***\n";
	std::cout << "\n 1.Codifica text";
	std::cout << "\n 0.Iesire";
	std::cout << "\n\nIntrodu optiune:";
}
void executable() {
	int op;
	while (true) {

		menu();
		std::cin >> op;
		if (op == 1) {
			std::cout << "\n\nText: ";
			std::string s;
		//	std::cin >> s;
			std::cin.ignore();
			std::getline(std::cin, s);
			CodingDecodingAlgorithm::buildHuffmanTree(s);
		}
		if (op == 0)
			break;
	}
}

int main()
{
	executeTests();

	executable();
	_CrtDumpMemoryLeaks();
	return 0;
}