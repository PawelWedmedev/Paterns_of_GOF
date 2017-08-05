#pragma once
#include<iostream>
#include<ctime>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;



class Request// событие (запрос денег) оформленное в виде класса 
// оформив запрос в виде класса мы можем фиксировать ряд параметров важных для этого патерна
//(например степень выполнения запроса, номинал...)
{
	int _requested;			//количество денег которые хочет снять человек
	int _rest;				// колличество сколько осталось к выдаче денег
	map<int, int> _notes;	// номинал и количество выданных банкнот
public:
	Request(int requested)
	{
		_requested = requested;
		_rest = requested;
	}
	void Show()
	{
		cout<<"Wos requested ammont of: "<<_requested << endl;
		cout <<"Transactions have been done:" << endl;
		map<int, int>::iterator it = _notes.begin();
		// было выдано купюр- first, в количестве- second
		for (it;it!= _notes.end();it++) 
		{
			cout << "was given:" << (*it).first << " in amount of:" << (*it).second << endl;
		}
		if (_rest > 0)
		{
			cout <<"Cannot be given:"<<_rest<<endl; 
		}
	}
	int GetRest()
	{
		return _rest;
	}
	map<int,int> GetNotes() // геттер для контейнера мар
	{
		return _notes;
	}

	void SetMap(map<int, int> notes) // сетер для контейнера мар
	{
		_notes = notes;
	}

	void SetRest(int rest)	// для изминения оставшихся к выдаче денег
	{
		_rest -= rest;
	}
};
 

class Handler //класс обработчик
{
protected:
	Handler* _next; // следующий обработчик
public:
	Handler()
	{}
	virtual void SetHandler(Handler* next) // написали метод вместо конструктора т.к конструктор
		// не передаеться при наследовании
	{
		_next = next;
	}
	// метод вызывающий обработчики друг за другом (Request* request)- указатель на объект класса заказ
	virtual void HandlerRequest(Request* request) = 0;
};

// ***************************************************конкретные обработчики
class Handler_500 : public Handler
{
protected:
	int _value;// значение банкноты 
	int _count;// количество банкнот
public:
	Handler_500 (int count)
	{
		_count = count;
		_value = 500;
	}
	virtual void HandlerRequest(Request* request)
	{
		map <int, int> notes1;
		while (request->GetRest()>=_value &&_count>0) // цикл пока есть что выдавать будем выдавать
	 // если остаток больше или равен 500 и если есть банкноты соответствующего номинала 
	 // собственно >= _value и есть условие выполнения этого конкретного обработчика
		{
			//notes1 = request->GetNotes();- непонятная строка(работает и без нее)!!!

			if (notes1.find(_value) == notes1.end()) // ищем есть ли в контейнере купюра 500(_value)
				// если find ее находит, то вернет сам итератор, если нет такой купюры то вернет end()
				// если нет то 500ки еще не выдавались
			{//Функция make_pair создает структуру, содержащую 2 пар элементов данных любого типа. 
				notes1.insert(make_pair(_value, 1));// если не нашли то добавляем в мар ( банкноту 500, в количестве 1)
			}
			else // если 500 выдавались, то мы должны увеличить количество выданных купюр на 1
			{
				notes1[_value]++;
			}
			_count--;
			request->SetRest(_value); // уменьшаем количество оставшихся банкнот(и количество оставшихся к выдаче денег) на номинал
									  // здесь же уменьшаем сумму запроса(при передаче ниже в _next->HandlerRequest(request))
			request->SetMap(notes1);  // из notes1 в notes через сетер
		}
		if (request->GetRest() > 0) // если мы не выполнили запрос полностью и нам еще нужно отдать какие то денги
			
			_next->HandlerRequest(request); // мы унаследовали с базового класса свойство _next
											// от _next вызываем этот же метод и передаем ему 
											// не обработанный до конца запрос (request)
		// в этом классе _next равен объекту h100 класса Handler_100, и от имени объекта h100 вызываем
		// метод HandlerRequest() класса Handler_100 с значением изменившегося заказа (request)
		// PS вот по тому при отладке при завершении всех выдач мы приходим именно сюда!

	}
};

class Handler_100 : public Handler
{
protected:
	int _value;
	int _count;
public:
	Handler_100(int count)
	{
		_count = count;
		_value = 100;
	}
	virtual void HandlerRequest(Request* request)
	{
		map <int, int> notes1;
		while (request->GetRest() >= _value &&_count>0)
		{
			notes1 = request->GetNotes();
			if (notes1.find(_value) == notes1.end())
			{
				notes1.insert(make_pair(_value, 1));
			}
			else
			{
				notes1[_value]++;
			}
			_count--;
			request->SetRest(_value);
			request->SetMap(notes1);
		}
		if (request->GetRest() > 0)
			_next->HandlerRequest(request);

	}
};

class Handler_50 : public Handler
{
protected:
	int _value;
	int _count;
public:
	Handler_50(int count)
	{
		_count = count;
		_value = 50;
	}
	virtual void HandlerRequest(Request* request)
	{
		map <int, int> notes1;
		while (request->GetRest() >= _value &&_count>0)
		{
			notes1 = request->GetNotes();
			if (notes1.find(_value) == notes1.end())
			{
				notes1.insert(make_pair(_value, 1));
			}
			else
			{
				notes1[_value]++;
			}
			_count--;
			request->SetRest(_value);
			request->SetMap(notes1);
		}
		if (request->GetRest() > 0&& _next!=0)
			_next->HandlerRequest(request);


	}
};