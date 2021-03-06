// TreeProgram.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Tree.h"
using namespace std;
int main()
{
	Tree *treeOne = new Tree();
	treeOne->pasteElem(1, {});
	treeOne->pasteElem(2, {0});
	treeOne->pasteElem(3, {1});
	treeOne->pasteElem(4, { 0,1 });
	treeOne->pasteElem(8, { 0, 0 });
	treeOne->pasteElem(5, {1,0});
	cout << *treeOne << endl;
	cout << "________________________________________" << endl;
	cout<<"Count even: "<<treeOne->countEven()<<endl;
	cout<<"Positive elem: "<<treeOne->positiveElem()<<endl;
	cout<<"Middle arifmetic: "<<treeOne->middle() << endl;
	vector<int> vec = treeOne->findElem(5);
	cout << "Vector way: ";
	for (unsigned int i = 0; i < vec.size(); i++) {
		cout <<vec[i] <<" ";
	}
	cout << endl;
	Tree *treeTwo = new Tree(*treeOne);//cоздание копии
	treeOne->delLeaves();
	cout << "________________________________________" << endl;
	cout << "delete leaves" << endl;
	cout << *treeOne << endl;
	cout << "________________________________________" << endl;
	cout << *treeTwo<<endl;//вывод копии
	delete treeOne;
	delete treeTwo;
	system("pause");
    return 0;
}

