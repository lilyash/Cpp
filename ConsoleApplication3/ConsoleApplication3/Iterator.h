#pragma once
#include "Queue.h"
class Iterator{
private:
	Queue *queue;
	int index;
public:
	Iterator(Queue *queue);
	~Iterator();
	void start();
	void next();
	bool finish();
	int getValue();
};

