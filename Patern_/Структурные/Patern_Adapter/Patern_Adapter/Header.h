#pragma once
# include<iostream>
# include<string>
//#include "Header1.h"
using namespace std;

class Rectangl 
{
public:
	virtual void Show() = 0;
};

class ColorRectangl
{
private:
		int _x, _y, _w, _h;
		string _color;
public:
	ColorRectangl(int x=0, int y=0, int w=0, int h=0, string color="No color")
	{
		_x = x;
		_y = y;
		_w = w;
		_h = h;
		_color = color;
	}
	void showRect()	//наш классный метод который нужно использовать в новом классе
	{
		cout << _x << " : " << _y << " : " << _w << " : " << _h << " : " << _color << endl;
	}
};

// ***********************************************класс адаптер
class MyRectangl: public Rectangl, public ColorRectangl
	// наследу€ от ColorRectangl мы получаем в распор€жение классный метод
	// а наследу€ от абстрактный класс Rectangl с виртуальным методом Show() мы можем  дополн€ть наш Show()
{
private:
	
public:
	MyRectangl(int x, int y, int w, int h, string color):ColorRectangl(x,y,w,h,color)
	{}
	virtual void Show()
	{
		cout << "From show method\n";// добавили свое (благодар€ абстрактному классу)
		showRect();// ...и вызываем классный метод
	}

};

// ************************************************объект адаптер
class MyRectangl2
{
private:
	int _x, _y, _w, _h;
	string _color;
	ColorRectangl* _cr;// объ€вл€ем поле класса, метод которого хотим использовать
public:
	MyRectangl2(int x = 0, int y = 0, int w = 0, int h = 0, string color = "No color")
	{
		_x = x;
		_y = y;
		_w = w;
		_h = h;
		_color = color;
		_cr = new ColorRectangl(x, y, w, h, color);
	}
	virtual void Show()
	{
		cout << "From show2   --------  method\n";
		_cr->showRect();// вызываем классный  метод от имени объекта
	}

};