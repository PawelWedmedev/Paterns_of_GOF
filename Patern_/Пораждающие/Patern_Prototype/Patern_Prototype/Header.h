#pragma once
#include<iostream>
using namespace std;

class Prototype// в абстрактном классе все методы должны быть virtual!!!!
{
protected:
	int _x, _y;
public:
	/*Prototype(int x=0,int y=0)
	{
		SetX(x);
		SetY(y);
	}*/
	virtual Prototype* clone() = 0;
	virtual void SetX(int x)
	{
		_x = x;
	}
	virtual void SetY(int y)
	{
		_y = y;
	}
	int GetX()
	{
		return _x;
	}
	int GetY()
	{
		return _y;
	}
	virtual void Show()
	{
		cout << "(" << _x << ":" << _y << ")\n";
	}
};

class Rect :public Prototype
{
protected:
	int _wight, _height;
public:
	/*Rect(int wight = 0, int height = 0)
	{
		_wight = wight;
		_height = height;
	}*/
	void SetX(int wight)
	{
		_wight = wight;
	}
	void SetY(int height)
	{
		_height = height;
	}
	int GetW()
	{
		return _wight;
	}
	int GetH()
	{
		return _height;
	}
	 void Show()
	{
		 //cout << "(" << _x << ":" << _y << ") & ";
		cout << "(" << _wight << ":" << _height << ")\n";
	}
	 Prototype* clone()// метод возвращает новый объект созданный с помощью конструктора копировани€
	 {
		 return new Rect(*this);
	 }
};

class Circl : public Prototype
{
protected:
	int _radius;
public:
	/*Circl(int radius=0)
	{
		_radius = radius;
	}*/
	void SetX(int radius)
	{
		_radius = radius;
	}
	
	int GetR()
	{
		return _radius;
	}
	
	void Show()
	{
		//cout << "(" << _x << ":" << _y << ") & ";
		cout << "(" << _radius << ")\n";
	}

	Prototype* clone()
	{
		return new Circl(*this);
	}
};

class Client // класс позвол€ет получать копии фигур
{
	static Prototype* fig1;// пол€ми класса €вл€ютьс€ указатели абстрактного класса (статические пол€)
	static Prototype* fig2;

public:

	static void Init()
	{
		fig1 = new Rect(); // заносим в указатели объекты 
		fig2 = new Circl();
	}
	static Prototype* GetRect()
	{
		return fig1->clone(); // вызываем метод clone() дл€ соответствующего объекта
	}
	static Prototype* GetCircl()
	{
		return fig2->clone();
	}
};

Prototype* Client::fig1 = NULL;// инициализируем указатели класса Client
Prototype* Client::fig2 = NULL;