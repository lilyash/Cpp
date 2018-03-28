#include "Queue.h"
#include "stdafx.h"


Queue::Queue(int N) {
	this->N = N;
	this->start = 0;
	this->ends = 0;
	this->array = new int[N];
}

Queue::~Queue(){
	delete array;
}

void Queue::push()
{
	if ((ends +1)%N == start) {
		throw Œver—rowdingException();
	}
}

