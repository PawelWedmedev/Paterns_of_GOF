#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<windows.h>
using namespace std;

class ABmediator;//  абстрактный класс который будет хранить в себе список тех кому отправляем сообщение

class ABChater// абстрактный класс - базовый тип для чаттера
{
protected:
	string _name;
public:
	ABChater(string name)
	{
		_name = name;
	}
	string GetName()
	{
		return _name;
	}
	virtual void Send_Message(ABmediator* abm, string msg) = 0;  // метод отправки сообщения (кому отправляем и само сообщение)
	virtual void Receive_Message(ABChater* abc, string msg) = 0; // метод получения сообщения(отчет о получении)
};

// Медиатор стоит между всеми чаттерами и пересылает сообщения между участниками чата!!!
class ABmediator
{
protected:
	vector<ABChater*> _chaters;
public:
	virtual void AddChater(ABChater* abc)// добавление нового учасника чата
	{
		_chaters.push_back(abc);
	}

	virtual void TransferMessage(ABChater* abc, string msg) = 0;// метод который всем пользователям будет отправлять сообщения (кому отправляем и само сообщение)
	// когда метод получает сообщение от одного клиента, он его должен разослать всем
};

class Chater : public ABChater // реальный чатер
{
public:
	Chater(string name) : ABChater(name) {} // наследуем конструктор

	// переопределяем методы отправки и получения сообщений:

	virtual void Send_Message(ABmediator* abm, string msg)// первый параметр это медиатор
	{
		abm->TransferMessage(this,msg);// от имени объекта abm вызываем метод TransferMessage(), и в этот метод передаем(кто отправил и само сообщение)
		// отправляет это сам чаттер, поэтому передаем this
	}

	virtual void Receive_Message(ABChater* abc, string msg) // первый параметр это чатер от которого пришло сообщение
	{
		cout <<this->GetName()<<" receved "<< msg <<" from " << abc->GetName() << endl;
		// получил сообщение this->GetName() от того от кого пришло сообщение(abc->GetName())
	}
};


// реальный медиатор (простой чат)
//но можно сделать несколько  медиаторов с разной степенью сложности реализации метода TransferMessage()
class Mediater : public ABmediator
{
public:
	virtual void TransferMessage(ABChater* abc, string msg)	
	{
	vector<ABChater*>::iterator it = _chaters.begin();
	for (it;it != _chaters.end();it++)
		{
			if ((*it) != abc)// проверка на отправку сообщения самому себе
				(*it)->Receive_Message(abc, msg);// отчет о получении
		}
	}
};


// метод Receive_Message() реализован в классе Chater а не в классе Mediator потому что в Chater есть как отправитель(this) чатер так и получатель чатер
//медиатор по сути делает cout тех чатеров которые есть в коллекции

