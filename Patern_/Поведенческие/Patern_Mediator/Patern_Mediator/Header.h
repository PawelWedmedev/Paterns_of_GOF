#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<windows.h>
using namespace std;

class ABmediator;//  ����������� ����� ������� ����� ������� � ���� ������ ��� ���� ���������� ���������

class ABChater// ����������� ����� - ������� ��� ��� �������
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
	virtual void Send_Message(ABmediator* abm, string msg) = 0;  // ����� �������� ��������� (���� ���������� � ���� ���������)
	virtual void Receive_Message(ABChater* abc, string msg) = 0; // ����� ��������� ���������(����� � ���������)
};

// �������� ����� ����� ����� ��������� � ���������� ��������� ����� ����������� ����!!!
class ABmediator
{
protected:
	vector<ABChater*> _chaters;
public:
	virtual void AddChater(ABChater* abc)// ���������� ������ �������� ����
	{
		_chaters.push_back(abc);
	}

	virtual void TransferMessage(ABChater* abc, string msg) = 0;// ����� ������� ���� ������������� ����� ���������� ��������� (���� ���������� � ���� ���������)
	// ����� ����� �������� ��������� �� ������ �������, �� ��� ������ ��������� ����
};

class Chater : public ABChater // �������� �����
{
public:
	Chater(string name) : ABChater(name) {} // ��������� �����������

	// �������������� ������ �������� � ��������� ���������:

	virtual void Send_Message(ABmediator* abm, string msg)// ������ �������� ��� ��������
	{
		abm->TransferMessage(this,msg);// �� ����� ������� abm �������� ����� TransferMessage(), � � ���� ����� ��������(��� �������� � ���� ���������)
		// ���������� ��� ��� ������, ������� �������� this
	}

	virtual void Receive_Message(ABChater* abc, string msg) // ������ �������� ��� ����� �� �������� ������ ���������
	{
		cout <<this->GetName()<<" receved "<< msg <<" from " << abc->GetName() << endl;
		// ������� ��������� this->GetName() �� ���� �� ���� ������ ���������(abc->GetName())
	}
};


// �������� �������� (������� ���)
//�� ����� ������� ���������  ���������� � ������ �������� ��������� ���������� ������ TransferMessage()
class Mediater : public ABmediator
{
public:
	virtual void TransferMessage(ABChater* abc, string msg)	
	{
	vector<ABChater*>::iterator it = _chaters.begin();
	for (it;it != _chaters.end();it++)
		{
			if ((*it) != abc)// �������� �� �������� ��������� ������ ����
				(*it)->Receive_Message(abc, msg);// ����� � ���������
		}
	}
};


// ����� Receive_Message() ���������� � ������ Chater � �� � ������ Mediator ������ ��� � Chater ���� ��� �����������(this) ����� ��� � ���������� �����
//�������� �� ���� ������ cout ��� ������� ������� ���� � ���������

