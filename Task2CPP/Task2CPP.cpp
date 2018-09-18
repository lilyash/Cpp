// Task2CPP.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "RingBuffer.h"
#include "Iterator.h"
#include <iostream>

using namespace std;
int main()
{
	RingBuffer *ringB = new RingBuffer(5);
	ringB->addElement(1);
	ringB->addElement(2);
	ringB->addElement(3);
	
	RingBuffer *ringA = new RingBuffer(*ringB);
	RingBuffer *ringC = new RingBuffer(2);
	ringA->addElement(0);
	if (!ringA->checkEmpty()) {
		cout << "queue isn't empty" << endl;
	}
	if (ringC->checkEmpty()) {
		cout << "queue is empty!" << endl;
	}
	Iterator iteratorA = Iterator(ringA);
	Iterator iteratorB = Iterator(ringB);
	while (!iteratorB.finish()) {
		iteratorB.next();
		cout << iteratorB.getValue() << endl;
		
	}
	
	cout << "______________________________________" << endl;
	
	while (!iteratorA.finish()) {
		iteratorA.next();
		cout << iteratorA.getValue() << endl;
		
	}

	cout << "______________________________________" << endl;
	cout <<"size ringA :" <<ringA->getSize()<<endl;
	ringA->doEmptyQueue(); 
	if (ringA->checkEmpty()) {
		cout << "ringA is empty" << endl;
	}
	iteratorA.start();
	while (!iteratorA.finish()) {
		iteratorA.next();
		cout << iteratorA.getValue() << endl;

	}

	//cout << ringB->getElem() << endl;
	delete ringA;
	delete ringB;
	delete ringC;

	system("pause");
    return 0;
}

