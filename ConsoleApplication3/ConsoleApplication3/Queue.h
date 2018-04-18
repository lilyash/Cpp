#pragma once

struct Œver—rowdingException{};
struct LackOfException{};

class Queue {
private:
	int *array;
	int N;
	int start;
	int ends;
	bool empty;
public:
	Queue();
	Queue(int N);
	Queue(const Queue &copy);
	~Queue();
	void push(int elem);
	int getFirst();
	int front();
	int size();
	bool isEmpty();
	void makeEmpty();
	friend class Iterator;
};