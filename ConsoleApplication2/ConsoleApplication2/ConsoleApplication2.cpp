#include "stdafx.h"
#include "iostream"
#include "conio.h"

using std::istream;
using std::ostream;
using std::cin;
using std::cout;

struct AccessException{};
struct DifferentlengthException{};

class DinamArray {
private:
	int *arr;
	int size;
	int reserv;
public:

	DinamArray() {
		arr = new int[15];
		size = 15;
		reserv = 0;
	}

	DinamArray(int size) {
		arr = new int[size];
		this->size = size;
		reserv = 0;
	}

	DinamArray(int size, int n) {
		arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = n;
		}
		this->size = size;
		reserv = 0;
	}

	DinamArray(const DinamArray &copy) {
		this->arr = new int[copy.size];
		this->size = copy.size;
		for (int i = 0; i < copy.size; i++) {
			arr[i] = copy.arr[i];
		}
		reserv = 0;
	}

	DinamArray(DinamArray &&copy) {
		this->arr = new int[copy.size];
		this->size = copy.size;
		for (int i = 0; i < copy.size; i++) {
			arr[i] = copy.arr[i];
		}
		copy.size = 15;
		delete[] copy.arr;
		copy.arr = new int[15];
		reserv = 0;
	}

	DinamArray(int size, int reserv, int n) {
		arr = new int[size + reserv];
		this->size = size;
		for (int i = 0; i < size; i++) {
			arr[i] = n;
		}
		this->reserv = reserv;
	}

	~DinamArray() {
		delete[] arr;
		reserv = NULL;
		size = NULL;
	}

	int length() {
		return size;
	}

	int operator [] (int i) {
		if (i >= this->size) {
			throw AccessException();
		}
		return arr[i];
	}

	DinamArray& operator = (const DinamArray& obj) {
		delete[] this->arr;
		this->arr = new int[obj.size];
		for (int i = 0; i < obj.size; i++) {
			arr[i] = obj.arr[i];
		}
		this->size = obj.size;
		return *this;
	}

	DinamArray& operator = (DinamArray&& obj) {
		delete[] this->arr;
		this->arr = new int[obj.size];
		for (int i = 0; i < obj.size; i++) {
			arr[i] = obj.arr[i];
		}
		this->size = obj.size;
		delete[] obj.arr;
		obj.size = 15;
		obj.arr = new int[15];
		return *this;
	}

	void resize(int newSize) {
		if (newSize > this->size + this->reserv) {
			int *buf = new int[newSize];
			for (int i = 0; i < newSize; i++) {
				if (i < size) {
					buf[i] = this->arr[i];
				}
				else {
					buf[i] = 0;
				}
			}
			size = newSize;
			delete[]arr;
			this->arr = buf;
		}
		else {
			newSize = newSize - size;
			size = size + newSize;
			reserv = reserv - newSize;
		}
	}

	bool operator == (const DinamArray& obj) {
		bool flag = true;
		if (this->size != obj.size) {
			throw 1;
		}
		else {
			for (int i = 0; i < this->size; i++) {
				if (this->arr[i] != obj.arr[i]) {
					flag = false;
				}
			}
			return flag;
		}
	}

	bool operator != (const DinamArray& obj) {
		bool flag = false;
		if (this->size != obj.size) {
			throw DifferentlengthException();
		}
		else {
			for (int i = 0; i < this->size; i++) {
				if (this->arr[i] != obj.arr[i]) {
					flag = true;
				}
			}
			return flag;
		}
	}

	bool operator < (const DinamArray& obj) {
		bool flag = false;
		int n = this->size, i = 0;
		if (n < obj.size) {
			n = obj.size;
		}
		while (i < n && this->arr[i] <= obj.arr[i]) {
			if (this->arr[i] < obj.arr[i]) {
				flag = true;
			}
			i++;
			if (i == n && !flag && n == obj.size && obj.size != this->size) {
				flag = true;
			}
		}
		return flag;
	}

	bool operator <= (const DinamArray& obj) {
		bool flag = false;
		int n = this->size, i = 0;
		if (n < obj.size) {
			n = obj.size;
		}
		while (i < n && this->arr[i] <= obj.arr[i]) {
			if (this->arr[i] < obj.arr[i]) {
				flag = true;
			}
			i++;
			if (i == n && !flag && n == obj.size) {
				flag = true;
			}
		}
		return flag;
	}

	bool operator > (const DinamArray& obj) {
		bool flag = false;
		int n = obj.size, i = 0;
		if (n < this->size) {
			n = this->size;
		}
		while (i < n && this->arr[i] >= obj.arr[i]) {
			if (this->arr[i] > obj.arr[i]) {
				flag = true;
			}
			i++;
			if (i == n && !flag && n == this->size && obj.size != this->size) {
				flag = true;
			}
		}
		return flag;
	}

	bool operator >= (const DinamArray& obj) {
		bool flag = false;
		int n = obj.size, i = 0;
		if (n < this->size) {
			n = this->size;
		}
		while (i < n && this->arr[i] >= obj.arr[i]) {
			if (this->arr[i] > obj.arr[i]) {
				flag = true;
			}
			i++;
			if (i == n && !flag && n == this->size) {
				flag = true;
			}
		}
		return flag;
	}

	DinamArray& operator + (const DinamArray& obj) {
		int newSize = this->size + obj.size;
		int *buf = new int[newSize];
		for (int i = 0; i < this->size; i++) {
			buf[i] = arr[i];
		}
		for (int i = 0; i < obj.size; i++) {
			buf[this->size + i] = obj.arr[i];
		}
		this->size = newSize;
		delete[] this->arr;
		this->arr = new int[newSize];
		this->arr = buf;
		return *this;
	}

	friend istream& operator>> (istream& is, DinamArray& obj) {
		is >> obj.size >> obj.reserv;
		for (int i = 0; i < obj.size; i++) {
			is >> obj.arr[i];
		}
		return is;
	}

	friend ostream& operator<< (ostream& os, const DinamArray& obj) {
		os << "size = " << obj.size << " reserv = " << obj.reserv << " array = { ";
		for (int i = 0; i < obj.size; i++) {
			os << obj.arr[i] << ' ';
		}
		os << "}";
		return os;
	}

	void reserve(int n) {
		reserv = n;
		int *buf = new int[size + n];
		for (int i = 0; i < size; i++) {
			buf[i] = arr[i];
		}
		delete[]arr;
		arr = buf;
	}

	int capacity() {
		return reserv;
	}

	void pushBack(int x) {
		reserv--;
		arr[size] = x;
		size++;
	}

	int popBack() {
		reserv++;
		size--;
		return arr[size];
	}
};

int main()
{

	_getch();

	return 0;
}


