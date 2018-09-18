
#include "stdafx.h" 
#include <iostream> 
#include "locale.h"

using namespace std;

struct SizeException{};
class DynamicArrayOfIntegers {
private:
	int *array;
	int size;
public:


	DynamicArrayOfIntegers() {
		size = 1;
		array = new int[size];
	}

	DynamicArrayOfIntegers(int size) {
		this->size = size;
		array = new int[size];
		for (int i = 0; i < size; i++) {
			array[i] = 0;
		}
	}

	DynamicArrayOfIntegers(int size, int n) {
		this->size = size;
		array = new int[size];
		for (int j = 0; j < size; j++) {
			array[j] = n;
		}
	}
	// конструктор копирования
	DynamicArrayOfIntegers(const DynamicArrayOfIntegers& copy) {
		size = copy.size;
		array = new int[size];
		for (int i = 0; i < size; i++) {
			array[i] = copy.array[i];
		}
	}


	//конструктор перемещения 
	DynamicArrayOfIntegers(DynamicArrayOfIntegers&& temp)
	{
		size = temp.size;
		array = new int[size];
		for (int i = 0; i < size; i++) {
			array[i] = temp.array[i];
		}
		delete[] temp.array;
	}
	//деструктор
	~DynamicArrayOfIntegers() {
		delete []array;
	}

	//длина массива
	int getLenght() {
		return size;
	}

	//изменение размера
	void reSize(int newSize) {
		int* tempArray = new int[newSize];
		if (size > newSize) {
			for (int i = 0; i < newSize; i++) {
				tempArray[i] = array[i];
			}
		}
		else {
			for (int j = 0; j < size; j++) {
				tempArray[j] = array[j];
			}
			for (int i = size; i < newSize; i++) {
				tempArray[i] = 0;
			}
		}
		size = newSize;
		delete []array;
		array = tempArray;
	}

	//конкатенация массивов
	DynamicArrayOfIntegers& operator + (const DynamicArrayOfIntegers& m2) {
		int bigSize = this->size + m2.size;
		DynamicArrayOfIntegers *res = new DynamicArrayOfIntegers(bigSize);
		for (int i = 0; i < this->size; i++) {
			res->array[i] = this->array[i];
		}
		for (int j = size; j < bigSize; j++) {
			res->array[j] = m2.array[j - size];
		}
		return *res;
	}

	//Оператор присваивания
	DynamicArrayOfIntegers operator =(const DynamicArrayOfIntegers&  m1) {
		if(this) {
			delete[] this->array;		
		}
		this->size = m1.size;
		this->array = new int[m1.size];
		for (int i = 0; i < m1.size; i++) {
			this->array[i] = m1.array[i];
		}
		return *this;
	}

	//оператор перемещения
	DynamicArrayOfIntegers operator =(DynamicArrayOfIntegers&&  m1) {
		if(this) {
			delete[] this->array;		
		}		
		this->size = m1.size;
		this->array = new int[m1.size];
		for (int i = 0; i < m1.size; i++) {
			this->array[i] = m1.array[i];
		}
		delete[] m1.array;
	}

	//перегрузка[]
	int operator [](int x) {
		if (x >= this->size && x < 0) {
			throw SizeException();
		}
		return array[x];
	}

	//перегрузка==
	bool operator ==(DynamicArrayOfIntegers const &m1) {
		if (m1.size != this->size) {
			throw SizeException();
		}
		for (int i = 0; i < m1.size; i++) {
			if (m1.array[i] != this->array[i]) {
				return false;
			}
		}
		return true;
	}

	//перегрузка != 
	bool operator !=(DynamicArrayOfIntegers const &m1) {
		if (m1.size != this->size) {
			throw SizeException();
		}
		for (int i = 0; i < m1.size; i++) {
			if (m1.array[i] != this->array[i]) {
				return true;
			}
		}
		return false;
	}

	//перегрузка >
	bool operator >(DynamicArrayOfIntegers const &m1) {
		if (m1.size < this->size) {
			for (int i = 0; i < m1.size; i++) {
				if (m1.array[i] < this->array[i])
					return true;
			}return true;
		}
		if (m1.size >= this->size) {
			for (int j = 0; j < this->size; j++) {
				if (m1.array[j] < this->array[j]) {
					return true;
				}
			}
		}
		return false;

	}
	//перегрузка <
	bool operator <(DynamicArrayOfIntegers const &m1) {
		if (m1.size <= this->size) {
			for (int i = 0; i < m1.size; i++) {
				if (m1.array[i] < this->array[i])
					return true;
			}
		}
		if (m1.size > this->size) {
			for (int j = 0; j < this->size; j++) {
				if (m1.array[j] < this->array[j]) {
					return true;
				}
			}return true;
		}
		return false;

	}
	//перегрузка >=
	bool operator >=(DynamicArrayOfIntegers const &m1) {
		if (m1.size < this->size) { return true; }//что кого больше ?
		if (m1.size > this->size) { return false; }
		if (m1.size == this->size) {
			for (int i = 0; i < m1.size; i++) {
				if ((m1.array[i] < this->array[i]) || (m1.array[i] == this->array[i])) {
					return true;
				}
				return false;

			}
		}
	}
	// перегрузка <=
	bool operator <=(DynamicArrayOfIntegers const &m1) {
		if (m1.size < this->size) { return false; }//что кого больше ?
		if (m1.size > this->size) { return true; }
		if (m1.size == this->size) {
			for (int i = 0; i < m1.size; i++) {
				if ((m1.array[i] > this->array[i]) || (m1.array[i] == this->array[i])) {
					return true;
				}
				return false;

			}
		}
	}
	// перегрузка операторов вывода
	friend ostream & operator << (ostream & stream, DynamicArrayOfIntegers dinArray) {
		stream << "size :" << dinArray.size << endl;
		stream << "array {";
		for (int i = 0; i < dinArray.size; i++) {
			stream << dinArray[i] << " ";
		}
		stream << "}";
		return stream;
	}
	// перегрузка оператора ввода
	friend istream & operator >>(istream & stream, DynamicArrayOfIntegers &dinArray) {
		stream >> dinArray.size;
		delete[] dinArray.array;
		dinArray.array = new int[dinArray.size];
		for (int i = 0; i < dinArray.size; i++) {
			stream >> dinArray.array[i];
		}
		return stream;
	}


};
int main()
{
	setlocale(LC_CTYPE, "rus");
	setlocale(LC_ALL, "Rus");
	DynamicArrayOfIntegers a(3, 4);
	DynamicArrayOfIntegers b(5, 7);
	DynamicArrayOfIntegers d(5, 5);
	DynamicArrayOfIntegers e(5, 5);
	DynamicArrayOfIntegers c(0, 0);
	int choice = 0;
	int newSizeArray = 0;
	int choice_array = 0;

	while (choice != 13) {
		if (choice == 0) {
			cout <<" array A  " <<a<<endl;
			cout <<" array B  "<< b << endl;
			cout <<" array C  "<< c << endl;
			cout <<" array D  "<<d <<endl;
			cout <<" array E  " << e<<endl;
			cout << "---------------Menu-------------------" << endl;
			cout << "1.Change of size an array(reSize)" << endl;
			cout << "2.Addition of arrays" << endl;
			cout << "3.assignment operator" << endl;//оператор присваивания
			cout << "4.assignment ==" << endl;
			cout << "5.assignment !=" << endl;
			cout << "6.assignment <" << endl;
			cout << "7.assignment <=" << endl;
			cout << "8.assignment >=" << endl;
			cout << "9.assignment +" << endl;
			cout << "10.assignment <<" << endl;
			cout << "11.assignment >>" << endl;
			cout << "12.Exit" << endl;
			cin >> choice;
		}
		if (choice == 1) {
			cout << "what array do you want to change ? ?"<<endl;
			cout << "1.a(size 3)"<<endl;
			cout << " 2.b(size 5)" << endl;
			cin >> choice_array;
			cout << "What size should I change ? "<<endl;
			cin >> newSizeArray;
			if (choice_array == 1) {
				a.reSize(newSizeArray);
				cout << "size new array:" << a.getLenght()<<endl;
			}
			if (choice_array == 2) {
				b.reSize(newSizeArray);
				cout << "size new array:" << b.getLenght()<<endl;
			}

			cin >> choice;
		}
		if (choice == 2) {
			c = a + b;
			cout << c.getLenght()<<endl;
			cout << c << endl<<endl;
			cout << a << endl;
			cin >> choice;
		}
		if (choice == 3) {
			c = b;
			cout << c << endl;
			cin >> choice;
		}
		if (choice == 4) {
			try {
				if (d == e) {
					cout << "d=e" << endl;
				}
				if (b == d) {
					cout << "b==d"<<endl;
				}
				else {
					cout << "b!=d"<<endl;
				}
			}
			catch (SizeException) {
				cout << "SizeException"<<endl;
			}
			cin >> choice;
		}
		if (choice == 5) {
			try {
				if (b != d) {
					cout << "b!=d" << endl;
				}
				else {
					cout << "b=d"<<endl;
				}
				cin >> choice;
			}
			catch (SizeException) {
				cout << "SizeException!"<<endl;
			}
		}
		if (choice == 6) {
			if (a > c) {
				cout << "a>c"<<endl;
			}
			if (a < c) {
				cout << "a<c";
			}
			cin >> choice;
		}
		if (choice == 7) {
			if (d <= e) {
				cout << "d<=e"<<endl;
			}
			if (b <= a) {
				cout << "b<=a"<<endl;
			}
			else {
				cout << "b>a" << endl;
			}
			cin >> choice;
		}
		if (choice == 8) {
			if (d >= e) {
				cout << "d>e"<<endl;
			}
			if(e>=c){
				cout << "e<=c"<<endl;
			}
			cin >> choice;
		}
		if (choice == 9) {
			c = a + b;
			cout << c<<endl;
			cin >> choice;
		}
		if (choice == 10) {
			cout << a<<endl;
			cin >> choice;
		}
		if (choice == 11) {
			cin >> c;
			cout << c<<endl;
			cin >> choice;
		}
	}
	system("pause");
	return 0;
}
