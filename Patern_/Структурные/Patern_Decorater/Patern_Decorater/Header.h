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

	virtual void CreateFile(string file)// записываем в файл .html
	{
		ofstream out("text.html");
		out << _text;
		out.close();
	}
};

class AbDecorator : public Text// абстрактный декоратор - родоначальник всех конкретных декораторов
{
protected:
	Text *_dtext;// заносим в класс абстрактного декоратора объект типа Text
public:
	AbDecorator(Text * dtext)// в качестве параметра  в конструктор приходит объект класса Text
	{
		_dtext = dtext;// создаем объект вокруг которого будем играться
	}

};

class BoldDecorator :public AbDecorator// жирный шрифт
{
public:
	BoldDecorator(Text * dtext): AbDecorator(dtext)// наследуем конструктор
	{// устанавливаем текст (получаем от getera исходную строку и делаем ее жирным шрифтом) 
		SetText("<b>"+dtext->GetText()+"</b>");// метод SetText определен в Text
	}

	//*************************
	//   если закоменьтить метод Display() в каждом классе то все равно работает
	//   метод вызываеться с класса дедушки (Text)
	//*************************

	// если бы метод Display был не определен в данном классе то он вызывался бы из класса Text
	//virtual void Display()// в каждом классе мы этот метод должны переопределять
	//{
	//	cout <<GetText()<< endl; // метод GetText будет вызван из класса Text
	//}
};
 
class ItalicDecorator :public AbDecorator// наклонный шрифт
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

class BigDecorator :public AbDecorator// большой шрифт
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

