#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>

using namespace std;

template <class T>
class SortStrategy // базовый класс
{
public:
	virtual void Sort(vector<T> &t) = 0;
};

template <class T>
class QuickSort : public SortStrategy<T>
{
public:
	virtual void Sort(vector<T> &v)
	{
		Quick(v, 0, v.size() - 1);
	}
	void Quick(vector<T> &v, int b, int e) // b - begin, e - end
	{
		int size = v.size();
		int i = b, j = e;
		T temp, mid;
		mid = v[(b + e) / 2];
		do {
			while (v[i] < mid)i++;
			while (v[j] > mid)j--;
			if (i <= j)
			{
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;
				i++;
				j--;
			}
		} while (i <= j);
		if (b < j)
			Quick(v, b, i);
		if (i < e)
			Quick(v, i, e);
	}
};

template <class T>
class InsertSort : public SortStrategy<T>
{
public:
	virtual void Sort(vector<T> &v)
	{
		int size = v.size();
		T x;
		int i, j;
		for (i = 1; i < size; i++)
		{
			x = v[i];
			for (j = i - 1; j >= 0 && v[j] > x; j--)
			{
				v[j + 1] = v[j];
			}
			v[j + 1] = x;
		}
	}
};

class MyStrategy
{

};