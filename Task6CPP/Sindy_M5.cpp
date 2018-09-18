// Sindy_M5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "TreeDictionary.h"

int main()
{
	TreeDictionary* tree = new TreeDictionary();
	tree->addWord("Hello");
	tree->addWord("Kenny");
	tree->addWord("Anya");
	tree->addWord("Anya");
	tree->addWord("James");
	tree->addWord("Easy");
	tree->addWord("Claw");
	tree->addWord("Denis");
	tree->addWord("Bottle");
	tree->addWord("Anya");
	tree->addWord("Fedya");
	tree->addWord("Ghost");
	tree->addWord("James");
	tree->addWord("Claw");
	tree->addWord("James");
	tree->addWord("Easy");
	tree->addWord("Claw");
	tree->addWord("Idea");
	tree->addWord("Anya");
	tree->addWord("Anya");
	std::cout << *tree << std::endl;
	std::cout << "count words in tree:"<<tree->countWords() << std::endl;
	std::cout <<"frequency word \"Anya\" :" <<tree->findWord("Anya") << std::endl;
	std::cout << "frequency word \"Ghost\" :" << tree->findWord("Ghost") << std::endl;
	std::cout << "frequency word \"Timmy\" :" << tree->findWord("Timmy") << std::endl;
	std::cout << "delete words" <<std :: endl;
	tree->deleteWord("Claw");
	tree->deleteWord("Bottle");
	tree->deleteWord("Anya");
	tree->deleteWord("Ghost");
	std::cout << *tree << std::endl;
	std::cout << "count word: "<<tree->countWords() << std::endl;
	std::cout << "frequency word \"Anya\" :" << tree->findWord("Anya") << std::endl;
	std::cout << "frequency word \"Ghost\" :" << tree->findWord("Ghost") << std::endl;
	std::cout << "frequency word \"Timmy\" :" << tree->findWord("Timmy") << std::endl;
	system("pause");
	delete tree;
    return 0;
}

