#include "stdafx.h" 
#include "iostream" 
#include "conio.h" 
#include "locale.h" 

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

struct BadArrayLengthException {};
struct EndOfReservException {};
struct EndSizeOfArrayException {};
struct BadIndexException {};
struct BadSizeException {};
struct BadReservException {};

class dinamArray {
private:
	int *arr;
	int size;
	int reserv;
public:

	dinamArray() {
		arr = new int[15];
		size = 15;
		reserv = 0;
	}

	dinamArray(int size) {
		arr = new int[size];
		this->size = size;
		reserv = 0;
	}

	dinamArray(int size, int n) {
		arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = n;
		}
		this->size = size;
		reserv = 0;
	}

	dinamArray(const dinamArray &copy) {
		this->arr = new int[copy.size];
		this->size = copy.size;
		for (int i = 0; i < copy.size; i++) {
			arr[i] = copy.arr[i];
		}
		reserv = 0;
	}

	dinamArray(dinamArray &&copy) {
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

	dinamArray(int size, int reserv, int n) {
		arr = new int[size + reserv];
		this->size = size;
		for (int i = 0; i < size; i++) {
			arr[i] = n;
		}
		this->reserv = reserv;
	}

	~dinamArray() {
		delete[] arr;
		reserv = NULL;
		size = NULL;
	}

	int length() {
		return size;
	}

	int operator [] (int i) {
		if (i >= this->size) {
			throw BadIndexException();
		}
		return arr[i];
	}

	dinamArray& operator = (const dinamArray& obj) {
		delete[] this->arr;
		this->arr = new int[obj.size];
		for (int i = 0; i < obj.size; i++) {
			arr[i] = obj.arr[i];
		}
		this->size = obj.size;
		return *this;
	}
	// перемещение//
	dinamArray& operator = (dinamArray&& obj) {
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
		if (newSize < 0) {
			throw BadSizeException();
		}
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
			for (int i = size; i < newSize; i++) {
				this->arr[i] = 0;
			}
			newSize = newSize - size;
			size = size + newSize;
			reserv = reserv - newSize;
		}
	}

	bool operator == (const dinamArray& obj) {
		bool flag = true;
		if (this->size != obj.size) {
			throw BadArrayLengthException();
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

	bool operator != (const dinamArray& obj) {
		bool flag = false;
		if (this->size != obj.size) {
			throw BadArrayLengthException();
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

	bool operator < (const dinamArray& obj) {
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

	bool operator <= (const dinamArray& obj) {
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

	bool operator > (const dinamArray& obj) {
		bool
			flag = false;
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

	bool operator >= (const dinamArray& obj) {
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

	dinamArray& operator + (const dinamArray& obj) {
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

	friend istream& operator>>(istream& is, dinamArray& obj) {
		cout << "Введите размер" << endl;
		int newSize, reserv;
		is >> newSize;
		obj.resize(newSize);
		obj.size = newSize;
		cout << "\nВведите резерв" << endl;
		is >> reserv;
		obj.reserve(reserv);
		obj.reserv = reserv;
		cout << "\nВведите элементы" << endl;
		for (int i = 0; i < obj.size; i++) {
			is >> obj.arr[i];
		}
		return is;
	}

	friend ostream& operator<<(ostream& os, const dinamArray& obj) {
		os << "size = " << obj.size << " reserv = " << obj.reserv <<" array = { ";
		for (int i = 0; i < obj.size; i++) {
			os << obj.arr[i] << ' ';
		}
		os << "}" << endl;
		return os;
	}

	void reserve(int n) {
		if (n <= 0) {
			throw BadReservException();
		}
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
		if (reserv == 0) {
			reserv = 13;
			int *buf = new int[size + reserv];
			for (int i = 0; i < size; i++) {
				if (i < size) {
					buf[i] = this->arr[i];
				}
				else {
					buf[i] = 0;
				}
			}
			buf[size + reserv] = x;
			size++;
			delete[]arr;
			this->arr = buf;
		}
		else {
			reserv--;
			arr[size] = x;
			size++;
		}
	}

	int popBack() {
		if (size == 0) {
			throw EndSizeOfArrayException();
		}
		reserv++;
		size--;
		return arr[size];
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	int status = 0;
	int numArr = 0;
	dinamArray arr1(10, 5);;
	dinamArray arr2 = dinamArray(5);
	while (status != -1) {
		if (status == 0) {
			cout << "1.Изменить массив\n2.Вывести массив" << endl;
			cout << "3.Узнать длинну массива\n4.Получить доступ к i-ому элементу массива(оператор [])" << endl;
			cout << "5.Оператор \"=\"\n6.Изменить размер" << endl;
			cout << "7.Сравнить массивы\n8.Сложить массивы" << endl;
			cout << "9.Зарезервировать место\n10.Вывести колличество зарезервированного места" << endl;
			cout << "11.Поместить элемент в конец массива\n12.Забрать элемент из конца массива" << endl;
			cout << "-1 для выхода" << endl;
			cin >> status;
			system("cls");
		}
		if (status == 1) {
			cout << "Какой массивы надо заполнить?(1/2)" << endl;
			cin >> status;
			numArr;
			if (numArr == 1) {
				cin >> arr1;
			}
			if (numArr == 2) {
				cin >> arr2;
			}
			status = 0;
			cout << "Готово!" << endl;
			_getch();
			system("cls");
		}
		if (status == 2) {
			cout <<  "Какой массивы надо вывести?(1/2)" << endl;
			cin >> numArr;
			if (numArr == 1) {
				cout << arr1;
			}
			if (numArr == 2) {
				cout << arr2;
			}
			status = 0;
			_getch();
			system("cls");
		}
		if (status == 3) {
			cout << "Длину какого массива надо узнать?(1/2)" << endl;
			cin >> numArr;
			if (numArr == 1) {
				cout << arr1.length();
			}
			if (numArr == 2) {
				cout << arr2.length();
			}
			status = 0;
			_getch();
			system("cls");
		}
		if (status == 4) {
			int i = 0;
			cout << "С каким массивом работаем?(1/2)" << endl;
			cin >> numArr;
			cout << "Какой элемент вывести?" << endl;
			cin >> i;
			try {
				if (numArr == 1) {
					cout << arr1[i];
				}
				if (numArr == 2) {
					cout << arr2[i];
				}
			}
			catch (BadIndexException e) {
				std::cerr << "Выход заграницы массива!" << endl;
			}
			status = 0;
			_getch();
			system("cls");
		}
		if (status == 5) {
			cout << "Какой массив приравнять?(1/2)" << endl;
			cin >> numArr;
			if (numArr == 1) {
				arr1 = arr2;
			}
			if (numArr == 2) {
				arr2 = arr1;
			}
			status = 0;
			_getch();
			system("cls");
		}
		if (status == 6) {
			int size;
			cout << "Длину какого массива надо изменить?(1/2)" << endl;
			cin >> numArr;
			cout << "Введите новую длинну." << endl;
			cin >> size;
			try {
				if (numArr == 1) {
					arr1.resize(size);
				}
				if (numArr == 2) {
					arr2.resize(size);
				}
			}
			catch (BadSizeException e) {
				std::cerr << "Длина должна быть положительной!" << endl;
			}
			status = 0;
			cout << "Готово!" << endl;
			_getch();
			system("cls");
		}
		if (status == 7) {
			bool flag = false;
			try {
				cout << " == != < > <= >=\n " << (arr1 == arr2) << " " << (arr1 != arr2) << " ";
			}
			catch (BadArrayLengthException e) {
				std::cerr << "Размеры массивов разные" << endl;
				flag = true;
			}
			if (flag) {
				cout << "< > <= >=" << endl;
			}
			cout << (arr1 < arr2) << " " << (arr1 > arr2) << " " << (arr1 <= arr2) << " " << (arr1 >= arr2) << " " << endl;
			status = 0;
			cout << "Готово!" << endl;
			_getch();
			system("cls");
		}
		if (status == 8) {
			arr1 + arr2;
			status = 0;
			cout << "Готово!" << endl;
			_getch();
			system("cls");
		}
		if (status == 9) {
			int reserv;
			cout << "В каком массиве надо зарезервировать память?(1/2)" << endl;
			cin >> numArr;
			cout << "Введите новую длинну." << endl;
			cin >> reserv;
			try {
				if (numArr == 1) {
					arr1.reserve(reserv);
				}
				if (numArr == 2) {
					arr2.reserve(reserv);
				}
			}
			catch (BadReservException e) {
				std::cerr << "Длина должна быть положительной!" << endl;
			}
			status = 0;
			cout << "Готово!" << endl;
			_getch();
			system("cls");
		}
		if (status == 10) {
			int size;
			cout << "Резерв какого массива надо узнать?(1/2)" << endl;
			cin >> numArr;
			if (numArr == 1) {
				cout << arr1.capacity();
			}
			if (numArr == 2) {
				cout << arr2.capacity();
			}
			status = 0;
			_getch();
			system("cls");
		}
		if (status == 11) {
			int elem;
			cout << "В конец какого массива поместить элемент?(1/2)" << endl;
			cin >> numArr;
			cout << "Введите элемент." << endl;
			cin >> elem;
			try {
				if (numArr == 1) {
					arr1.pushBack(elem);
				}
				if (numArr == 2) {
					arr2.pushBack(elem);
				}
			}
			catch (EndOfReservException e) {
				std::cerr << "Нет зарезервированного места!" << endl;
			}
			status = 0;
			cout << "Готово!" << endl;
			_getch();
			system("cls");
		}
		if (status == 12) {
			cout << "Из какого массива хотите вытащить элемент?(1/2)" << endl;
			cin >> status;
			numArr;
			try {
				if (numArr == 1) {
					cout << arr1.popBack();
				}
				if (numArr == 2) {
					cout << arr2.popBack();
				}
			}
			catch (EndSizeOfArrayException e) {
				std::cerr << "Нечего извлекать!" << endl;
			}
			status = 0;
			_getch();
			system("cls");
		}
	}
	return 0;
}