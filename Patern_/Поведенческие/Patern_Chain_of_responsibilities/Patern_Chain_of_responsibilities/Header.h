#pragma once
#include<iostream>
#include<ctime>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;



class Request// ������� (������ �����) ����������� � ���� ������ 
// ������� ������ � ���� ������ �� ����� ����������� ��� ���������� ������ ��� ����� �������
//(�������� ������� ���������� �������, �������...)
{
	int _requested;			//���������� ����� ������� ����� ����� �������
	int _rest;				// ����������� ������� �������� � ������ �����
	map<int, int> _notes;	// ������� � ���������� �������� �������
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
		// ���� ������ �����- first, � ����������- second
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
	map<int,int> GetNotes() // ������ ��� ���������� ���
	{
		return _notes;
	}

	void SetMap(map<int, int> notes) // ����� ��� ���������� ���
	{
		_notes = notes;
	}

	void SetRest(int rest)	// ��� ��������� ���������� � ������ �����
	{
		_rest -= rest;
	}
};
 

class Handler //����� ����������
{
protected:
	Handler* _next; // ��������� ����������
public:
	Handler()
	{}
	virtual void SetHandler(Handler* next) // �������� ����� ������ ������������ �.� �����������
		// �� ����������� ��� ������������
	{
		_next = next;
	}
	// ����� ���������� ����������� ���� �� ������ (Request* request)- ��������� �� ������ ������ �����
	virtual void HandlerRequest(Request* request) = 0;
};

// ***************************************************���������� �����������
class Handler_500 : public Handler
{
protected:
	int _value;// �������� �������� 
	int _count;// ���������� �������
public:
	Handler_500 (int count)
	{
		_count = count;
		_value = 500;
	}
	virtual void HandlerRequest(Request* request)
	{
		map <int, int> notes1;
		while (request->GetRest()>=_value &&_count>0) // ���� ���� ���� ��� �������� ����� ��������
	 // ���� ������� ������ ��� ����� 500 � ���� ���� �������� ���������������� �������� 
	 // ���������� >= _value � ���� ������� ���������� ����� ����������� �����������
		{
			//notes1 = request->GetNotes();- ���������� ������(�������� � ��� ���)!!!

			if (notes1.find(_value) == notes1.end()) // ���� ���� �� � ���������� ������ 500(_value)
				// ���� find �� �������, �� ������ ��� ��������, ���� ��� ����� ������ �� ������ end()
				// ���� ��� �� 500�� ��� �� ����������
			{//������� make_pair ������� ���������, ���������� 2 ��� ��������� ������ ������ ����. 
				notes1.insert(make_pair(_value, 1));// ���� �� ����� �� ��������� � ��� ( �������� 500, � ���������� 1)
			}
			else // ���� 500 ����������, �� �� ������ ��������� ���������� �������� ����� �� 1
			{
				notes1[_value]++;
			}
			_count--;
			request->SetRest(_value); // ��������� ���������� ���������� �������(� ���������� ���������� � ������ �����) �� �������
									  // ����� �� ��������� ����� �������(��� �������� ���� � _next->HandlerRequest(request))
			request->SetMap(notes1);  // �� notes1 � notes ����� �����
		}
		if (request->GetRest() > 0) // ���� �� �� ��������� ������ ��������� � ��� ��� ����� ������ ����� �� �����
			
			_next->HandlerRequest(request); // �� ������������ � �������� ������ �������� _next
											// �� _next �������� ���� �� ����� � �������� ��� 
											// �� ������������ �� ����� ������ (request)
		// � ���� ������ _next ����� ������� h100 ������ Handler_100, � �� ����� ������� h100 ��������
		// ����� HandlerRequest() ������ Handler_100 � ��������� ������������� ������ (request)
		// PS ��� �� ���� ��� ������� ��� ���������� ���� ����� �� �������� ������ ����!

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