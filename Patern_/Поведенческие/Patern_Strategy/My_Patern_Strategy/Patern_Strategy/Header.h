#pragma once
#include<iostream>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;

template<class T>
class SortStrategy
{
public:
	virtual void Sort(vector<T> &t) = 0;
};

template<class T>
class QuickSort : public SortStrategy<T>// быстрая сортировка
{
public:
	void Sort(vector<T> &v)
	{
		Quic(v, 0, v.size() - 1);
	}

	void Quic(vector <T> &v, int b, int e)
	{
		int size = v.size();
		int i = b;
		int	j = e;
		T temp, mid;
		mid = v[(b + e) / 2];
		do
		{
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
		} while (i<=j);
		if (b < j)
			Quic(v,b,i);
		if(i<e)
			Quic(v, i, e);
	}
};

template<class T>
class InsertSort : public SortStrategy<T>// сортировка вставками
{
public:
	void Sort(vector<T> &v)
	{
		int size = v.size();
		T x;
		int j;
		for (int i(1);i < size;i++)
		{
			x = v[i];
			for (j = i - 1;j >= 0 && v[j] >x;j--)
			{
				v[j + 1] = v[j];
			}
			v[j + 1] = x;
		}

	}

};

class MyStrategy
{
public:

};