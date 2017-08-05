#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>
using namespace std;

class Text
{
protected:
	string _text;
public:
	void SetText(string text)
	{
		_text = text;
	}

	string GetText()
	{
		return _text;
	}

	virtual void Display()
	{
		cout << _text << endl;
	}

	virtual void CreateFile(string file)// ���������� � ���� .html
	{
		ofstream out("text.html");
		out << _text;
		out.close();
	}
};

class AbDecorator : public Text// ����������� ��������� - ������������� ���� ���������� �����������
{
protected:
	Text *_dtext;// ������� � ����� ������������ ���������� ������ ���� Text
public:
	AbDecorator(Text * dtext)// � �������� ���������  � ����������� �������� ������ ������ Text
	{
		_dtext = dtext;// ������� ������ ������ �������� ����� ��������
	}

};

class BoldDecorator :public AbDecorator// ������ �����
{
public:
	BoldDecorator(Text * dtext): AbDecorator(dtext)// ��������� �����������
	{// ������������� ����� (�������� �� getera �������� ������ � ������ �� ������ �������) 
		SetText("<b>"+dtext->GetText()+"</b>");// ����� SetText ��������� � Text
	}

	//*************************
	//   ���� ������������ ����� Display() � ������ ������ �� ��� ����� ��������
	//   ����� ����������� � ������ ������� (Text)
	//*************************

	// ���� �� ����� Display ��� �� ��������� � ������ ������ �� �� ��������� �� �� ������ Text
	//virtual void Display()// � ������ ������ �� ���� ����� ������ ��������������
	//{
	//	cout <<GetText()<< endl; // ����� GetText ����� ������ �� ������ Text
	//}
};
 
class ItalicDecorator :public AbDecorator// ��������� �����
{
public:
	ItalicDecorator(Text * dtext) :AbDecorator(dtext)
	{
		SetText("<i>" + dtext->GetText() + "</i>");
	}

	/*virtual void Display()
	{
		cout << GetText() << endl;
	}*/
};

class BigDecorator :public AbDecorator// ������� �����
{
public:
	BigDecorator(Text * dtext) :AbDecorator(dtext)
	{
		SetText("<big>" + dtext->GetText() + "</big>");
	}

	/*virtual void Display()
	{
		cout << this->GetText() << endl;
	}*/
};

