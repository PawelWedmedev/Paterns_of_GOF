#pragma once
#include<iostream>
#include<string>
using namespace std;


class BaseSender // ������� �����
{
public:
	virtual void Send_Message (string titel,string body) = 0;
};

class EmailSender: public BaseSender // �������� ��������� �� e-mail
{
public:
	virtual void Send_Message(string titel, string body)
	{
		cout << " Email: " << titel << " text : " << body << endl;
	}
};

class MsmqSender : public BaseSender // �������� ��������� �� Msmq
{
public:
	virtual void Send_Message(string titel, string body)
	{
		cout << " Msmq: " << titel << " text : " << body << endl;
	}
};

class WebServiceSender : public BaseSender // �������� ��������� �� web
{
public:
	virtual void Send_Message(string titel, string body)
	{
		cout << " WebService: " << titel << " text : " << body << endl;
	}
};
//***************************************

class Messege // �������� �������� ��������� ������������� � ��������� �����(������ ��������� � ���� ������)
{
protected:
	BaseSender *_sender; // Dependens ingections. ��� �� ���� � ���� ����, �� �������� (Message) � ������������ ���������� ���������!!
	string _titel;
	string _body;
public:
	Messege(BaseSender *sender, string titel, string body)
	{
		SetSender(sender);
		_titel = titel;
		_body = body;
	}

	void SetSender(BaseSender *sender)// ������������� ������ ��������
	{
		_sender = sender;
	}

	virtual void Send() 
	{
		_sender->Send_Message(_titel, _body); // ����� ���� _sender �������� ������ (������ ���� _sender ����� � ����������� ������ ��������)
	}

};


class SuperMessage :public Messege// ����� ��� ��������� ������� ����� ���� ������(����� ������ 0 ��� 1)
{
protected:
	int _status;
public:
	// ��������� ����������� ������ Messege
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