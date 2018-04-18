#include "Queue.h"
#include "stdafx.h"



Queue::Queue()
{
	this->start = 0;
	this->ends = 0;
	this->array = new int[5];
	empty = true;
}

Queue::Queue(int N) {
	this->N= N;
	this->start = 0;
	this->ends = 0;
	this->array = new int[N];
	empty = true;
}

Queue::Queue(const Queue & copy)
{
	this->start = copy.start;
	this->ends = copy.ends;
	this->N = copy.N;
	this->array = new int[copy.N];
	for (int i = 0; i < copy.N; i++) {
		this->array[i] = copy.array[i];
	}
}

Queue::~Queue(){
	delete array;
}

void Queue::push(int elem)
{
	if ((ends+1) == start) {
		throw Œver—rowdingException();
	}
	ends = (ends + 1) % N;
	empty = false;
	array[ends] = elem;
}

int Queue::getFirst()
{
	if (isEmpty()) {
		throw LackOfException();
	}
	int res = array[start];
	if (start == ends) {
		empty = true;
		
	}
	start = (start + 1) % N;
	return res;
}

int Queue::front()
{
	return array[start];
}

int Queue::size()
{
	return N;
}

bool Queue::isEmpty()
{
	return empty;
}

void Queue::makeEmpty()
{
	empty = true;
	start = ends;
}

