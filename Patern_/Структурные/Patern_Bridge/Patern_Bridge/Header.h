#pragma once
#include<iostream>
#include<string>
using namespace std;


class BaseSender // базовый класс
{
public:
	virtual void Send_Message (string titel,string body) = 0;
};

class EmailSender: public BaseSender // отправка сообщения по e-mail
{
public:
	virtual void Send_Message(string titel, string body)
	{
		cout << " Email: " << titel << " text : " << body << endl;
	}
};

class MsmqSender : public BaseSender // отправка сообщения по Msmq
{
public:
	virtual void Send_Message(string titel, string body)
	{
		cout << " Msmq: " << titel << " text : " << body << endl;
	}
};

class WebServiceSender : public BaseSender // отправка сообщения по web
{
public:
	virtual void Send_Message(string titel, string body)
	{
		cout << " WebService: " << titel << " text : " << body << endl;
	}
};
//***************************************

class Messege // действие отправки сообщения инкапсулируем в отдельный класс(запрос оформляем в виде класса)
{
protected:
	BaseSender *_sender; // Dependens ingections. Это по сути и есть мост, от действия (Message) к абстрактному отправщику сообщений!!
	string _titel;
	string _body;
public:
	Messege(BaseSender *sender, string titel, string body)
	{
		SetSender(sender);
		_titel = titel;
		_body = body;
	}

	void SetSender(BaseSender *sender)// устанавливаем службу отправки
	{
		_sender = sender;
	}

	virtual void Send() 
	{
		_sender->Send_Message(_titel, _body); // через поле _sender вызываем методы (какого типа _sender такая и срабатывает служба доставки)
	}

};


class SuperMessage :public Messege// новый вид сообщения которое может быть важным(имеет статус 0 или 1)
{
protected:
	int _status;
public:
	// наследуем конструктор класса Messege
	SuperMessage(BaseSender *sender, string titel, string body, int status): Messege (sender, titel, body)
	{
		_status = status;
	}

	virtual void Send()
	{
		cout << "Importance :" << _status << endl;
		_sender->Send_Message(_titel, _body);
	}

};