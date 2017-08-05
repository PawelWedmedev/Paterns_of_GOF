#pragma once
#include<iostream>
#include<ctime>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<fstream>

using namespace std;


class BaseSymbol // ������� �����  
{
protected:
	char _symbol;
	int _position;
	int _size;
	string _color;
public:
	virtual string Display(int size, string color)=0;
	char GetChar()
	{
		return _symbol;
	}
};
class Symbol :public BaseSymbol//
{
public:
	Symbol(char c)// ��������� �������������� �����������
	{
		_symbol = c;
		_position = 0;
		_size = 20;
		_color = 'blue';
	}
	virtual string Display (int size, string color)
	{
		char s[20];
		string str = "<span style ='color:";
		str += color;
		str += ";font-size:";
		itoa(size, s, 10);
		str += s;str += "'>";str += _symbol;str += "</span>";
		return str;
	}
};
// ����� ������� ���� ����� ���� ������� �� �� ���������� ���� ��� �� ������� � ���������
class CharFactory
{
protected:
	map<char, BaseSymbol*> pool;
public:
	BaseSymbol* GetSymbol(char key)
	{
		map<char, BaseSymbol*>::iterator it = pool.find(key);
		if (it == pool.end())
		{
			BaseSymbol *bs = new Symbol(key);// � ��������� �������� ���� ������� ������ ������������ ����
			pool[key] = bs;// ������ bs ������� � pool
			return bs;
		}
		else
		{
			return it->second; 
		}

	}
	int GetPoolSize()//����� ���������� ������ ����(pool)
	{
		return pool.size();
	}

	//void PoolShow()//////
	//{
	//	

	//}
};

