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
	void showRect()	//��� �������� ����� ������� ����� ������������ � ����� ������
	{
		cout << _x << " : " << _y << " : " << _w << " : " << _h << " : " << _color << endl;
	}
};

// ***********************************************����� �������
class MyRectangl: public Rectangl, public ColorRectangl
	// �������� �� ColorRectangl �� �������� � ������������ �������� �����
	// � �������� �� ����������� ����� Rectangl � ����������� ������� Show() �� �����  ��������� ��� Show()
{
private:
	
public:
	MyRectangl(int x, int y, int w, int h, string color):ColorRectangl(x,y,w,h,color)
	{}
	virtual void Show()
	{
		cout << "From show method\n";// �������� ���� (��������� ������������ ������)
		showRect();// ...� �������� �������� �����
	}

};

// ************************************************������ �������
class MyRectangl2
{
private:
	int _x, _y, _w, _h;
	string _color;
	ColorRectangl* _cr;// ��������� ���� ������, ����� �������� ����� ������������
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
		_cr->showRect();// �������� ��������  ����� �� ����� �������
	}

};