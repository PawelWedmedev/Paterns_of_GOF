#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<windows.h>
using namespace std;


class Shop// абстрактный наблюдатель
{
public:
	virtual void Notify(int prise) = 0;// параметр - новая измененная цена
};

class RealShop :public Shop// реальный наблюдатель ( магазин )
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
	virtual void Notify(int price)// метод который устанавливает новую цену в магазине и сообщает об этом
	{
		_price = price;
		cout << _name << " recived new prise: " << _price << endl;
	}

};

// все строиться вокруг этого данного класса.Если кому то интиресно следить за этим классом, этот кто то должен
// передать свой объект в коллекцию этого класса(метод Subscriber()).
// Этот класс берет на себя обязательство, что в случае какого то важного события ( в нашем случае это изминение цены)
// каждому кто находиться в моей коллекции я сообщу( перезвоню ).
// Рассылка сообщения происходят в методе  NotifyAll(). Классы получатели расссылок должны также иметь метод который 
// обрабытывает сообщение ( это метод Notify(_prise)), параметр эого метода это то что мы сообщаем всем. 
// В нашем случае это цена.

class Product// тот за кем наблюдают
{
	string _product;		// название товара
	int _price;
	vector <Shop*> _shops;	// вектор содержащий всех подписчиков (все магазины)
							//когда меняеться цена все магазины подписчики узнают об этом автоматически
public:
	Product(string product, int price)
	{
		_product = product;
		_price = price;
	}

	void Subscriber(Shop* shop)// метод добавляющий подписчиков( наблюдателей )
	{
		_shops.push_back(shop);
	 }

	void Unsubscriber(Shop* shop)// метод для отписки от сообщений (параметр - объект магазин, который предаем в алгоритм remove )
	{
	  _shops.erase(remove(_shops.begin(),_shops.end(),shop));
	}

	void ChengePrise(int price)// метод который изменяет цену
	{
		_price = price;
	}

	void NotifyAll()// каждый раз как мы будем менять цену нам нужно перебрать всех подписчиков и сообщить новую цену
					// поэтому метод ChengePrise() и NotifyAll() нужно вызывать один за другим
	{
		vector<Shop*>::iterator it= _shops.begin();
			for(it ;it != _shops.end();it++)
			{
				(*it)->Notify(_price);// вызываем виртуальный метод магазина который устанавливает цену и сообщает об этом
			}
	}

};