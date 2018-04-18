#include "stdafx.h"
#include "Iterator.h"


Iterator::Iterator(Queue queue)
{
	this->queue = new Queue(queue);
	this->index = queue.start;
}
