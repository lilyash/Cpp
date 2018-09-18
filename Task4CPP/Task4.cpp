// Task4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "LinkedHashTable.h"
#include "iostream"

using namespace std;
int main()
{
	LinkedHashTable* oneHashTable = new LinkedHashTable();
	oneHashTable->addElem(1, 0);
	oneHashTable->addElem(2, 3);
	oneHashTable->addElem(3, 2);
	oneHashTable->addElem(4, 5);
	oneHashTable->addElem(15,7 );
	oneHashTable->addElem(5, 12);
	oneHashTable->printElem();
	Iterator iteratorOne(oneHashTable);
	while (iteratorOne.hasNext()) {
		cout << iteratorOne.seeElem() << endl;
		iteratorOne.next();
	}
	cout << iteratorOne.seeElem() << endl;
	cout << "-----------------------------" << endl;
	oneHashTable->removeElem(3);
	iteratorOne.start();
	while (iteratorOne.hasNext()) {
		cout << iteratorOne.seeElem() << endl;
		iteratorOne.next();
	}
	cout << iteratorOne.seeElem() << endl;
	cout << "-----------------------------" << endl;
	cout<<oneHashTable->findElem(0)<<endl;
	cout << oneHashTable->findElem(5) << endl;
	cout <<"isEmpty: " <<oneHashTable->isEmpty()<<endl;
	cout << "doEmpty." << endl;
	oneHashTable->doEmpty();
	cout << "isEmpty: " << oneHashTable->isEmpty() << endl;
	system("pause");
	return 0;
}

