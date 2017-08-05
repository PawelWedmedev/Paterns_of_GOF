#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<windows.h>
using namespace std;

// ���������� ������� ������ ��� ������
// 1. ��������� ������� ������� ��������� ��� ������� �������
// 2. ������� ����� ����� ����� ������������ �� ������� ������� ������� ������� ���������� ����� ������
// 3. ������ ����� ������� ������� �� ������ ��������� ������� ������
// ����� ������� ���������� ���������� ������� - ���  ��������:
// �� ������� ����� ������������ �� �������� ������ ���� ����������� �����, 
// � ���� ������ ������� ����� � �������� �������� ��� ������ �������� ������ � ��� ������� ��� �����(����������� ����������� ��������������)
// � ��� �������� ������ ���� �����(��� � AF- Client)

class Card
{
	int _pin;
	int _ballans;
public:
	Card(int pin, int ballans)
	{
		SetPin(pin);
		SetBallans(ballans);
	}

	void SetBallans(int ballans)
	{
		_ballans = ballans;
	}
	void SetPin(int pin)
	{
		_pin = pin;
	}
	int GetBallans()
	{
		return _ballans;
	}

	int GetPin()
	{
		return _pin;
	}

	void Show()
	{
		cout << "Card:" << _pin << " curent balanse:" << _ballans << endl;
	}
};

class Bank
{
	vector<Card*> cards;// ������ ��������
public:
	void AddCard(Card *c)// ��������� �������� � ����
	{
		if (c->GetBallans() > 0)
			cards.push_back(c);
	}

	void Show()// ����� �� ����� ���� �������� �����
	{
		for_each(cards.begin(), cards.end(), [](Card* c) {c->Show();});
	}

	Card* CheckCard(Card* c)// ����� �������� �������������� �������� � ���������
	{
		vector<Card*>::iterator it =find(cards.begin(), cards.end(), c);
		if (it != cards.end())// ���� �������� �� ����� cards.end �� �� ��������� �� ��������� ��������
			return (*it);// ���������� ���� ��������
		else return NULL;
	}
};

class ATM// ����� �������� (������� ������� ������� ����� �����������(Wraper) � �������� 3 ������ ������� � ��� ���������)
{
	Bank* _bank;
	int _money;
public:
	ATM (){}
	ATM(Bank* bank)
	{
		_bank = bank;
	}
	int InsertCard (Card* card)  // ������ ����� �������
	{
		Card *c=_bank->CheckCard(card); // ��������� ��������( � ���������� �������� Card *c= )
		if (c == NULL) // ���� �������� �� ������� (�� ����������� ����� �����)
		{
			cout << "The card doesnt not belong to the bank" << endl;
			return -2;
		}
		// ����� �������� �������� ������ ������
		int pin;
		cout << "Enter pin code: ";
		cin >> pin;
		if (card->GetPin() != pin)
		{
			cout << "Wrong pin code!" << endl;
			return (-1);
		}
		return 0;
	}

	int RequestBallans(Card* c)// ����� �������� ��������
	{
		int money;
		cout << "Enter money: ";
		cin >> money;
		if (c->GetBallans()< money)
		{
			cout << "Not manney" << endl;
			return (-1);
		}
		_money = money;
		return 0;
	}

	void GetMoney(Card* c)// ����� ������ ������
	{
		c->SetBallans(c->GetBallans() - _money);
		cout <<"Get money and card\n";
	}

};
// ���������� ��� ����� ��������
class ATMFacade :public ATM
{
public:
	ATMFacade(Bank* bank): ATM(bank)// ��������� ����������� ������������ ������
	{}
	void ClientAction(Card* card)
	{
		
		int res = InsertCard(card);	// ��������� ���� �������� � ��������� �� ��� � �� �������������� ����� (���� ��� �� �� ����� ���������� 0)
		if (res == 0)
		{
			res = RequestBallans(card); // ��������� ������� ������� �� ����� (��� ������� ������� ����� ���������� 0)
			if (res == 0) // ���� ��� �� � �������� ����...
				GetMoney(card); // ...������ ������
		}
		card->Show();
	}
};