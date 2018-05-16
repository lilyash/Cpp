#include "stdafx.h"
#include "Iterator.h"


Iterator::Iterator(Queue* queue)
{
	this->queue = queue;
	this->index = queue->start;
}

Iterator::~Iterator(){}

void Iterator::start()
{
	index = queue->start;
}

void Iterator::next()
{
	index++;
	index = index % queue->size();
}

bool Iterator::finish()
{
	if (index == queue->ends) {
		
		return true;
	}
	else 
		return false;
}

int Iterator::getValue()
{
	return queue->array[index];
}
