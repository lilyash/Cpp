#include "stdafx.h"
#include "Queue.h"
#include "iostream"
#include "conio.h"
#include "locale.h"
#include "Iterator.h"

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;


int main()
{
	setlocale(LC_ALL, "ru");
	int status = 0; 
	int number = 0;
	Queue *q = new Queue(6);
	cout << q->isEmpty() << endl;
	q->push(7);
	q->push(47);
	q->push(37);
	q->push(798);
	q->push(0);
	Iterator *itr = new Iterator(q);
	cout << q->isEmpty() << endl;
	cout << q->size() << endl;
	cout << q->front() << endl;
	cout << "------------------------" << endl;
	while (!itr->finish()) {
		cout << itr->getValue() << endl;
		itr->next();
	}
	cout << itr->getValue() << endl;
	cout << "------------------------" << endl;
	try {
		q->push(5);
	}
	catch (ОverСrowdingException) {
		cout << "Очередь переполнена! Вставить элемент невозможно." << endl;
	}
	itr->start();
	cout << "------------------------" << endl;
	while (!itr->finish()) {
		cout << itr->getValue() << endl;
		itr->next();
	}
	cout << itr->getValue() << endl;
	cout << "------------------------" << endl;
	q->makeEmpty();
	try {
		q->getFirst();
	}
	catch (LackOfException) {
		cout << "Невозможно взять первый элемент очереди. Очередь пуста." << endl;
	}
	itr->start();
	cout << "------------------------" << endl;
	while (!itr->finish()) {
		cout << itr->getValue() << endl;
		itr->next();
	}
	cout << "------------------------" << endl;
	system("pause");

}

