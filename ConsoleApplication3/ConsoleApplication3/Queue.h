#pragma once

struct Œver—rowdingException{};
struct LackOfException{};

class Queue {
private:
	int *array;
	int N;
	int start;
	int ends;

public:
	Queue(int N);
	~Queue();
	void push();
	int getFirst();
	int front();
	int size();
	void isEmpty();
	bool makeEmpty();
};