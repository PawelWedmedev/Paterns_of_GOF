#include "Header.h"

template <class T>
SortStrategy<T>* SelectSort(vector<T> &v) // стратегия выбора способа сортировки
{
	SortStrategy<T>* strategy;
	if (v.size() % 2 == 0)
		strategy = new InsertSort<T>;
	else
		strategy = new QuickSort<T>;
	strategy->Sort(v);
	return strategy;
}


int main()
{
	vector<int> v;
	vector<string> vs;
	vs.push_back("one");
	vs.push_back("two");
	vs.push_back("three");
	vs.push_back("four");
	vs.push_back("five");
	for (int i = 0; i < 11; i++)
	{
		v.push_back(rand() % 20);
	}
	vector<string>::iterator it;
	for (it = vs.begin(); it < vs.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	SelectSort(vs);
	
	cout << endl;
	for (it = vs.begin(); it < vs.end(); it++)
	{
		cout << *it << " ";
	}
	return 0;
}