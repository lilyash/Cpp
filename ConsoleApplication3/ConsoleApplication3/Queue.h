#pragma once

struct �ver�rowdingException{};
struct LackOfException{};

class Queue {
private:
	int *array;
	int N;
	int start;
	int ends;
	bool empty;
public:
	Queue(int N);
	~Queue();
	void push(int elem);
	int getFirst();
	int front();
	int size();
	bool isEmpty();
	void makeEmpty();
};