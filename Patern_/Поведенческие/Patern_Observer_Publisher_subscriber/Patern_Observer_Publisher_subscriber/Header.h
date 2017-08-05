#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<windows.h>
using namespace std;


class Shop// ����������� �����������
{
public:
	virtual void Notify(int prise) = 0;// �������� - ����� ���������� ����
};

class RealShop :public Shop// �������� ����������� ( ������� )
{
protected:
	string _name;
	int _price;
public:
	RealShop(string name)
	{
		_name =name;
		_price = 0;
	}
	virtual void Notify(int price)// ����� ������� ������������� ����� ���� � �������� � �������� �� ����
	{
		_price = price;
		cout << _name << " recived new prise: " << _price << endl;
	}

};

// ��� ��������� ������ ����� ������� ������.���� ���� �� ��������� ������� �� ���� �������, ���� ��� �� ������
// �������� ���� ������ � ��������� ����� ������(����� Subscriber()).
// ���� ����� ����� �� ���� �������������, ��� � ������ ������ �� ������� ������� ( � ����� ������ ��� ��������� ����)
// ������� ��� ���������� � ���� ��������� � ������( ��������� ).
// �������� ��������� ���������� � ������  NotifyAll(). ������ ���������� ��������� ������ ����� ����� ����� ������� 
// ������������ ��������� ( ��� ����� Notify(_prise)), �������� ���� ������ ��� �� ��� �� �������� ����. 
// � ����� ������ ��� ����.

class Product// ��� �� ��� ���������
{
	string _product;		// �������� ������
	int _price;
	vector <Shop*> _shops;	// ������ ���������� ���� ����������� (��� ��������)
							//����� ��������� ���� ��� �������� ���������� ������ �� ���� �������������
public:
	Product(string product, int price)
	{
		_product = product;
		_price = price;
	}

	void Subscriber(Shop* shop)// ����� ����������� �����������( ������������ )
	{
		_shops.push_back(shop);
	 }

	void Unsubscriber(Shop* shop)// ����� ��� ������� �� ��������� (�������� - ������ �������, ������� ������� � �������� remove )
	{
	  _shops.erase(remove(_shops.begin(),_shops.end(),shop));
	}

	void ChengePrise(int price)// ����� ������� �������� ����
	{
		_price = price;
	}

	void NotifyAll()// ������ ��� ��� �� ����� ������ ���� ��� ����� ��������� ���� ����������� � �������� ����� ����
					// ������� ����� ChengePrise() � NotifyAll() ����� �������� ���� �� ������
	{
		vector<Shop*>::iterator it= _shops.begin();
			for(it ;it != _shops.end();it++)
			{
				(*it)->Notify(_price);// �������� ����������� ����� �������� ������� ������������� ���� � �������� �� ����
			}
	}

};